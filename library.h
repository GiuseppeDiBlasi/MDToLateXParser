#ifndef MDTOLATEXPARSER_LIBRARY_H
#define MDTOLATEXPARSER_LIBRARY_H

#include <string>
#include <vector>

#include "exceptionConstants.h"

void hello();

void loadBufferFromFile(std::vector<std::string>&, const std::string&);
void printBuffer(const std::vector<std::string>&);

#endif // MDTOLATEXPARSER_LIBRARY_H