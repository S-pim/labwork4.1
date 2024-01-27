#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "mystring.h"

#define BUFFER_SIZE 256

int main() {
    char buffer[BUFFER_SIZE];

    while (1) {
        printf("Enter a string (Ctrl+D to exit): ");
        int result = scanf(" %255[^\n]", buffer);

        if (result == EOF) {
            break; 
        } else if (result == 0) {
            fprintf(stderr, "Error in input\n");
            while (fgetc(stdin) != '\n');
            continue;
        }

        int shiftAmount;
        printf("Enter the shift amount: ");
        result = scanf("%d", &shiftAmount);

        if (result != 1) {
            fprintf(stderr, "Error in shift amount input\n");
            continue;
        }

        cyclicShiftWords(buffer, shiftAmount);
        printf("Result: %s\n", buffer);
    }

    return 0;
}