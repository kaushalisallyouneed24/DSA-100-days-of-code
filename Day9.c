#include <stdio.h>
#include <string.h>

int main() {
    char str[1000]; // Assuming a maximum length of 999 characters

    // Read the string input (stops at whitespace)
    if (scanf("%s", str) != 1) return 0;

    int length = strlen(str);
    int left = 0;
    int right = length - 1;

    // Perform the mirror (reversal) operation in-place
    while (left < right) {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }

    // Print the mirrored string
    printf("%s\n", str);

    return 0;
}
