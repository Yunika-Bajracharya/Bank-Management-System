CC=g++
FLAGS=-g

ifeq ($(OS),Windows_NT)
	OUTPUT=output.exe
else
	OUTPUT=output
endif

ouput: Main.cpp Bank.cpp User.cpp
	$(CC) $^ -o $(OUTPUT) $(FLAGS)
