
#include <stdio.h>

int countDistinctVowels(const char str[]) {
    // Array to track whether each vowel has appeared
    int a = 0, e = 0, i = 0, o = 0, u = 0;

    int count = 0;
    int j = 0;

    // Check every character in the string
    while (str[j] != '\0') {

        // Convert uppercase vowels by checking both cases
        switch (str[j]) {

            case 'a':
            case 'A':
                if (a == 0) {
                    count++;
                    a = 1;
                }
                break;

            case 'e':
            case 'E':
                if (e == 0) {
                    count++;
                    e = 1;
                }
                break;

            case 'i':
            case 'I':
                if (i == 0) {
                    count++;
                    i = 1;
                }
                break;

            case 'o':
            case 'O':
                if (o == 0) {
                    count++;
                    o = 1;
                }
                break;

            case 'u':
            case 'U':
                if (u == 0) {
                    count++;
                    u = 1;
                }
                break;
        }

        j++;
    }

    // Return the number of distinct vowels
    return count;
}

int main() {

    char str[] = "Hello Love Earth";

    printf("Number of distinct vowels: %d\n",
           countDistinctVowels(str));

    return 0;
}
