#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"
#include "rod_cutting.h"

/* main function that takes in the rod length as an argument from the command
line */
int main(int argc, char *argv[]) {
    const int ROD_LENGTH  = atoi(argv[1]);
    int remainder         = 0;
    int *length_options   = NULL;
    int *values           = NULL;
    int number_of_options = 0;

    input_cut_options(&length_options, &values, &number_of_options);

    int cuts[number_of_options];
    memset(cuts, 0, sizeof(cuts));

    int best_value = rod_cutting(ROD_LENGTH, length_options, values,
                                 number_of_options, cuts, &remainder);

    print_results(length_options, cuts, values, number_of_options, remainder,
                  best_value);
}
