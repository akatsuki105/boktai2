CXX ?= g++

CXXFLAGS = -Wall -Werror -std=c++20 -O2

SRCS = scaninc.cpp c_file.cpp asm_file.cpp source_file.cpp

HEADERS := scaninc.hpp asm_file.hpp c_file.hpp source_file.hpp

.PHONY: all clean

ifeq ($(OS),Windows_NT)
EXE := .exe
else
EXE :=
endif

all: scaninc$(EXE)
	@:

scaninc$(EXE): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $@ $(LDFLAGS)

clean:
	$(RM) scaninc scaninc.exe
