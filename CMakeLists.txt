cmake_minimum_required(VERSION 4.0)
project(MDToLateXParser)

set(CMAKE_CXX_STANDARD 17)

#library
add_library(MDToLateXParser SHARED library.cpp
        exceptionConstants.h
        TextParsing/TextTokenizer.cpp
        TextParsing/TextTokenizer.h
        TextParsing/Tokens/Token.cpp
        TextParsing/Tokens/Token.h
        TextParsing/Tokens/PlainTextToken.cpp
        TextParsing/Tokens/PlainTextToken.h
        TextParsing/LatexOutput.cpp
        TextParsing/LatexOutput.h
        TextParsing/Tokens/TokenCharsConstants.h
        TextParsing/Tokens/BoldTextToken.cpp
        TextParsing/Tokens/BoldTextToken.h
        TextParsing/LatexTagConstants.h)

#test exe
add_executable(parser_test main.cpp)

#link exe to library
target_link_libraries(parser_test PRIVATE MDToLateXParser)
