#include <stdio.h>
#include <string.h>

char firstNonRepeating(char* s) {
    int count[26] = {0};
    int n = strlen(s);

    // Step 1: Build the frequency map
    for (int i = 0; i < n; i++) {
        count[s[i] - 'a']++;
    }

    // Step 2: Find the first character with a frequency of 1
    for (int i = 0; i < n; i++) {
        if (count[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[100005];
    if (scanf("%s", s) != 1) return 0;

    char result = firstNonRepeating(s);
    printf("%c\n", result);

    return 0;
}
