#include "day1.hpp"

namespace day1 {
    std::filesystem::path CURRENT_DIR = std::filesystem::current_path();
    std::string FILE_PATH = (CURRENT_DIR / "files/day1.txt").string();
    // std::string FILE_PATH = (CURRENT_DIR / "src/day1/sample2.txt").string();

    int part_one() {
        std::vector<int> accSum;
        std::cout << "Day 1 (Part 1) - Advent of Code 2023\n";
        std::ifstream file(FILE_PATH);

        if (!file.is_open()) {
            std::cerr << "Error opening file: " << FILE_PATH << "\n";
            return 1;
        }

        std::string line;
        int result;

        while(std::getline(file, line)) {
            std::vector<char> tempChars;
            std::copy_if(line.begin(), line.end(), std::back_inserter(tempChars), [](char ch) {
                return std::isdigit(ch);
            });

            if (!tempChars.empty()) {
                char digit[2] = {tempChars.front(), tempChars.back()};
                result = std::atoi(digit);
                accSum.push_back(result);
            }
        }

        int sum = std::accumulate(accSum.begin(), accSum.end(), 0);
        std::cout << "Answer: " << sum << "\n";

        file.close();
        return 0;
    }

    std::string convert_to_digits(const std::string &input, const std::unordered_map<std::string, int> &tokenNumbers) {
        std::string result = "";
        std::string temp = "";

        for (size_t i = 0; i < input.size(); ++i) {
            if (std::isdigit(input[i])) {
                temp += input[i];
            } else {
                for (const auto& entry : tokenNumbers) {
                    const std::string &token = entry.first;
                    if (input.compare(i, token.length(), token) == 0) {
                        temp += std::to_string(entry.second);
                        i += token.length() - 1;
                        break;
                    }
                }
            }
        }

        return temp;
    }

    int part_two() {
        std::vector<int> accSum;
        std::cout << "Day 1 (Part 2) - Advent of Code 2023\n";
        std::ifstream file(FILE_PATH);
        std::unordered_map<std::string, int> tokenNumbers = {
            {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
            {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
        };

        if (!file.is_open()) {
            std::cerr << "Error opening file: " << FILE_PATH << "\n";
            return 1;
        }

        std::string line;
        int result;

        while (std::getline(file, line)) {
            std::string result = convert_to_digits(line, tokenNumbers);
            std::string tempResult = std::string(1, result[0]) + result[result.size() - 1];
            accSum.push_back(std::stoi(tempResult));
        }

        int sum = std::accumulate(accSum.begin(), accSum.end(), 0);
        std::cout << "Answer: " << sum << "\n";

        file.close();

        return 0;
    }
}
