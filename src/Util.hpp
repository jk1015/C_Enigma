#include <vector>

#ifndef UTIL_H
#define UTIL_H

extern int alphabet_base;
extern int alphabet_size;
void readFile(char* filename, std::vector<int>& config);
int charToInt(char c);
char intToChar(int i);


#endif
