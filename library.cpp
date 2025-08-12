#include "library.h"

#include <fstream>
#include <iostream>
#include <vector>

#include "exceptionConstants.h"

void loadBufferFromFile(std::vector<std::string>& buffer, const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::invalid_argument(excTxt::FILE_NOT_FOUND);


    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line))
            buffer.push_back(line += '\n');
    }
}

void printBuffer(const std::vector<std::string>& buffer) {
    if (buffer.empty())
        return;

    for (const auto & s : buffer) {
        std::cout << s << std::endl;
    }

}

void hello() {
    std::vector<std::string> buffer{};

    loadBufferFromFile(buffer, "examples/Clipping Armi.md");

    std::cout << "Hello, World!" << std::endl;
}

