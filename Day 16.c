#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    int visited[n]; // Array to keep track of counted elements
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0; // Initialize all as not visited
    }

    for (int i = 0; i < n; i++) {
        // If this element is already processed, skip it
        if (visited[i] == 1) {
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = 1; // Mark the duplicate as visited
                count++;
            }
        }

        // Print the element and its total count
        printf("%d:%d\n", arr[i], count);
    }

    return 0;
}
