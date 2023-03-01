clean:
	-rm output/main

test: clean
	clang++ -o output/main src/main.cpp src/expreval.cpp

run: test
	./output/main
