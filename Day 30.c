#include <stdio.h>
#include <stdlib.h>

struct Term {
    int coeff;
    int exp;
    struct Term* next;
};

// Function to create a new term node
struct Term* createTerm(int c, int e) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    newTerm->coeff = c;
    newTerm->exp = e;
    newTerm->next = NULL;
    return newTerm;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;

    struct Term *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        int c, e;
        scanf("%d %d", &c, &e);

        struct Term* newTerm = createTerm(c, e);
        if (head == NULL) {
            head = tail = newTerm;
        } else {
            tail->next = newTerm;
            tail = newTerm;
        }
    }

    // Traversal and Formatting
    struct Term* temp = head;
    while (temp != NULL) {
        // Print the term
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }

        // Print " + " if there is another term following
        if (temp->next != NULL) {
            printf(" + ");
        }
        
        temp = temp->next;
    }
    printf("\n");

    // Memory Cleanup
    while (head != NULL) {
        struct Term* toDelete = head;
        head = head->next;
        free(toDelete);
    }

    return 0;
}
