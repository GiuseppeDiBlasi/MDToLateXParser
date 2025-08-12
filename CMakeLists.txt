cmake_minimum_required(VERSION 4.0)
project(MDToLateXParser)

set(CMAKE_CXX_STANDARD 17)

#####
### Header files under TextParsing/ directory
#####
set(DIR_TEXT_PARSING_HEADERS
        TextParsing/MDTagConstants.h
        TextParsing/TextFunctions.h
        TextParsing/LatexOutput.h
        TextParsing/LatexTagConstants.h
        TextParsing/TextTokenizerCursor.h
)

#####
### Header files under TextParsing/Tokens directory
#####

set(DIR_TEXT_PARSING_TOKENS_HEADERS
        TextParsing/Tokens/BoldTextToken.h
        TextParsing/Tokens/TokenCharsConstants.h
        TextParsing/Tokens/PlainTextToken.h
        TextParsing/Tokens/Token.h
)

#####
### CPP files under TextParsing/ directory
#####
set(DIR_TEXT_PARSING_CPP
        TextParsing/TextTokenizer.cpp
        TextParsing/LatexOutput.cpp
        TextParsing/TextTokenizerCursor.cpp
)

#####
### CPP files under TextParsing/Tokens directory
#####

set(DIR_TEXT_PARSING_TOKENS_CPP
        TextParsing/Tokens/BoldTextToken.cpp
        TextParsing/Tokens/PlainTextToken.cpp
        TextParsing/Tokens/Token.cpp
)

add_library(MDToLateXParser SHARED
        ${DIR_TEXT_PARSING_HEADERS}
        ${DIR_TEXT_PARSING_TOKENS_HEADERS}
        ${DIR_TEXT_PARSING_CPP}
        ${DIR_TEXT_PARSING_TOKENS_CPP}
        library.cpp

)
target_include_directories(MDToLateXParser
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        PRIVATE TextParsing
        PRIVATE TextParsing/Tokens
)

add_executable(parser_test main.cpp)

target_link_libraries(parser_test PRIVATE MDToLateXParser)