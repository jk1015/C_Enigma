# edit this makefile so that running make compiles your enigma program
CPPFLAGS = -Wall -g
OBJECTS = Mapping.o Rotor.o Reflector.o Plugboard.o Machine.o Main.o




enigma: $(OBJECTS)
	g++ $(CPPFLAGS) -o enigma $(OBJECTS)

Main.o: Main.cpp
	g++ $(CPPFLAGS) -c Main.cpp

Machine.o: Machine.cpp Rotor.hpp Reflector.hpp Plugboard.hpp Mapping.hpp
	g++ $(CPPFLAGS) -c Machine.cpp

Rotor.o: Rotor.cpp Rotor.hpp Mapping.hpp
	g++ $(CPPFLAGS) -c Rotor.cpp

Reflector.o: Reflector.cpp Reflector.hpp Mapping.hpp
	g++ $(CPPFLAGS) -c Reflector.cpp

Plugboard.o: Plugboard.cpp Plugboard.hpp Mapping.hpp
	g++ $(CPPFLAGS) -c Plugboard.cpp

Mapping.o: Mapping.cpp Mapping.hpp
	g++ $(CPPFLAGS) -c Mapping.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
