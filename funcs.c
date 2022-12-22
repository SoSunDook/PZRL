#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "bin.h"
#include "oct.h"
#include "hex.h"

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
                *op = input[0];
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

int count(int num1, int num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '%':
            return num1 % num2;
        case '&':
            if (num1 < 0 || num2 < 0) {
                printf("Error\n");
                exit(0);
            }
            return num1 & num2;
        case '|':
            if (num1 < 0 || num2 < 0) {
                printf("Error\n");
                exit(0);
            }
            return num1 | num2;
        case '^':
            if (num1 < 0 || num2 < 0) {
                printf("Error\n");
                exit(0);
            }
            return num1 ^ num2;
        default:
            printf("Error\n");
            exit(0);
            return 0;
    }
}

int type(char *num) {
    if (num[0] == '-') {
        num++;
    }
    if (strlen(num) == 1) {
        return 0;
    }
    if (num[0] == '0' && num[1] == 'x') {
        return 2;
    }
    if (num[0] == '0') {
        return 1;
    }
    return 0;
}

int compare(char *num1, char *num2) {
    if (type(num1) == type(num2)) {
        return 1;
    }
    return 0;
}

char *calc(char *input) {
    char num1[SIZE];
    char num2[SIZE];
    char op;
    if (input[0] == '~') {
        op = input[0];
        strcpy(num1, input+1);
        int tp = type(num1);
        switch (tp) {
            case 0:
                return tbin(~fbin(num1));
            case 1:
                return toct(~foct(num1));
            case 2:
                return thex(~fhex(num1));
        }
    }else{
        strip(input, num1, num2, &op);
        int tp = type(num1);
        if (compare(num1, num2)) {
            switch (tp) {
                case 0:
                    return tbin(count(fbin(num1), fbin(num2), op));
                case 1:
                    return toct(count(foct(num1), foct(num2), op));
                case 2:
                    return thex(count(fhex(num1), fhex(num2), op));
            }
        }else{
            return NULL;
        }
    }
}

void printres(char *res) {
    if (res == NULL) {
        printf("Systems of numbers does not match\n");
    }else{
        int tp = type(res);
        if (tp == 0) {
            printf("%s (%i)\n", res, fbin(res));
        }else if (tp == 1) {
            printf("%s (%i)\n", res, foct(res));
        }else if (tp == 2) {
            printf("%s (%i)\n", res, fhex(res));
        }
    }
}