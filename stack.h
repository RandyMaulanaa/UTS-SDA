#ifndef STACK_H
#define STACK_H

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} Stack;

typedef struct {
    char items[MAX][MAX];
    int top;
} StrStack;

void initStack(Stack *s);
void push(Stack *s, char c);
char pop(Stack *s);
char peek(Stack *s);
int precedence(char op);
int isOperator(char c);

#endif
