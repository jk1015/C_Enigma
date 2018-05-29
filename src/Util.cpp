#include "Util.hpp"
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

int alphabet_base = 65;
int alphabet_size = 26;

//Read file to int vector;.
void readFile(char* filename, vector<int>& config)
{
  ifstream inFile;
  inFile.open(filename);
  config.clear();

  if(!inFile)
  {
    string msg = "Unable to open ";
    throw runtime_error(msg + filename);
  }

  int buffer;
  while(inFile >> buffer)
  {
    config.push_back(buffer);
  }
}

//Map character to int. Error if not A..Z
int charToInt(char c)
{
  int i = ((int) c) - alphabet_base;

  if(i < 0 || i >= alphabet_size)
  {
    string msg = "Invalid character: \"";
    msg += c;
    msg += "\"";
    throw invalid_argument(msg);
  }
  return i;
}

//Map int to character.
char intToChar(int i)
{
  return (char) (i + alphabet_base);
}
