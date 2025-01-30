#include <stdio.h>
#include <stdlib.h>

/* prints the distribution of cuts along with how much value they contributed to
the total, the remainder, and the most value that can be obtained */
void print_results(const int length_options[], const int cuts[],
                   const int values[], const int number_of_length_options,
                   const int remainder, const int best_value) {
    printf("\nCutting list (<n> @ <size> = <total value>):\n");
    for (int ix = 0; ix < number_of_length_options; ix++) {
        const int total_value = (cuts[ix] * values[ix]);
        printf("%d @ %d = %d\n", cuts[ix], length_options[ix], total_value);
    }

    printf("Remainder: %d\n", remainder);
    printf("Value: %d\n", best_value);
}

/* checks for additional characters after inputting two integers representing
the length and value */
int input_cut_options_error_check(const char *buffer) {
    char extra_character;
    return (sscanf(buffer, "%*d, %*d %c", &extra_character) == 1);
}

/* prompts the user to input cut options along with their respective values */
void input_cut_options(int **length_options, int **values,
                       int *number_of_length_options, int *array_size) {
    int length;
    int value;
    char buffer[100];

    printf(
        "Enter the list of piece prices in the format \"<length>, "
        "<value>\" (Ctrl+Z for Windows / Ctrl+D for Linux to end):\n");

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%d, %d", &length, &value) != 2 ||
            input_cut_options_error_check(buffer)) {
            printf(
                "Invalid input. Only enter integers in the specified format. "
                "For example, \"24, 5\".\n");
            continue;
        }

        if (*number_of_length_options == *array_size) {
            (*array_size) *= 2;

            *length_options =
                realloc(*length_options, (*array_size) * sizeof(int));
            *values = realloc(*values, (*array_size) * sizeof(int));
        }

        (*length_options)[*number_of_length_options] = length;
        (*values)[*number_of_length_options]         = value;
        (*number_of_length_options)++;
    }
}

/* checks for additional characters after inputting an integer that represents
the rod length */
int input_rod_length_error_check(const char *argv) {
    char extra_character;
    return (sscanf(argv, "%*d %c", &extra_character) == 1);
}
