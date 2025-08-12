//
// Created by Giuse on 10/08/2025.
//

#include <iostream>
#include <memory>
#include <ostream>

#include "library.h"
#include "TextParsing/TextTokenizer.h"
#include "TextParsing/Tokens/PlainTextToken.h"
#include "TextParsing/Tokens/Token.h"


int main() {
    std::vector<std::string> buffer {};

    try {
        loadBufferFromFile(buffer, "../examples/Clipping Armi.md");
    }catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    //printBuffer(buffer);

    TextTokenizer txtTokenizer(buffer);

    std::vector<std::unique_ptr<Token>> tokens = txtTokenizer.generateTokens();

    for (const auto& token : tokens) {
        std::cout << token->getLatexContent() << std::endl;
    }

    //std::cout << BOLD_TEXT_TAG << std::endl;
}
