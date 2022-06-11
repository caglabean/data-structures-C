all: clear clean compile run

clear:
	@clear

clean:
	@rm -rf test

compile: main.c utils.c utils.h
	@gcc main.c utils.c -o test

run:
	./test
