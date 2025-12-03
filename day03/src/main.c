#include "helpers.h"
#include <iso646.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <strings.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFFER_SIZE 300

#ifndef DIGITS
# define DIGITS 2
#endif

int main(int ac, char **av) {

    // === ERROR HANDLING ===
    if (ac != 2) {
        fprintf(stderr, "Usage: ./day03 <input-file>\n");
        return 1;
    }

    int fd = open(av[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Could not open file: %s\n", av[1]);
        return 1;
    }

    // === LOOPING THROUGH WHOLE FILE ===
    char buffer[BUFFER_SIZE];
    int bytes_read = 1;
    long result = 0;
    while (bytes_read) {
        // === GETTING THE LINE ===
        bzero(&buffer, BUFFER_SIZE);
        size_t i = 0;
        while (i < BUFFER_SIZE) {
            char curr;
            bytes_read = read(fd, &curr, sizeof(char));
            if (!bytes_read) {
                printf("The total output joltage is \e[1m%li\e[0m jolts\n", result);
                close(fd);
                return(0);
            }
            if (curr == '\n')
                break;
            buffer[i] = curr;
            i++;
        }
        if (i == BUFFER_SIZE) {
            fprintf(stderr, "Line to long. Stopping here to prevent buffer overflow!\n");
            fprintf(stderr, "Increase BUFFER_SIZE to fix this issues.\n");
            close(fd);
            return 1;
        }
        size_t line_len = i;
        if (line_len < DIGITS) {
            fprintf(stderr, "Impossible to create number with %u digits with an input of only %lu characters\n", DIGITS, line_len);
            close(fd);
            return 1;
        }
        // === PROCESSING THE LINE ===
        char digits[DIGITS + 1] = {0};
        for (size_t idx = 0; idx < line_len; idx++) {
            if (!isdigit(buffer[idx])) {
                break;
            }
            for (size_t k = 0; k < DIGITS; k++) {
                if (buffer[idx] > digits[k] && idx < (line_len - (DIGITS-1-k))) {
                    digits[k] = buffer[idx];
                    bzero(&digits[k+1], DIGITS-k);
                    break;
                }
            }
        }
        // Not protecting for potential overflow
        result += atol(&digits[0]);
    }
    close(fd);
}
