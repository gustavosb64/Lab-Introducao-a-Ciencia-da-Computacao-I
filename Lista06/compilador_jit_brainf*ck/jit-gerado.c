#include <stdio.h>

int main(int argc, char *argv[]) {
	char mem[30000];

	for (int i=0; i<30000; i++) {
		mem[i]=0;
	}

	int i=0;

	while (mem[i]) {
		putchar(mem[i]);
		while (mem[i]) {
			putchar(mem[i]);
		}
		putchar(mem[i]);
		putchar(mem[i]);
		mem[i]++;
		mem[i]--;
		i--;
		i++;
		while (mem[i]) {
		}
		putchar(mem[i]);
		putchar(mem[i]);
	}
	mem[i]++;
	mem[i]++;
	mem[i]++;
	mem[i]++;
	mem[i]++;
	mem[i]++;
	mem[i]++;
	mem[i]++;
	while (mem[i]) {
		i++;
		mem[i]++;
		mem[i]++;
		mem[i]++;
		mem[i]++;
		while (mem[i]) {
			i++;
			mem[i]++;
			mem[i]++;
			i++;
			mem[i]++;
			mem[i]++;
			mem[i]++;
			i++;
			mem[i]++;
			mem[i]++;
			mem[i]++;
			i++;
			mem[i]++;
			i--;
			i--;
			i--;
			i--;
			mem[i]--;
		}
		i++;
		mem[i]++;
		i++;
		mem[i]++;
		i++;
		mem[i]--;
		i++;
		i++;
		mem[i]++;
		while (mem[i]) {
			i--;
		}
		i--;
		mem[i]--;
	}
	i++;
	i++;
	putchar(mem[i]);
	i++;
	mem[i]--;
	mem[i]--;
	mem[i]--;
	putchar(mem[i]);
	mem[i]++;
	mem[i]++;
	mem[i]++;
	mem[i]++;
	mem[i]++;
	mem[i]++;
	mem[i]++;
	putchar(mem[i]);
	putchar(mem[i]);
	mem[i]++;
	mem[i]++;
	mem[i]++;
	putchar(mem[i]);
	i++;
	i++;
	putchar(mem[i]);
	i--;
	mem[i]--;
	putchar(mem[i]);
	i--;
	putchar(mem[i]);
	mem[i]++;
	mem[i]++;
	mem[i]++;
	putchar(mem[i]);
	mem[i]--;
	mem[i]--;
	mem[i]--;
	mem[i]--;
	mem[i]--;
	mem[i]--;
	putchar(mem[i]);
	mem[i]--;
	mem[i]--;
	mem[i]--;
	mem[i]--;
	mem[i]--;
	mem[i]--;
	mem[i]--;
	mem[i]--;
	putchar(mem[i]);
	i++;
	i++;
	mem[i]++;
	putchar(mem[i]);
	i++;
	mem[i]++;
	mem[i]++;
	putchar(mem[i]);

	printf("\n");
	for (int j=0; j<30000; j++) {
		if (mem[j] != 0) {
			printf("%d ", mem[j]);
		}
	}
	printf("\n");

	return 0;
}
