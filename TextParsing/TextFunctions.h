//
// Created by Giuse on 11/08/2025.
//

#ifndef MDTOLATEXPARSER_TEXTFUNCTIONS_H
#define MDTOLATEXPARSER_TEXTFUNCTIONS_H
#include "MDTagConstants.h"

namespace txtFuncs{
    inline bool isText(const char c) {
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }

    inline bool canBeMDTag(const char c) {
        return c == mdTags::BOLD_TAG || c == mdTags::BULLETED_LIST_TAG || c == mdTags::HEADER_TAG;
    }
}

#endif //MDTOLATEXPARSER_TEXTFUNCTIONS_H