#pragma once
#include <iostream>

namespace terminal {
    int display_screen();

    template <typename T>
    void display_screen(T part_one, T part_two);
}
