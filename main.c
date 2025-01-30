#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"
#include "rod_cutting.h"

#define INITIAL_SIZE 5

/* main function that takes in the rod length as an argument from the command
line */
int main(int argc, char *argv[]) {
    if (argc != 2 || !sscanf(argv[1], "%d", &argc) ||
        input_rod_length_error_check(argv[1])) {
        printf(
            "Invalid input. Input one integer in this format \"./main "
            "<integer>\". For "
            "example, \"./main 45\".\n");
        return 0;
    }

    const int rod_length         = argc;
    int remainder                = 0;
    int *length_options          = calloc(INITIAL_SIZE, sizeof(int));
    int *values                  = calloc(INITIAL_SIZE, sizeof(int));
    int number_of_length_options = 0;
    int array_size               = INITIAL_SIZE;

    input_cut_options(&length_options, &values, &number_of_length_options,
                      &array_size);

    if (number_of_length_options == 0) {
        printf("No length options were entered.\n");
        return 0;
    }

    int cuts[number_of_length_options];
    memset(cuts, 0, sizeof(cuts));

    printf("cuts: %d\n", cuts[0]);
    int best_value = rod_cutting(rod_length, length_options, values,
                                 number_of_length_options, cuts, &remainder);

    print_results(length_options, cuts, values, number_of_length_options,
                  remainder, best_value);
}
