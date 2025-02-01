#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "error_handling.h"
#include "helpers.h"
#include "rod_cutting.h"

#define INITIAL_SIZE 5

/* main function that takes in the rod length as an argument from the command
line */
int main(int argc, char *argv[]) {
    if (argc != 2 || !sscanf(argv[1], "%d", &argc) ||
        rod_length_additional_characters(argv[1]) ||
        negative_rod_length(&argc)) {
        printf(
            "Invalid input. Input one positive integer in this format \"./main "
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
        printf("\nInvalid input. Enter at least one length and value pair.\n");
        return 0;
    }

    sort(length_options, values, number_of_length_options);

    // for (int ix = 0; ix < number_of_length_options; ix++)
    //     printf("%d, %d\n", length_options[ix], values[ix]);

    int cuts[number_of_length_options];
    memset(cuts, 0, sizeof(cuts));

    int best_value = rod_cutting(rod_length, length_options, values,
                                 number_of_length_options, cuts, &remainder);

    printf("\n");
    print_results(length_options, cuts, values, number_of_length_options,
                  remainder, best_value);
}
