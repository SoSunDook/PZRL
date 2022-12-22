#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "hex.h"
#include "reverse.h"

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
        if (!(((num[i] >= '0') && (num[i] <= '9')) || ((tolower(num[i]) >= 'a') && (tolower(num[i]) <= 'f')))) {
            printf("Error\n");
            exit(0);
        }
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