#include "stack.h"

// typedef struct {
//     char items[MAX];
//     int top;
// } Stack;

// // Struktur stack untuk string
// typedef struct {
//     char items[MAX][MAX];
//     int top;
// } StrStack;

void initStack(Stack *s) {
    s->top = -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->items[++s->top] = c;
    }
}

char pop(Stack *s) {
    return (s->top >= 0) ? s->items[s->top--] : '\0';
}

char peek(Stack *s) {
    return (s->top >= 0) ? s->items[s->top] : '\0';
}

int precedence(char op) {
    switch (op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}