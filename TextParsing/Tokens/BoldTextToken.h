//
// Created by Giuse on 10/08/2025.
//

#ifndef MDTOLATEXPARSER_BOLDTEXTTOKEN_H
#define MDTOLATEXPARSER_BOLDTEXTTOKEN_H
#include "Token.h"
#include "../LatexTagConstants.h"

class BoldTextToken final : public Token{
    public:
    explicit BoldTextToken(const std::string& txt) : Token(txt) {};

    std::string getLatexContent() const override {
        return lxtTags::BOLD_TEXT_TAG + "{" + this->content + "}";
    };
};


#endif //MDTOLATEXPARSER_BOLDTEXTTOKEN_H