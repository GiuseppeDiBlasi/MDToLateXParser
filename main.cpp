//
// Created by Giuse on 10/08/2025.
//

#include <iostream>
#include <ostream>

#include "library.h"
#include "TextParsing/LatexTagConstants.h"

int main() {
    std::vector<std::string> buffer {};

    try {
        loadBufferFromFile(buffer, "../examples/Clipping Armi.md");
    }catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    printBuffer(buffer);

    std::cout << BOLD_TEXT_TAG << std::endl;
}
