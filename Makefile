# CS4280 11/16/22 Bryce Paubel P4
# Makefile to compile P4

# NOTE THAT THIS IS HEAVILY BASED ON A MAKEFILE
# FROM CS2750, WHICH I TOOK SUMMER 2021 AND BASED MY
# MAKEFILE HEAVILY ON AN EXAMPLE WITHIN THE COURSE

CC = g++

FLAGS = -Wall -g -std=c++11

DEPS = ./src/main.cpp ./src/files.cpp ./src/globalTable.cpp ./src/gtp.cpp
OBJ = ./build/main.o ./build/files.o ./build/globalTable.o ./build/gtp.o

TARGET = gtp

# By default make will start with the first target
# which in this case is our executable, target
$(TARGET): $(OBJ)
	$(CC) $(FLAGS) -o $@ $^
	rm $(OBJ)

./build/%.o: ./src/%.cpp $(DEPS)
	$(CC) $(FLAGS) -c -o $@ $<

./build/%.o: ./test/%.cpp $(DEPS)
	$(CC) $(FLAGS) -c -o $@ $<

# Run the program (if not compiled, will compile)
# This works with default input, from the keyboard
.PHONY: run
run:
	make
	$(TARGET)