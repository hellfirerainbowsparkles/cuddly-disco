#include <ncurses.h>
#include <functional>

class KeyBinding {
    public: std::function<void()> function;
    char key = ' ';
};

class KeyBindings {

    public: std::function<void()> moveUp;
    public: std::function<void()> moveDown;
    public: std::function<void()> moveLeft;
    public: std::function<void()> moveRight;
    public: std::vector<KeyBinding> actions;

    public: void setMovement(
        std::function<void()> up,
                     std::function<void()> down,
                     std::function<void()> left,
                     std::function<void()> right)
    {
        moveUp    = up;
        moveDown  = down;
        moveLeft  = left;
        moveRight = right;
    }


    public: KeyBindings() {

    }

    public: void checkBindings(int key) {
        keypad(stdscr, TRUE);
        if (key == KEY_UP)
        {
            moveUp();
        } else if (key == KEY_DOWN) {
            moveDown();
        } else if (key == KEY_LEFT) {
            moveLeft();
        } else if (key == KEY_RIGHT) {
            moveRight();
        }
/*
        switch (key)
        {
            case KEY_UP || ' ':
                moveUp();
                break;

            case KEY_DOWN:
                moveDown();
                break;

            case KEY_LEFT:
                moveLeft();
                break;

            case KEY_RIGHT:
                moveRight();
                break;
        }
        */
    }

};

