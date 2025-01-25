#include <stdio.h>
#include <string.h>

int rod_cutting(const int size, const int lengths[], const int values[],
                const int lengths_size, int cuts[], int *remainder);

int main() {
    int cuts[]             = {0, 0};
    int lengths[]          = {7, 8};
    int values[]           = {5, 7};
    int size               = 26;
    int lengths_array_size = sizeof(lengths) / sizeof(lengths[0]);
    int remainder          = 0;

    int max_value = rod_cutting(size, lengths, values, lengths_array_size, cuts,
                                &remainder);

    printf("Max value: %d\n", max_value);

    printf("Cut distribution: \n");
    for (int ix = 0; ix < lengths_array_size; ix++)
        printf("Length: %d: cuts: %d\n", lengths[ix], cuts[ix]);

    printf("Remainder: %d\n", remainder);
}

/**
 * TODO: fix cut distribution not being properly calculated when there exists a
 * remainder
 */
int rod_cutting(const int size, const int lengths[], const int values[],
                const int lengths_size, int cuts[], int *remainder) {
    if (size == 0)
        return 0;

    int max = 0;  // each path will have its own max value
    int temp_cuts[lengths_size];
    memcpy(temp_cuts, cuts,
           sizeof(temp_cuts));  // copy the cuts so far down this path
    int temp_remainder = size;  // each path will have its own remainder

    for (int i = 0; i < lengths_size; i++) {
        int current_cuts[lengths_size];
        memcpy(current_cuts, cuts, sizeof(current_cuts));

        if (lengths[i] <= size) {
            current_cuts[i]++;
            // printf("currently at index: %d with cuts: %d \n", i,
            // current_cuts[i]);

            int current_remainder = size - lengths[i];
            int val = values[i] + rod_cutting(size - lengths[i], lengths,
                                              values, lengths_size,
                                              current_cuts, &current_remainder);

            // printf("val: %d\n", val);
            // printf("max: %d\n", max);
            if (val > max) {
                max = val;
                memcpy(temp_cuts, current_cuts, sizeof(temp_cuts));
                temp_remainder = current_remainder;
            }
        }
    }

    memcpy(cuts, temp_cuts, sizeof(temp_cuts));
    *remainder = temp_remainder;

    return max;
}
