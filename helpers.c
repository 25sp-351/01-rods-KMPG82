#include <stdio.h>

/* prints the distribution of cuts along with how much value they contributed to
the total */
void print_cut_distribution(const int length_options[], const int cuts[],
                            const int values[], const int length_options_size) {
    printf("\nCutting list (<n> @ <size> = <total value>): \n");
    for (int ix = 0; ix < length_options_size; ix++) {
        int value_of_cuts = (cuts[ix] * values[ix]);
        printf("%d @ %d = %d \n", cuts[ix], length_options[ix], value_of_cuts);
    }
}

/* prompts the user to input cut options along with their respective values */
void input_cut_options(int length_options[], int values[], int cuts[],
                       const int length_options_size) {
    for (int ix = 0; ix < length_options_size; ix++) {
        printf(
            "Enter the list of piece prices one at a time as shown (<length> "
            "<value>): ");
        scanf("%d %d", &length_options[ix], &values[ix]);
        cuts[ix] = 0;
    }
}
