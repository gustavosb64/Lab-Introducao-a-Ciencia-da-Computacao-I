all:
	gcc -g -Wall -Wpedantic -o hitbox hitbox.c

c:
	gcc -g -o hitbox hitbox.c

run:
	./hitbox

debug:
	valgrind --leak-check=full --show-leak-kinds=all ./hitbox
