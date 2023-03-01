clean:
	-rm output/main

all: clean
	clang++ -o output/main src/main.cpp src/expreval.cpp

run: all
	./output/main
