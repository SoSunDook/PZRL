#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 128

void strip(char *input, char *num1, char *num2, char *op) {
    int i = 0;
    char *ptr = input;
    while (*ptr != '\0') {
        if (*ptr == ' ') {
            *ptr = '\0';
            if (i == 0) {
                strcpy(num1, input);
            }else if (i == 1) {
                strcpy(op, input);
            }
            *ptr = ' ';
            input = ptr + 1;
            i++;
        }else if (*(ptr+1) == '\0') {
            strcpy(num2, input);
        }
        ptr++;
    }
}

char *calc(char *input) {
    char num1[SIZE];
    char num2[SIZE];
    char op[SIZE];
    strip(input, num1, num2, op);
    printf("%s %s %s\n", num1, num2, op);
}

int main() {
    char *input = (char *)malloc(SIZE*sizeof(char));
    fgets(input, SIZE, stdin);
    char *pos = strchr(input, '\n');
    *pos = '\0';
    char *res = calc(input);
    free(input);
    return 0;
}