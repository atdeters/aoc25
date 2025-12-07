/*=========================================================

	This main function can take the puzzle input by
	command-line argument or by redirecting/piping it
	into the program.

//=======================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main( int ac, char **av ) {

	int fd = 0;
	char ch;

	if (ac > 2) {
		fprintf(stderr, "Usage: ./day <puzzle-input>\n");
		return 1;
	}
	else if (ac == 2) {
		fd = open(av[1], O_RDONLY);
		if (fd == -1) {
			fprintf(stderr, "Could not open file: %s\n", av[1]);
			return 1;
		}
	}

	size_t buff_len = 2;
	size_t len = 0;

	char *input = calloc(sizeof(char), buff_len + 1);
	while(read(fd, &ch, sizeof(char))) {
		// === IF BUFFER FULL -> ALLOCATE NEW QUADRATICALLY ===
		if (len == buff_len) {
			buff_len *= 2;
			char *tmp = calloc(sizeof(char), buff_len + 1);
			if (!tmp) {
				fprintf(stderr, "Memory allocation failed\n");
				if (fd) {
					close(fd);
				}
				free(input);
				return 1;
			}
			strcat(tmp, input);
			free(input);
			input = tmp;
		}
		input[len] = ch;
		len++;
		// ==== WORKING ON INDIVIDUAL LINES HERE ====
		// if (ch == '\n') { //===HERE===// }
		// ===============
	}
	if (fd) {
		close(fd);
	}

// ===== WORKING ON FULL STRING HERE ====

// ===== CODE ENDS HERE ====
	free(input);
	return 0;
}
