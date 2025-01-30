#include <stdio.h>

/* checks for additional characters after inputting two integers representing
the length and value */
int check_for_additional_characters(const char *buffer) {
    char extra_character;
    return (sscanf(buffer, "%*d, %*d %c", &extra_character) == 1);
}

/* checks if length and value are positive integers */
int validate_length_value_input(const int *length, const int *value) {
    return (*length > 0 && *value > 0);
}
