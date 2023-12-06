#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>

namespace day1 {
    int part_one();
    int part_two();
    std::string convert_to_digits(const std::string &input, const std::unordered_map<std::string, int> &tokenNumbers);
}
