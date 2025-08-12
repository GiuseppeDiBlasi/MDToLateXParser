//
// Created by Giuse on 12/08/2025.
//


#include "TextTokenizerCursor.h"


crsResults::CursorMoveResult TextTokenizerCursor::moveCursorForward() {
    if (cursorPos + 1 < text[numRow].length()) {
        ++cursorPos;
        lastMoveResult = crsResults::MOVING_CURRENT_LINE;
        return crsResults::MOVING_CURRENT_LINE;
    }

    cursorPos = 0;

    if (numRow + 1 < text.size()) {
        ++numRow;
        lastMoveResult = crsResults::NEXT_LINE;
        return crsResults::NEXT_LINE;
    }

    lastMoveResult = crsResults::END_OF_FILE;
    return crsResults::END_OF_FILE;

}

[[nodiscard]] char TextTokenizerCursor::peekNextChar() const {
    if (cursorPos + 1 < text[numRow].length())
        return text[numRow][cursorPos + 1];
    if (numRow + 1 < text[numRow].size())
        return text[numRow + 1][0];

    return '\0';

}

[[nodiscard]] char TextTokenizerCursor::getCurrentChar() const{
    return text[numRow][cursorPos];
}

[[nodiscard]] char TextTokenizerCursor::getCharAt(const std::size_t row, const std::size_t idx) const{
    return text[row][idx];
}

[[nodiscard]] crsResults::CursorMoveResult TextTokenizerCursor::getLastMoveResult() const{ return lastMoveResult; }

void TextTokenizerCursor::skipBoldTag() {
    if (getCurrentChar() == peekNextChar() && getCurrentChar() == mdTags::BOLD_TAG) {
        moveCursorAmount(2);
    }
}
