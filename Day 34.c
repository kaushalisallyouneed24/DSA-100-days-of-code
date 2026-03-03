#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Node structure for the Linked List Stack
struct Node {
    int data;
    struct Node* next;
};

// Push operation
void push(struct Node** top, int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *top;
    *top = newNode;
}

// Pop operation
int pop(struct Node** top) {
    if (*top == NULL) return 0;
    struct Node* temp = *top;
    int val = temp->data;
    *top = (*top)->next;
    free(temp);
    return val;
}

int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i] != '\0'; i++) {
        // If operand, push to stack (convert char to int)
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0');
        } 
        // If operator, pop two and operate
        else {
            int val2 = pop(&stack);
            int val1 = pop(&stack);
            
            switch (exp[i]) {
                case '+': push(&stack, val1 + val2); break;
                case '-': push(&stack, val1 - val2); break;
                case '*': push(&stack, val1 * val2); break;
                case '/': push(&stack, val1 / val2); break;
            }
        }
    }
    return pop(&stack);
}

int main() {
    char exp[100];
    if (scanf("%s", exp) != 1) return 0;

    printf("%d\n", evaluatePostfix(exp));

    return 0;
}
