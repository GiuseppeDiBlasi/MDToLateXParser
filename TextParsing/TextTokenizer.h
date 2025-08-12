//
// Created by Giuse on 10/08/2025.
//

#ifndef MDTOLATEXPARSER_TEXTTOKENIZER_H
#define MDTOLATEXPARSER_TEXTTOKENIZER_H
#include <memory>
#include <stack>
#include <string>
#include <vector>

#include "TextTokenizerCursor.h"
#include "Tokens/Token.h"


class TextTokenizer {

private:
private:
    TextTokenizerCursor textCursor;

    enum StateEnum {
        PLAIN_TEXT,
        BOLD_TEXT,
        BULLETED_LIST,
        HEADER,
    };

    struct type_state{
        std::string content;
        StateEnum state;
        bool openTag = false;
    };

public:
    TextTokenizer() = default;

    explicit TextTokenizer(const std::vector<std::string>& text) : textCursor(text) {};

    ~TextTokenizer() = default;

    std::vector<std::unique_ptr<Token>> generateTokens();

    bool handleBoldTag(char, std::stack<type_state>&, std::vector<std::unique_ptr<Token>>&);


};


#endif //MDTOLATEXPARSER_TEXTTOKENIZER_H