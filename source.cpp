#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::string getCmdOption(char ** begin, char ** end, const std::string & option)
{
    char ** itr = std::find(begin, end, option);
    if (itr != end && ++itr != end)
    {
        return std::string(*itr);
    }
    return "";
}

int main(int argc, char* argv[]) {
    std::vector<std::string> args(argv, argv + argc);
    std::string input = getCmdOption(argv, argv + argc, "--string");
    std::string delimiter = getCmdOption(argv, argv + argc, "--delimiter");

    if (delimiter.empty()) {
        delimiter = " "; // default delimiter is space
    }

    if (!input.empty()) {
        for (size_t i = 0; i < input.size(); ++i) {
            std::cout << static_cast<int>(input[i]);
            if (i != input.size() - 1) {
                std::cout << delimiter;
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "No input string was given." << std::endl;
    }

    return 0;
}