#include <stdio.h>
#include <string.h>

char findFirstRepeated(char* s) {
    // Array to store whether a character has been seen (26 lowercase letters)
    int seen[26] = {0};

    for (int i = 0; s[i] != '\0'; i++) {
        int index = s[i] - 'a';

        // If the character is already in the 'seen' array, this is the first repeat
        if (seen[index] == 1) {
            return s[i];
        }

        // Mark the character as seen
        seen[index] = 1;
    }

    // No repeated character found
    return '\0'; 
}

int main() {
    char s[100005];
    if (scanf("%s", s) != 1) return 0;

    char result = findFirstRepeated(s);

    if (result == '\0') {
        printf("-1\n");
    } else {
        printf("%c\n", result);
    }

    return 0;
}
