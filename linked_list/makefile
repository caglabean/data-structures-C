all: clean compile run



clean:
	@echo "Removing compiled files and text file.\n*********************************"

	@rm -f test

compile: 210104004158.c 
	@echo "Compiling.\n*********************************"
	@gcc 210104004158.c -o test

run:
	@echo "Running the program.\n*********************************"
	./test
	@echo "*********************************\nCompleted.\n"