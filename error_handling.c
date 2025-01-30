#include <stdio.h>

/* checks for additional characters after inputting two integers representing
the length and value */
int length_value_additional_characters(const char *buffer) {
    char extra_character;
    return (sscanf(buffer, "%*d, %*d %c", &extra_character) == 1);
}

/* checks if length and value are positive integers */
int negative_length_value(const int *length, const int *value) {
    return (*length > 0 && *value > 0);
}

/* checks for additional characters after inputting an integer that represents
the rod length */
int rod_length_additional_characters(const char *argv) {
    char extra_character;
    return (sscanf(argv, "%*d %c", &extra_character) == 1);
}

/* checks if rod length is a positive integer */
int negative_rod_length(const int *rod_length) {
    return (*rod_length < 0);
}
