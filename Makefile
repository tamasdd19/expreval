clean:
	-rm output/main

all: clean
	clang++ -o output/main src/main.cpp src/expreval.cpp -std=c++17

run: all
	./output/main

compile_test: clean
	clang++ -o output/test src/expreval.cpp test/main.cpp test/test1.cpp -Ivendor/Catch2/include

test: compile_test
	./output/test
