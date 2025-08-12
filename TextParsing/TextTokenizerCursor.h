//
// Created by Giuse on 12/08/2025.
//

#ifndef MDTOLATEXPARSER_TEXTTOKENIZERCURSOR_H
#define MDTOLATEXPARSER_TEXTTOKENIZERCURSOR_H

#include <cstddef>
#include <vector>
#include <string>

#include "MDTagConstants.h"


namespace crsResults {
    enum CursorMoveResult {
    MOVING_CURRENT_LINE,
    NEXT_LINE,
    END_OF_FILE
};
}


class TextTokenizerCursor {
    public:

    TextTokenizerCursor() = default;


    explicit TextTokenizerCursor(const std::vector<std::string>& text) : text(text) {
        numRow = 0;
        cursorPos = 0;
        lastMoveResult = crsResults::MOVING_CURRENT_LINE;
    }

    ~TextTokenizerCursor() = default;

    crsResults::CursorMoveResult moveCursorForward();


    [[nodiscard]] char peekNextChar() const;



    [[nodiscard]] char getCurrentChar() const;


    [[nodiscard]] char getCharAt(std::size_t row, std::size_t idx) const;


    [[nodiscard]] crsResults::CursorMoveResult getLastMoveResult() const;

    void skipBoldTag();


private:
    const std::vector<std::string> text;

    std::size_t numRow = 0 ;
    std::size_t cursorPos = 0;

    crsResults::CursorMoveResult lastMoveResult = crsResults::MOVING_CURRENT_LINE;

    void moveCursorAmount(const size_t amount) {
        for (size_t i = 0; i < amount; ++i)
            moveCursorForward();
    }

};

#endif //MDTOLATEXPARSER_TEXTTOKENIZERCURSOR_H