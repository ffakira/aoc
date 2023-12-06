#include "main.hpp"

int main() {
    int selectedOption = terminal::display_screen();

    switch(selectedOption) {
        case 0:
            terminal::display_screen(day1::part_one, day1::part_two);
            break;
        case 1:
            terminal::display_screen(day2::part_one, day2::part_two);
            break;
    }

    return 0;
}
