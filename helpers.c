#include <stdio.h>
#include <stdlib.h>

/* prints the distribution of cuts along with how much value they contributed to
the total, the remainder, and the most value that can be obtained */
void print_results(const int length_options[], const int cuts[],
                   const int values[], const int number_of_options,
                   const int remainder, const int best_value) {
    printf("\nCutting list (<n> @ <size> = <total value>): \n");
    for (int ix = 0; ix < number_of_options; ix++) {
        const int TOTAL_VALUE = (cuts[ix] * values[ix]);
        printf("%d @ %d = %d \n", cuts[ix], length_options[ix], TOTAL_VALUE);
    }

    printf("remainder: %d\n", remainder);
    printf("Value: %d\n", best_value);
}

/* prompts the user to input cut options along with their respective values */
void input_cut_options(int **length_options, int **values,
                       int *number_of_options) {
    int length;
    int value;
    char buffer[100];

    printf(
        "Enter the list of piece prices in the format <length>, "
        "<value> (Ctrl+Z for Windows / Ctrl+D for Linux to end):\n");

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%d, %d", &length, &value) != 2)
            break;

        *length_options =
            realloc(*length_options, (*number_of_options + 1) * sizeof(int));
        *values = realloc(*values, (*number_of_options + 1) * sizeof(int));

        (*length_options)[*number_of_options] = length;
        (*values)[*number_of_options]         = value;
        (*number_of_options)++;
    }
}
