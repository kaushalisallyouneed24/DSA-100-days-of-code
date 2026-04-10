#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparison function for qsort to sort strings alphabetically
int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    // Allocate memory for pointers to strings
    char** names = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        names[i] = (char*)malloc(101 * sizeof(char)); // Assuming max name length is 100
        scanf("%s", names[i]);
    }

    // 1. Sort names lexicographically
    qsort(names, n, sizeof(char*), compareStrings);

    char* winner = names[0];
    int maxVotes = 0;
    int currentVotes = 1;

    // 2. Linear scan to count frequencies
    for (int i = 1; i < n; i++) {
        if (strcmp(names[i], names[i - 1]) == 0) {
            currentVotes++;
        } else {
            // Check if previous candidate was the winner
            if (currentVotes > maxVotes) {
                maxVotes = currentVotes;
                winner = names[i - 1];
            }
            currentVotes = 1; // Reset for the new name
        }
    }

    // Final check for the last block of names
    if (currentVotes > maxVotes) {
        maxVotes = currentVotes;
        winner = names[n - 1];
    }

    // 3. Print result
    printf("%s %d\n", winner, maxVotes);

    // Cleanup
    for (int i = 0; i < n; i++) free(names[i]);
    free(names);

    return 0;
}
