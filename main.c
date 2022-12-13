#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funcs.h"

#define SIZE 128

<<<<<<< HEAD
=======
char *strrev(char *str) {
    char *p1, *p2;
    if (! str || ! *str) {
        return str;
    }
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

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

int fbin(char *num) {
    int f = 0;
    if (num[0] == '-') {
        f = 1;
        num++;
    }
    int res = 0;
    int len = strlen(num);
    for (int i = 0; i < len; ++i) {
        res <<= 1;
        res += (num[i] - '0');
    }
    if (f) {
        return -res;
    }
    return res;
}

char *tbin(int num) {
    char *res = NULL;
    if (num == 0) {
        res = realloc(res, (2)*sizeof(char));
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    int num1 = (num > 0) ? num : -num;
    int i = 0;
    while (num1 > 0) {
        res = realloc(res, (i+1)*sizeof(char));
        res[i] = (char)(num1 % 2) + '0';
        num1 >>= 1;
        i++;
    }
    if (num > 0) {
        res = realloc(res, (i+1)*sizeof(char));
        res[i] = '\0';
        strrev(res);
    }else{
        res = realloc(res, (i+2)*sizeof(char));
        res[i] = '-';
        res[i+1] = '\0';
        strrev(res);
    }
    return res;
}

int foct(char *num) {
    int f = 0;
    if (num[0] == '-') {
        f = 1;
        num++;
    }
    num++;
    int res = 0;
    int len = strlen(num);
    for (int i = 0; i < len; ++i) {
        res <<= 3;
        res += (num[i] - '0');
    }
    if (f) {
        return -res;
    }
    return res;
}

char *toct(int num) {
    char *res = NULL;
    if (num == 0) {
        res = realloc(res, (2)*sizeof(char));
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    int num1 = (num > 0) ? num : -num;
    int i = 0;
    if (num == 0) {
        res = realloc(res, (2)*sizeof(char));
        res[0] = '0';
        res[1] = '\0';
    }
    while (num1 > 0) {
        res = realloc(res, (i+1)*sizeof(char));
        res[i] = (char)(num1 % 8) + '0';
        num1 >>= 3;
        i++;
    }
    if (num > 0) {
        res = realloc(res, (i+2)*sizeof(char));
        res[i] = '0';
        res[i+1] = '\0';
        strrev(res);
    }else{
        res = realloc(res, (i+3)*sizeof(char));
        res[i] = '0';
        res[i+1] = '-';
        res[i+2] = '\0';
        strrev(res);
    }
    return res;
}

int fhex(char *num) {
    int f = 0;
    if (num[0] == '-') {
        f = 1;
        num++;
    }
    num++;
    num++;
    int res = 0;
    int len = strlen(num);
    for (int i = 0; i < len; ++i) {
        res <<= 4;
        if (isdigit(num[i])) {
            res += (num[i] - '0');
        }else{
            res += (tolower(num[i]) - 'a' + 10);
        }
    }
    if (f) {
        return -res;
    }
    return res;
}

char *thex(int num) {
    char *res = NULL;
    if (num == 0) {
        res = realloc(res, (2)*sizeof(char));
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    int num1 = (num > 0) ? num : -num;
    int i = 0;
    if (num == 0) {
        res = realloc(res, (2)*sizeof(char));
        res[0] = '0';
        res[1] = '\0';
    }
    while (num1 > 0) {
        res = realloc(res, (i+1)*sizeof(char));
        if (num1 % 16 < 10) {
            res[i] = (char)(num1 % 16) + '0';
        }else{
            res[i] = (char)(num1 % 16)- 10 + 'a';
        }
        num1 >>= 4;
        i++;
    }
    if (num > 0) {
        res = realloc(res, (i+3)*sizeof(char));
        res[i] = 'x';
        res[i+1] = '0';
        res[i+2] = '\0';
        strrev(res);
    }else{
        res = realloc(res, (i+4)*sizeof(char));
        res[i] = 'x';
        res[i+1] = '0';
        res[i+2] = '-';
        res[i+3] = '\0';
        strrev(res);
    }
    return res;
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

>>>>>>> face9babe35741d7c1090e21e6713ab57ca0ba0c
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