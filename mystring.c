#include <string.h>
#include "mystring.h"

void cyclicShiftWords(char *str, int shiftAmount) {
    char *token = strtok(str, " ");
    while (token != NULL) {
        int tokenLength = strlen(token);
        int shift = shiftAmount % tokenLength;

       
        memmove(token + shift, token, tokenLength - shift);
        memmove(token, token + tokenLength - shift, shift);

        token = strtok(NULL, " ");
    }
}
