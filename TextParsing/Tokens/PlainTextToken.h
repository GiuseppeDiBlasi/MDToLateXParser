//
// Created by Giuse on 10/08/2025.
//

#ifndef MDTOLATEXPARSER_PLAINTEXTTOKEN_H
#define MDTOLATEXPARSER_PLAINTEXTTOKEN_H

#include "Token.h"


class PlainTextToken final : public Token {
public:
    PlainTextToken() : Token() {}
    explicit PlainTextToken(const std::string& s) : Token(s) {}

    std::string getLatexContent() const override;
};


#endif //MDTOLATEXPARSER_PLAINTEXTTOKEN_H