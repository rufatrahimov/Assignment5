
#include <stdio.h>

// Function to invert the case of all letters in a string
void invert(char dst[], const char src[]) {
    int i = 0;

    // Continue until the end of the source string
    while (src[i] != '\0') {

        // If the character is uppercase (A-Z), convert it to lowercase
        if (src[i] >= 'A' && src[i] <= 'Z') {
            dst[i] = src[i] + 32;
        }

        // If the character is lowercase (a-z), convert it to uppercase
        else if (src[i] >= 'a' && src[i] <= 'z') {
            dst[i] = src[i] - 32;
        }

        // Keep numbers, spaces, and special characters unchanged
        else {
            dst[i] = src[i];
        }

        i++;
    }

    // Add the null character to mark the end of the destination string
    dst[i] = '\0';
}

int main() {
    char result[100];

    // Call the invert function
    invert(result, "Hello World There!");

    // Print the resulting string
    printf("%s\n", result);

    return 0;
}
