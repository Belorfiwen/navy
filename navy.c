#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 256

int main() {

	setbuf(stdout, NULL);
	char buffer[BUFSIZE];

	// mines
	printf("C2\n");
	printf("H2\n");
	printf("C7\n");
	printf("H7\n");
	printf("E5\n");

	// ships
	printf("B2B6\n");
	fgets(buffer, BUFSIZE, stdin);
	assert(strcmp(buffer, "OK\n") == 0);

	printf("E8H8\n");
	fgets(buffer, BUFSIZE, stdin);
	assert(strcmp(buffer, "OK\n") == 0);

	printf("D1F1\n");
	fgets(buffer, BUFSIZE, stdin);
	assert(strcmp(buffer, "OK\n") == 0);

	printf("G5I5\n");
	fgets(buffer, BUFSIZE, stdin);
	assert(strcmp(buffer, "OK\n") == 0);

	printf("I0I1\n");
	fgets(buffer, BUFSIZE, stdin);
	assert(strcmp(buffer, "OK\n") == 0);

	fgets(buffer, BUFSIZE, stdin);
	assert(strcmp(buffer, "START\n") == 0);

	for (;;) {
		
		printf("SHOOT\n"); // or POOL or MOVE
		printf("D2\n");
		fgets(buffer, BUFSIZE, stdin);
		assert(strcmp(buffer, "MISS\n") == 0);

		fgets(buffer, BUFSIZE, stdin);
		// NOTHING or MISSED or KABOOM or ATTACK
	}
	return EXIT_SUCCESS;
}