#include <stdio.h>
#include <stdlib.h>
#include "rod_cutting.h"
#include "helpers.h"

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
    printf("Remainder (<length>): %d\n", remainder);
    printf("Value (<total value>): %d\n", best_value);
}