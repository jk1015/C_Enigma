# edit this makefile so that running make compiles your enigma program
CXX      = g++
CPPFLAGS = -Wall -g


TARGET = enigma
SRCDIR = src
DEPDIR = headers
OBJDIR = obj

SOURCES  := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(SRCDIR)/*.hpp)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: directories program

directories: $(OBJDIR)

program: $(TARGET)

$(OBJDIR):
	mkdir $@

$(TARGET): $(OBJECTS)
	$(CXX) $(CPPFLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	rm -rf $(TARGET) $(OBJDIR)

.PHONY: clean
