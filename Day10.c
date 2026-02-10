#include <stdio.h>
#include <string.h>

int main() {
    char str[1000]; // Buffer for the input string

    // Read the string (assumes no spaces)
    if (scanf("%s", str) != 1) return 0;

    int length = strlen(str);
    int left = 0;
    int right = length - 1;
    int isPalindrome = 1; // Assume it is a palindrome initially

    while (left < right) {
        // If characters at current pointers don't match
        if (str[left] != str[right]) {
            isPalindrome = 0; // Not a palindrome
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
