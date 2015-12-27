#include <iostream>
#include <fstream>
#include <ncurses.h>

#include "Chooser.h"

int main(int argc, char **argv) {

    // init random seed generator
    srand((unsigned int) time(NULL));

    // init screen
    initscr();
    clear();

    // init chooser
    Chooser c = Chooser();

    // In case a filename is passed with a list
    if (argc == 2) {
        std::string line;
        std::ifstream myfile (argv[1]);

        if (myfile.is_open()) {
            while (getline (myfile, line))
                c.addItem(line);

        } else {
            printw("Unable to open file!! press any key to continue\n");
            refresh();

            getch();
        }
    }

    // main loop
    while (1) {
        clear();

        // Print the item list
        if (c.getItem_list().size() != 0) {
            printw(c.listAsString().c_str());

            printw("\n\n");
        }

        // takes a comand
        printw("Enter a item: ");
        refresh();

        char item[20];
        getstr(item);

        if (!strcmp(item, "quit") || !strcmp(item, "q") || !strcmp(item, "Q")) {
            break;

        } else if (!strcmp(item, "random") || !strcmp(item, "rand") || !strcmp(item, "r")) {
            clear();

            printw("\nSelected Item: %s\n", c.randomItem().c_str());
            refresh();

            getch();
            break;

        } else if (!strcmp(item, "file")){
            std::string line;

            printw("Enter file name: ");
            refresh();

            char f_name[20];
            getstr(f_name);

            std::ifstream myfile (f_name);
            if (myfile.is_open()) {
                while (getline (myfile, line))
                    c.addItem(line);

            } else {
                printw("Unable to open file!! press any key to continue\n");
                refresh();

                getch();
            }

        } else {
            c.addItem(item);
        }
    }

    endwin();
    return 0;
}