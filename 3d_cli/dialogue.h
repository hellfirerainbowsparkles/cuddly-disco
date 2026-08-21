#include <fstream>
#include <string>
#include <vector>
#include <map>

using json = nlohmann::json;


// ------------------------------------------------------------
// DIALOG DEFINITION
// ------------------------------------------------------------

struct DialogChoice
{
    std::string text;
    int value = 0;
};


struct Dialog
{
    std::string id;
    std::string title;

    std::vector<DialogChoice> choices;

    int selected = 0;
};


// ------------------------------------------------------------
// SAVE DIALOG STATES
// ------------------------------------------------------------

bool saveDialogs(
    const std::map<std::string, Dialog>& dialogs,
    const std::string& filename)
{
    json j;

    for (const auto& pair : dialogs)
    {
        const Dialog& dialog = pair.second;

        j[dialog.id] =
        {
            {"selected", dialog.selected}
        };

        if (
            dialog.selected >= 0 &&
            dialog.selected <
                static_cast<int>(dialog.choices.size())
        )
        {
            j[dialog.id]["value"] =
                dialog.choices[dialog.selected].value;

            j[dialog.id]["text"] =
                dialog.choices[dialog.selected].text;
        }
    }

    std::ofstream file(filename);

    if (!file.is_open())
        return false;

    file << j.dump(4);

    return true;
}


// ------------------------------------------------------------
// LOAD DIALOG STATES
// ------------------------------------------------------------

bool loadDialogs(
    std::map<std::string, Dialog>& dialogs,
    const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
        return false;

    try
    {
        json j;
        file >> j;

        for (auto& pair : dialogs)
        {
            Dialog& dialog = pair.second;

            if (!j.contains(dialog.id))
                continue;

            int selected =
                j[dialog.id].value(
                    "selected",
                    dialog.selected
                );

            if (
                selected >= 0 &&
                selected <
                    static_cast<int>(dialog.choices.size())
            )
            {
                dialog.selected = selected;
            }
        }

        return true;
    }
    catch (const json::exception& e)
    {
        return false;
    }
}


// ------------------------------------------------------------
// DRAW DIALOG
// ------------------------------------------------------------

void drawDialog(
    WINDOW* win,
    const Dialog& dialog,
    int cursor)
{
    werase(win);

    box(win, 0, 0);

    int height;
    int width;

    getmaxyx(
        win,
        height,
        width
    );

    // Title
    int titleX =
        (width -
         static_cast<int>(dialog.title.size()))
        / 2;

    if (titleX < 1)
        titleX = 1;

    mvwprintw(
        win,
        1,
        titleX,
        "%s",
        dialog.title.c_str()
    );


    // Choices
    for (
        int i = 0;
        i < static_cast<int>(dialog.choices.size());
        ++i
    )
    {
        int y = i + 3;

        if (y >= height - 2)
            break;

        if (i == cursor)
        {
            wattron(
                win,
                A_REVERSE
            );
        }

        mvwprintw(
            win,
            y,
            3,
            "%s",
            dialog.choices[i].text.c_str()
        );

        if (i == cursor)
        {
            wattroff(
                win,
                A_REVERSE
            );
        }
    }


    mvwprintw(
        win,
        height - 2,
        2,
        "UP/DOWN: move   ENTER: select   ESC: cancel"
    );

    wrefresh(win);
}


// ------------------------------------------------------------
// SHOW DIALOG
//
// returns:
//     selected value
//
// or:
//     -1 if cancelled
// ------------------------------------------------------------

int showDialog(
    Dialog& dialog)
{
    if (dialog.choices.empty())
        return -1;

    int width = 50;

    int height =
        static_cast<int>(dialog.choices.size()) + 6;

    if (height > LINES - 2)
        height = LINES - 2;

    if (width > COLS - 2)
        width = COLS - 2;

    int startY =
        (LINES - height) / 2;

    int startX =
        (COLS - width) / 2;


    WINDOW* win =
        newwin(
            height,
            width,
            startY,
            startX
        );

    keypad(
        win,
        TRUE
    );


    int cursor =
        dialog.selected;

    if (
        cursor < 0 ||
        cursor >= static_cast<int>(dialog.choices.size())
    )
    {
        cursor = 0;
    }


    while (true)
    {
        drawDialog(
            win,
            dialog,
            cursor
        );

        int key =
            wgetch(win);


        switch (key)
        {
            case KEY_UP:
            {
                --cursor;

                if (cursor < 0)
                {
                    cursor =
                        static_cast<int>(
                            dialog.choices.size()
                        ) - 1;
                }

                break;
            }


            case KEY_DOWN:
            {
                ++cursor;

                if (
                    cursor >=
                    static_cast<int>(
                        dialog.choices.size()
                    )
                )
                {
                    cursor = 0;
                }

                break;
            }


            case 10:       // ENTER
            case KEY_ENTER:
            {
                dialog.selected =
                    cursor;

                int value =
                    dialog.choices[cursor].value;

                delwin(win);

                touchwin(stdscr);
                refresh();

                return value;
            }


            case 27:       // ESC
            {
                delwin(win);

                touchwin(stdscr);
                refresh();

                return -1;
            }
        }
    }
}
