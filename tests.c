#include <stdio.h>
#include "helpers.h"
#include "rod_cutting.h"

int tests() {
    int length_options[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int values[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int number_of_options = 8;
    int cuts[8];
    int remainder = 0;
    int best_value = rod_cutting(8, length_options, values, number_of_options, cuts, &remainder);
    if (best_value != 22) {
        printf("Test 1 failed\n");
        return 1;
    }
    if (remainder != 0) {
        printf("Test 2 failed\n");
        return 1;
    }
    if (cuts[0] != 2 || cuts[1] != 6) {
        printf("Test 3 failed\n");
        return 1;
    }
    printf("All tests passed\n");
    return 0;
}