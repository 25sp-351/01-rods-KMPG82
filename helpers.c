#include <stdio.h>
#include <stdlib.h>

#include "error_handling.h"
#define BUFFER_SIZE 100
#define SIZE_MULTIPLIER 2

/* prints the distribution of cuts along with how much value they contributed to
the total, the remainder, and the most value that can be obtained */
void print_results(const int *length_options, const int *cuts,
                   const int *values, const int number_of_length_options,
                   const int remainder, const int best_value) {
    for (int ix = 0; ix < number_of_length_options; ix++) {
        if (cuts[ix] != 0) {
            const int total_value = (cuts[ix] * values[ix]);
            printf("%d @ %d = %d\n", cuts[ix], length_options[ix], total_value);
        }
    }

    printf("Remainder: %d\n", remainder);
    printf("Value: %d\n", best_value);
}

/* handles input piece options along with their respective values */
void input_cut_options(int *length_options, int *values,
                       int *number_of_length_options, int *array_size) {
    int length;
    int value;
    char buffer[BUFFER_SIZE];

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%d, %d", &length, &value) != 2 ||
            length_value_additional_characters(buffer) ||
            negative_length_value(length, value) == 0) {
            printf(
                "Invalid input. Only enter positive integers in the specified "
                "format. "
                "For example, \"24, 5\".\n");
            continue;
        }

        if (number_of_length_options == array_size) {
            *array_size *= SIZE_MULTIPLIER;

            length_options = realloc(length_options, *array_size * sizeof(int));
            values         = realloc(values, *array_size * sizeof(int));
        }

        length_options[*number_of_length_options] = length;
        values[*number_of_length_options]         = value;
        (*number_of_length_options)++;
    }
}

/* uses a selection sort algorithm to sort the pieces in descending order based
on value, then based on length if values are the same */
void sort(int *length_options, int *values, int number_of_length_options) {
    for (int ix = 0; ix < number_of_length_options; ix++) {
        for (int jx = ix + 1; jx < number_of_length_options; jx++) {
            if (values[ix] < values[jx]) {
                int temp           = values[ix];
                values[ix]         = values[jx];
                values[jx]         = temp;

                temp               = length_options[ix];
                length_options[ix] = length_options[jx];
                length_options[jx] = temp;
                continue;
            }

            if (values[ix] == values[jx]) {
                if (length_options[ix] < length_options[jx]) {
                    int temp           = length_options[ix];
                    length_options[ix] = length_options[jx];
                    length_options[jx] = temp;
                }
            }
        }
    }
}
