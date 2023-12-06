#include "terminal.hpp"
#include <ncurses.h>

namespace terminal {
    int display_screen() {
        initscr();
        keypad(stdscr, TRUE);
        curs_set(0);

        int input;
        int selectedOption = 0;

        while(true) {
            clear();
            printw("Select the day [1-4]:\n");

            for (int i = 0; i < 5; i++) {
                if (i == selectedOption) {
                    attron(A_UNDERLINE);

                    std::string formatDay = "Day %d";
                    printw(formatDay.c_str(), i + 1);

                    attroff(A_UNDERLINE);
                    printw("\n");
                } else {
                    printw("Day %d\n", i + 1);
                }
            }

            move(selectedOption + 1, 0);
            refresh();

            input = getch();

            switch (input) {
                case KEY_UP:
                    selectedOption = std::max(0, selectedOption - 1);
                    break;
                case KEY_DOWN:
                    selectedOption = std::min(4, selectedOption + 1);
                    break;
                case 10:
                case 27:
                    break;
                default:
                    continue;
            }

            if (input == 10 || input == 27) {
                break;
            }
        }

        curs_set(1);
        endwin();

        return selectedOption;
    }

    template <typename T>
    void display_screen(T part_one, T part_two) {
        initscr();
        keypad(stdscr, TRUE);
        curs_set(0);

        int input;
        int selectedOption = 0;

        while(true) {
            clear();
            printw("Select part [1-2]:\n");

            for (int i = 0; i < 2; i++) {
                if (i == selectedOption) {
                    attron(A_UNDERLINE);

                    std::string formatPart = "Part %d";
                    printw(formatPart.c_str(), i + 1);

                    attroff(A_UNDERLINE);
                    printw("\n");
                } else {
                    printw("Part %d\n", i + 1);
                }
            }

            move(selectedOption + 1, 0);
            refresh();

            input = getch();

            switch (input) {
                case KEY_UP:
                    selectedOption = std::max(0, selectedOption - 1);
                    break;
                case KEY_DOWN:
                    selectedOption = std::min(1, selectedOption + 1);
                    break;
                case 10:
                case 27:
                    break;
                default:
                    continue;
            }

            if (input == 10 || input == 27) {
                break;
            }
        }

        curs_set(1);
        endwin();

        if (selectedOption == 0) part_one();
        if (selectedOption == 1) part_two();
    }

    template void display_screen<int (*)()>(int (*)(), int (*)());
}
