all:
	gcc -g -Wall -Wpedantic -o main main.c

c:
	gcc -g -o main main.c

run:
	./main

debug:
	valgrind -s --show-leak-kinds=all --track-origins=yes ./main
