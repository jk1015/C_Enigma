#include <iostream>
#include <vector>
#include <stdexcept>
#include "Mapping.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "Plugboard.hpp"
#include "Machine.hpp"
#include "Util.hpp"

using namespace std;


int main(int argc, char **argv)
{
  vector<Mapping*> maps;
  vector<int> config;

  //Read plugboard mapping file and construct a plugboard.
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
      cerr << "--------------------------" << endl
           << "Error in plugboard file: " << argv[argc -1] << endl
           << ex.what() << endl
           << "--------------------------" << endl;
      throw ex;
    }
  }
  else
  {
    throw runtime_error("A plugboard mapping must be provided!");
  }


  //Read rotor mapping files and construct a rotor for each.
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
      cerr << "--------------------------" << endl
           << "Error in rotor file: " << argv[i] << endl
           << ex.what() << endl
           << "--------------------------" << endl;
      throw ex;
    }
  }


  Reflector* ref = new Reflector();
  maps.push_back(ref);
  Machine* m = new Machine(maps);

  //Read characters from stdin, encode and write result to stdout
  char input;
  int value;
  while(cin >> input)
  {
    if(!isspace(input))
    {
      value = charToInt(input);
      m->map(value);
      cout << intToChar(value);
    }
  }

  delete m;
  for(unsigned i = 0 ; i < maps.size(); i++)
  {
    delete maps[i];
  }

  return 0;
}
