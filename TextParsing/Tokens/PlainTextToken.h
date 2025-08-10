//
// Created by Giuse on 10/08/2025.
//

#ifndef MDTOLATEXPARSER_PLAINTEXTTOKEN_H
#define MDTOLATEXPARSER_PLAINTEXTTOKEN_H
#include "Token.h"


class PlainTextToken final : Token{
    public:

    PlainTextToken() = default;
    ~PlainTextToken() override = default;

    std::string getLatexContent() override;

};


#endif //MDTOLATEXPARSER_PLAINTEXTTOKEN_H