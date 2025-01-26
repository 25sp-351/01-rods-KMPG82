#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rod_cutting(const int size, const int length_options[], const int values[],
                const int length_options_size, int cuts[], int *remainder);

void print_cut_distribution(const int length_options[], const int cuts[],
                            const int values[], const int length_options_size);

void input_cut_options(int length_options[], int values[], int cuts[],
                       const int length_options_size);

/* main function that takes in the rod length as an argument from the command
line */
int main(int argc, char *argv[]) {
    int rod_length          = atoi(argv[1]);
    int remainder           = 0;
    int length_options_size = 0;

    printf("Enter how many piece options there are: ");
    scanf("%d", &length_options_size);

    int length_options[length_options_size];
    int values[length_options_size];
    int cuts[length_options_size];

    input_cut_options(length_options, values, cuts, length_options_size);

    int best_value = rod_cutting(rod_length, length_options, values,
                                 length_options_size, cuts, &remainder);

    print_cut_distribution(length_options, cuts, values, length_options_size);
    printf("Remainder: %d\n", remainder);
    printf("Value: %d\n", best_value);
}

/* recursive function that explores all possible options of cutting a rod of a
given length and returns the maximum value that can be obtained with a given set
of length options and their values */
int rod_cutting(const int rod_length, const int length_options[],
                const int length_values[], const int length_options_size,
                int cuts[], int *remainder) {
    if (rod_length == 0)
        return 0;

    int best_value     = 0;
    int best_remainder = rod_length;
    int best_cuts[length_options_size];
    memcpy(best_cuts, cuts, sizeof(best_cuts));

    for (int ix = 0; ix < length_options_size; ix++) {
        int current_cuts[length_options_size];
        memcpy(current_cuts, cuts, sizeof(current_cuts));

        if (length_options[ix] <= rod_length) {
            current_cuts[ix]++;

            int current_remainder = rod_length - length_options[ix];
            int current_value     = length_values[ix] +
                                rod_cutting(current_remainder, length_options,
                                            length_values, length_options_size,
                                            current_cuts, &current_remainder);

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

/* prints the distribution of cuts along with how much value they contributed to
the total */
void print_cut_distribution(const int length_options[], const int cuts[],
                            const int values[], const int length_options_size) {
    printf("\nCutting list: \n");
    for (int ix = 0; ix < length_options_size; ix++) {
        int value_of_cuts = cuts[ix] * values[ix];
        printf("%d @ %d = %d \n", length_options[ix], cuts[ix], value_of_cuts);
    }
}

/* prompts the user to input cut options along with their respective values */
void input_cut_options(int length_options[], int values[], int cuts[],
                       const int length_options_size) {
    for (int ix = 0; ix < length_options_size; ix++) {
        printf(
            "Enter the list of piece prices one at a time as shown "
            "(<length> <value>): ");
        scanf("%d %d", &length_options[ix], &values[ix]);
        cuts[ix] = 0;
    }
}
