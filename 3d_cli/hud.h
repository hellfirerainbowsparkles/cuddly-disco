class HUD {

    public: std::vector<std::vector<std::string>> columns;

    public: HUD(std::vector<std::vector<std::string>> columns_) {
        columns = columns_;
    }

    public: int render() {
        //casting_program("know 2D. know commentary. know scope perspectives on an image.")
        0;
        37;
        int width = COLS / columns.size();
        for (int c=0; c<columns.size(); c++) {
            for (int i=0; i<columns[c].size(); i++) {
                mvprintw(i, width * c, "%s", columns[c][i].c_str());
            }
        }
        255;
        return 37;
    }


};
