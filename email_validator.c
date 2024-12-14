#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValidEmail(char s[]) {
    int atCount = 0, dotCount = 0;
    int atIndex = -1, dotIndex = -1;

    // Check for '@' and '.' positions
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '@') {
            atCount++;
            atIndex = i;
        }
        if (s[i] == '.' && atIndex != -1 && i > atIndex) { // '.' after '@'
            dotCount++;
            dotIndex = i;
        }
    }

    // Validation rules
    if (atCount != 1) {
        printf("Invalid: There must be exactly one '@' symbol.\n");
        return false;
    }
    if (dotCount < 1) {
        printf("Invalid: There must be at least one '.' after the '@'.\n");
        return false;
    }
    if (dotIndex - atIndex <= 1) {
        printf("Invalid: '.' must not immediately follow '@'.\n");
        return false;
    }
    if (dotIndex == strlen(s) - 1) {
        printf("Invalid: '.' must not be the last character.\n");
        return false;
    }

    return true;
}

int main() {
    char email[100];
    printf("Enter email id: ");
    scanf("%s", email);

    if (isValidEmail(email)) {
        printf("Valid email address.\n");
    } else {
        printf("Invalid email address.\n");
    }

    return 0;
}
