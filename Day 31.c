#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1) {
        // Stack Overflow - not explicitly required by your prompt but good practice
        return;
    }
    stack[++top] = value;
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("%d\n", stack[top--]);
    }
}

void display() {
    if (top == -1) {
        return;
    }
    for (int i = top; i >= 0; i--) {
        printf("%d%s", stack[i], (i == 0) ? "" : " ");
    }
    printf("\n");
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            int val;
            scanf("%d", &val);
            push(val);
        } else if (choice == 2) {
            pop();
        } else if (choice == 3) {
            display();
        }
    }

    return 0;
}
