//
// Created by Giuse on 10/08/2025.
//

#ifndef MDTOLATEXPARSER_TOKEN_H
#define MDTOLATEXPARSER_TOKEN_H

#include <string>
#include <utility>

class Token {
    public:
    Token() = default;

    explicit Token(std::string  s) : content(std::move(s)) {}

    virtual ~Token() = default;

    virtual std::string getLatexContent() const{
        return content;
    };

protected:
    std::string content;

};


#endif //MDTOLATEXPARSER_TOKEN_H