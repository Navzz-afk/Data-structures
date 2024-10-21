#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int isEmpty(int* top) {
    return *top == -1;
}

int isFull(int* top) {
    return *top == MAX - 1;
}

char peek(char stk[], int* top) {
    return stk[*top];
}

char pop(char stk[], int* top) {
    if (isEmpty(top))
        return -1;

    char ch = stk[*top];
    (*top)--;
    return ch;
}

void push(char stk[], int* top, char oper) {
    if (isFull(top))
        printf("Stack Full!!!!\n");
    else {
        (*top)++;
        stk[*top] = oper;
    }
}

int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
    return -1;
}

void covertInfixToPostfix(char* expression, char stk[], int* top) {
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i) {
        if (checkIfOperand(expression[i]))
            expression[++j] = expression[i];
        else if (expression[i] == '(')
            push(stk, top, expression[i]);
        else if (expression[i] == ')') {
            while (!isEmpty(top) && peek(stk, top) != '(')
                expression[++j] = pop(stk, top);
            if (!isEmpty(top) && peek(stk, top) != '(')
                return;
            else
                pop(stk, top);
        } else {
            while (!isEmpty(top) && precedence(expression[i]) <= precedence(peek(stk, top)))
                expression[++j] = pop(stk, top);
            push(stk, top, expression[i]);
        }
    }

    while (!isEmpty(top))
        expression[++j] = pop(stk, top);

    expression[++j] = '\0';
    printf("%s\n", expression);
}

int main() {
    char stk[MAX];
    int top = -1;  // Stack pointer initialized to -1

    char expression[20];
    printf("Enter expression\n");
    fgets(expression, sizeof(expression), stdin);  // Using fgets instead of gets to avoid buffer overflow

    covertInfixToPostfix(expression, stk, &top);
    return 0;
}
