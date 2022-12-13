#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "oct.h"
#include "reverse.h"

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