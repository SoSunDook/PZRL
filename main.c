#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

int fbin(char *num) {
    int res = 0;
    int len = strlen(num);
    for (int i = 0; i < len; ++i) {
        res <<= 1;
        res += (num[i] - '0');
    }
    return res;
}

char *tbin(int num) {
    int i = 0;
    char *res = NULL;
    while (num > 0) {
        res = realloc(res, (i+1)*sizeof(char));
        res[i] = (char)(num % 2) + '0';
        num >>= 1;
        i++;
    }
    res[i] = '\0';
    strrev(res);
    return res;
}

int foct(char *num) {
    num++;
    int res = 0;
    int len = strlen(num);
    for (int i = 0; i < len; ++i) {
        res <<= 3;
        res += (num[i] - '0');
    }
    return res;
}

char *toct(int num) {
    int i = 0;
    char *res = NULL;
    while (num > 0) {
        res = realloc(res, (i+1)*sizeof(char));
        res[i] = (char)(num % 8) + '0';
        num >>= 3;
        i++;
    }
    res[i] = '\0';
    strrev(res);
    return res;
}

int fhex(char *num) {
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
    return res;
}

char *thex(int num) {
    int i = 0;
    char *res = NULL;
    while (num > 0) {
        res = realloc(res, (i+1)*sizeof(char));
        if (num % 16 < 10) {
            res[i] = (char)(num % 16) + '0';
        }else{
            res[i] = (char)(num % 16)- 10 + 'a';
        }
        num >>= 4;
        i++;
    }
    res[i] = '\0';
    strrev(res);
    return res;
}

char *calc(char *input) {
    char num1[SIZE];
    char num2[SIZE];
    char op;
    if (input[0] == '~') {
        op = input[0];
        strcpy(num1, input+1);
    }else{
        strip(input, num1, num2, &op);
    }
    printf("%s %s %c\n", num1, num2, op);
    printf("fbin(10) : %i\n", fbin("10"));
    printf("tbin(8) : %s\n", tbin(8));
    printf("foct(10) : %i\n", foct("010"));
    printf("toct(8) : %s\n", toct(8));
    printf("fhex(10) : %i\n", fhex("0x10"));
    printf("thex(8) : %s\n", thex(8));
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