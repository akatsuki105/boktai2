CXX ?= g++

CXXFLAGS = -Wall -Werror -std=c++11 -O2

SRCS = bytecode.cpp lexer.cpp parser.cpp assembler.cpp render.cpp main.cpp

HEADERS := bytecode.h lexer.h parser.h assembler.h render.h

.PHONY: all clean

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

all: bokasm$(EXE)
	@:

bokasm$(EXE): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) bokasm bokasm.exe
