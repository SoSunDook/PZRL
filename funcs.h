#ifndef FUNCS_H
#define FUNCS_H
void strip(char *input, char *num1, char *num2, char *op);
int count(int num1, int num2, char op);
int type(char *num);
int compare(char *num1, char *num2);
char *calc(char *input);
void printres(char *res);
#endif