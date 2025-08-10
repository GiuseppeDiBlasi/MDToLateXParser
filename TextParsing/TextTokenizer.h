//
// Created by Giuse on 10/08/2025.
//

#ifndef MDTOLATEXPARSER_TEXTTOKENIZER_H
#define MDTOLATEXPARSER_TEXTTOKENIZER_H
#include <string>
#include <vector>

#include "Tokens/Token.h"


class TextTokenizer {
public:
    TextTokenizer();
    ~TextTokenizer();

    std::vector<Token> generateTokens(const std::vector<std::string>& text);

private:
};


#endif //MDTOLATEXPARSER_TEXTTOKENIZER_H