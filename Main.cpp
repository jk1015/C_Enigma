// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <stdexcept>
#include "Mapping.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "Plugboard.hpp"
#include "Machine.hpp"

using namespace std;

void readFile(char* filename, vector<int>& config);
void stringToIntVector(string s, vector<int>& v);
int charToInt(char c);
char intToChar(int i);
//Extract 26 to global
//Check errors with exceptions and catch to give better error messages


int main(int argc, char **argv)
{
  vector<Mapping*> maps;
  vector<int> config;
  string contents;

  if(argc > 1)
  {
    try
    {
      readFile(argv[argc -1], config);
      Plugboard* plug = new Plugboard(config);
      maps.push_back(plug);
    }
    catch (exception& ex)
    {
      cerr << "error in " << argv[argc -1] << ex.what() << endl;
      throw ex;
    }
  }
  else
  {
    throw runtime_error("A plugboard mapping must be provided!");
  }

  for(int i = 1; i < argc - 1; i++)
  {
    try
    {
      readFile(argv[i], config);
      Rotor* rotor = new Rotor(config);
      maps.push_back(rotor);
    }
    catch (exception& ex)
    {
      cerr << "error in " << argv[i] << endl;
      throw ex;
    }
  }

  Reflector* ref = new Reflector();
  maps.push_back(ref);

  Machine* m = new Machine(maps);
  vector<int> output;

  string input;
  cin >> input;

  stringToIntVector(input, output);


  for(unsigned i = 0; i < output.size(); i++)
  {
    m->map(output[i]);
    std::cout << intToChar(output[i]);
  }
  cout << endl;

  return 0;
}

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

//Transform string to int vector with removed whitespane.
void stringToIntVector(string s, vector<int>& v)
{
  v.clear();
  for(string::iterator it = s.begin(); it != s.end(); it++)
  {
    if(!isspace(*it))
    {
        v.push_back(charToInt(*it));
    }
  }
}


//Map character to int. Error if not A..Z
int charToInt(char c)
{
  int i = ((int) c) - 65;

  if(i < 0 || i > 25)
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
  return (char) (i + 65);
}
