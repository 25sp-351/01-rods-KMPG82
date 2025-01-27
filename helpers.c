#include <stdio.h>

/* prints the distribution of cuts along with how much value they contributed to
the total */
void print_cut_distribution(const int LENGTH_OPTIONS[], const int CUTS[],
                            const int VALUES[], const int LENGTH_OPTIONS_SIZE) {
    printf("\nCutting list (<n> @ <size> = <total value>): \n");
    for (int ix = 0; ix < LENGTH_OPTIONS_SIZE; ix++) {
        const int TOTAL_VALUE = (CUTS[ix] * VALUES[ix]);
        printf("%d @ %d = %d \n", CUTS[ix], LENGTH_OPTIONS[ix], TOTAL_VALUE);
    }
}

/* prompts the user to input cut options along with their respective values */
void input_cut_options(const int LENGTH_OPTIONS_SIZE, int length_options[],
                       int values[], int cuts[]) {
    for (int ix = 0; ix < LENGTH_OPTIONS_SIZE; ix++) {
        printf(
            "Enter the list of piece prices one at a time as shown (<length> "
            "<value>): ");
        scanf("%d %d", &length_options[ix], &values[ix]);
        cuts[ix] = 0;
    }
}
