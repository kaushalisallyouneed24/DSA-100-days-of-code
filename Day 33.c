#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1) return -1;
    return stack[top--];
}

// Function to define operator precedence
int precedence(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0;
}

int main() {
    char infix[MAX];
    scanf("%s", infix);
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // 1. If operand, print it
        if (isalnum(ch)) {
            printf("%c", ch);
        }
        // 2. If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }
        // 3. If ')', pop until '(' is found
        else if (ch == ')') {
            char x;
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        }
        // 4. If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                printf("%c", pop());
            }
            push(ch);
        }
    }

    // Pop remaining operators from stack
    while (top != -1) {
        printf("%c", pop());
    }
    printf("\n");

    return 0;
}
