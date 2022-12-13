#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcs.h"

#define SIZE 128

int main() {
    char *input = (char *)malloc(SIZE*sizeof(char));
    fgets(input, SIZE, stdin);
    char *pos = strchr(input, '\n');
    *pos = '\0';
    char *res = calc(input);
    printres(res);
    free(res);
    free(input);
    return 0;
}