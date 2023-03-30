clean:
	-rm main

all: clean
	clang++ -o main.exe src/main.cpp src/expreval.cpp -std=c++17

run: all
	main

compile_test: clean
	clang++ -o test.exe src/expreval.cpp test/main.cpp test/test1.cpp -Ivendor/Catch2/include

test: compile_test
	test
