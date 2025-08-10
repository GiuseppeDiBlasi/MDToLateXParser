//
// Created by Giuse on 10/08/2025.
//

#include "TextTokenizer.h"

#include "Tokens/Token.h"
#include "Tokens/TokenCharsConstants.h"

std::vector<Token> TextTokenizer::generateTokens(const std::vector<std::string> &text) {
        std::vector<Token> tokens{};
        for (const std::string& s : text) {
                size_t boldTextIdx = s.find(BOLD_TEXT);

                if (boldTextIdx != std::string::npos) {

                }

        }

}
