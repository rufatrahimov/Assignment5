
#include <stdio.h>
#include <stdbool.h>

// Function to validate a time string
bool isValidTime(const char str[]) {

    int i = 0;
    int hour = 0;
    int minute = 0;
    int digits = 0;

    // Read the hour (1 or 2 digits)
    while (str[i] >= '0' && str[i] <= '9') {
        hour = hour * 10 + (str[i] - '0');
        digits++;
        i++;
    }

    // Hour must contain 1 or 2 digits
    if (digits < 1 || digits > 2)
        return false;

    // Check for colon
    if (str[i] != ':')
        return false;

    i++;

    // Read the minutes (exactly 2 digits)
    if (str[i] < '0' || str[i] > '9')
        return false;

    minute = (str[i] - '0') * 10;

    i++;

    if (str[i] < '0' || str[i] > '9')
        return false;

    minute += str[i] - '0';

    i++;

    // Check hour and minute ranges
    if (hour > 23 || minute > 59)
        return false;

    // If the string ends here, the time is valid
    if (str[i] == '\0')
        return true;

    // Otherwise, exactly one whitespace must follow
    if (str[i] != ' ')
        return false;

    i++;

    // Check AM or PM (case insensitive)
    char first = str[i];
    char second = str[i + 1];

    if (!((first == 'A' || first == 'a' ||
           first == 'P' || first == 'p') &&
          (second == 'M' || second == 'm')))
        return false;

    // Check that nothing comes after AM/PM
    if (str[i + 2] != '\0')
        return false;

    // AM/PM format must use hours from 1 to 12
    if (hour < 1 || hour > 12)
        return false;

    return true;
}

int main() {

    printf("%d\n", isValidTime("13:45"));    // 1 (true)
    printf("%d\n", isValidTime("43:45"));    // 0 (false)
    printf("%d\n", isValidTime("1:45 PM")); // 1 (true)
    printf("%d\n", isValidTime("01:45 pm"));// 1 (true)
    printf("%d\n", isValidTime("13:30 am"));// 0 (false)
    printf("%d\n", isValidTime("3:30am"));  // 0 (false)

    return 0;
}
