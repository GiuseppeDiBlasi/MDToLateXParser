//
// Created by Giuse on 10/08/2025.
//

#include "TextTokenizer.h"

#include <stack>
#include "TextFunctions.h"
#include "Tokens/BoldTextToken.h"

#include "Tokens/Token.h"
#include "Tokens/PlainTextToken.h"

bool TextTokenizer::handleBoldTag(char c, std::stack<TextTokenizer::type_state>& states, std::vector<std::unique_ptr<Token>>& tokens) {

    const char nextChar = textCursor.peekNextChar();

    if (nextChar == '\0') {
        textCursor.moveCursorForward();
        states.top().content += c;

        return false;
    }

    if (nextChar == c) {
        //I close the tag and create the token and return true
        if (states.top().openTag) {
            states.top().openTag = false;
            tokens.push_back(std::make_unique<BoldTextToken>(BoldTextToken(states.top().content)));
            states.pop();

            textCursor.skipBoldTag();

            return true;
        }

        //I check if there is another tag before the current one
        if (!states.empty() && states.top().state == PLAIN_TEXT) {
            tokens.push_back(std::make_unique<PlainTextToken>(PlainTextToken(states.top().content)));
            states.pop();
        }


        //I skip to the first valid character after the opening the bold tag
        textCursor.skipBoldTag();
        c = textCursor.getCurrentChar();

        type_state ts = {"", BOLD_TEXT, true};

        ts.content += c;

        states.push(ts);

    }

    return true;
}


std::vector<std::unique_ptr<Token>> TextTokenizer::generateTokens() {
    std::vector<std::unique_ptr<Token>> tokens;
    std::stack<type_state> states;

    while (textCursor.getLastMoveResult() != crsResults::END_OF_FILE) {
        char c = textCursor.getCurrentChar();

        bool canBeMdTag =  txtFuncs::canBeMDTag(c);

        //Here I decide whether to open or close tags
        if (canBeMdTag) {
            if (c == mdTags::BOLD_TAG) {
                if (handleBoldTag(c, states, tokens)) {
                    textCursor.moveCursorForward();
                    continue;
                }


            }
        }
        //here whe put the text on the current state
        else {
            //If there are any tags opened then it's normal text
            if (states.empty()) {
                type_state ts = {"", PLAIN_TEXT};
                ts.content += c;
                states.push(ts);

                textCursor.moveCursorForward();
                continue;

            }

            states.top().content += c;
        }

        textCursor.moveCursorForward();
    }

    //Check for remaining tags after reaching end of file
    while (!states.empty()) {
        type_state ts = states.top();
        states.pop();

        switch (ts.state) {
            case PLAIN_TEXT:
                tokens.push_back(std::make_unique<Token>(PlainTextToken(ts.content)));
                break;

            case BOLD_TEXT:
                tokens.push_back(std::make_unique<Token>(BoldTextToken(ts.content)));
                break;

            // case BULLETED_LIST:
            //     tokens.push_back(std::make_unique<Token>(BulletListToken(ts.content)));
            //     break;

            default:
                break;
        }
    }

    return tokens;
}

