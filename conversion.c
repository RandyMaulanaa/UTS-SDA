#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "conversion.h"
#include "stack.h"

#define MAX 100

void infixToPostfix(char *infix, char *postfix) {
    Stack s;
    initStack(&s);
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            push(&s, c);
        } else if (c == ')') {
            while (s.top != -1 && peek(&s) != '(')
                postfix[j++] = pop(&s);
            pop(&s);
        } else if (isOperator(c)) {
            while (s.top != -1 && precedence(peek(&s)) >= precedence(c))
                postfix[j++] = pop(&s);
            push(&s, c);
        }
    }
    while (s.top != -1)
        postfix[j++] = pop(&s);
    postfix[j] = '\0';
}

// Postfix ke Infix
void postfixToInfix(char *postfix, char *infix) {
    StrStack s;
    s.top = -1;
    char buffer[MAX];
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isalnum(postfix[i])) {
            snprintf(buffer, sizeof(buffer), "%c", postfix[i]);
            strcpy(s.items[++s.top], buffer);
        } else if (isOperator(postfix[i])) {
            char op1[MAX], op2[MAX];
            strcpy(op2, s.items[s.top--]);
            strcpy(op1, s.items[s.top--]);
            snprintf(buffer, sizeof(buffer), "(%s%c%s)", op1, postfix[i], op2);
            strcpy(s.items[++s.top], buffer);
        }
    }
    strcpy(infix, s.items[s.top]);
}

// Infix ke Prefix
void infixToPrefix(char *infix, char *prefix) {
    strrev(infix);
    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }
    infixToPostfix(infix, prefix);
    strrev(prefix);
}

// Prefix ke Infix
void prefixToInfix(char *prefix, char *infix) {
    StrStack s;
    s.top = -1;
    strrev(prefix);
    char buffer[MAX];
    for (int i = 0; prefix[i] != '\0'; i++) {
        if (isalnum(prefix[i])) {
            snprintf(buffer, sizeof(buffer), "%c", prefix[i]);
            strcpy(s.items[++s.top], buffer);
        } else if (isOperator(prefix[i])) {
            char op1[MAX], op2[MAX];
            strcpy(op1, s.items[s.top--]);
            strcpy(op2, s.items[s.top--]);
            snprintf(buffer, sizeof(buffer), "(%s%c%s)", op1, prefix[i], op2);
            strcpy(s.items[++s.top], buffer);
        }
    }
    strcpy(infix, s.items[s.top]);
}

// Prefix ke Postfix
void prefixToPostfix(char *prefix, char *postfix) {
    char infix[MAX];
    prefixToInfix(prefix, infix);
    infixToPostfix(infix, postfix);
}

// Postfix ke Prefix
void postfixToPrefix(char *postfix, char *prefix) {
    char infix[MAX];
    postfixToInfix(postfix, infix);
    infixToPrefix(infix, prefix);
}