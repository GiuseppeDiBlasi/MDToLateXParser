//
// Created by Giuse on 10/08/2025.
//

#ifndef MDTOLATEXPARSER_TOKEN_H
#define MDTOLATEXPARSER_TOKEN_H
#include <string>


class Token {
    public:
    Token() = default;

    virtual ~Token() = default;

    virtual std::string getLatexContent() = 0;

    enum TokenType {
        TYPE_PLAIN_TEXT,
        TYPE_HEADER,
        TYPE_BOLD_TEXT,
        TYPE_BULLETED_LIST
    };

protected:
    std::string content;

};


#endif //MDTOLATEXPARSER_TOKEN_H