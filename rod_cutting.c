#include <stdio.h>
#include <string.h>

/* recursive function that explores all possible options of cutting a rod of a
given length and returns the maximum value that can be obtained with a given set
of length options and their values */
int rod_cutting(const int ROD_LENGTH, const int LENGTH_OPTIONS[],
                const int LENGTH_VALUES[], const int NUMBER_OF_OPTIONS,
                int cuts[], int *remainder) {
    if (ROD_LENGTH == 0)
        return 0;

    // for (int i = 0; i < NUMBER_OF_OPTIONS; i++)
    // {
    //     printf("LENGTH_OPTIONS[%d]: %d\n", i, LENGTH_OPTIONS[i]);
    // }

    int best_value     = 0;
    int best_remainder = ROD_LENGTH;
    int best_cuts[NUMBER_OF_OPTIONS];
    memcpy(best_cuts, cuts, sizeof(best_cuts));

    for (int ix = 0; ix < NUMBER_OF_OPTIONS; ix++) {
        int current_cuts[NUMBER_OF_OPTIONS];
        memcpy(current_cuts, cuts, sizeof(current_cuts));

        if (LENGTH_OPTIONS[ix] <= ROD_LENGTH) {
            current_cuts[ix]++;

            // printf("ROD_LENGTH: %d, LENGTH_OPTIONS[%d]: %d\n", ROD_LENGTH,
            // ix, LENGTH_OPTIONS[ix]);
            int current_remainder = (ROD_LENGTH - LENGTH_OPTIONS[ix]);
            int current_value     = (LENGTH_VALUES[ix] +
                                 rod_cutting(current_remainder, LENGTH_OPTIONS,
                                                 LENGTH_VALUES, NUMBER_OF_OPTIONS,
                                                 current_cuts, &current_remainder));

            if (current_value > best_value) {
                best_value = current_value;
                memcpy(best_cuts, current_cuts, sizeof(best_cuts));
                best_remainder = current_remainder;
            }
        }
    }

    memcpy(cuts, best_cuts, sizeof(best_cuts));
    *remainder = best_remainder;

    return best_value;
}
