#include <stdio.h>
#include <string.h>

/* recursive function that explores all possible options of cutting a rod of a
given length and returns the maximum value that can be obtained with a given set
of length options and their values */
int rod_cutting(const int ROD_LENGTH, const int LENGTH_OPTIONS[],
                const int LENGTH_VALUES[], const int LENGTH_OPTIONS_SIZE,
                int cuts[], int *remainder) {
    if (ROD_LENGTH == 0)
        return 0;

    int best_value     = 0;
    int best_remainder = ROD_LENGTH;
    int best_cuts[LENGTH_OPTIONS_SIZE];
    memcpy(best_cuts, cuts, sizeof(best_cuts));

    for (int ix = 0; ix < LENGTH_OPTIONS_SIZE; ix++) {
        int current_cuts[LENGTH_OPTIONS_SIZE];
        memcpy(current_cuts, cuts, sizeof(current_cuts));

        if (LENGTH_OPTIONS[ix] <= ROD_LENGTH) {
            current_cuts[ix]++;

            int current_remainder = (ROD_LENGTH - LENGTH_OPTIONS[ix]);
            int current_value     = (LENGTH_VALUES[ix] +
                                 rod_cutting(current_remainder, LENGTH_OPTIONS,
                                                 LENGTH_VALUES, LENGTH_OPTIONS_SIZE,
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
