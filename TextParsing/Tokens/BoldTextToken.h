//
// Created by Giuse on 10/08/2025.
//

#ifndef MDTOLATEXPARSER_BOLDTEXTTOKEN_H
#define MDTOLATEXPARSER_BOLDTEXTTOKEN_H
#include "Token.h"


class BoldTextToken final : Token{
    public:
    explicit BoldTextToken(const std::string& txt);

};


#endif //MDTOLATEXPARSER_BOLDTEXTTOKEN_H