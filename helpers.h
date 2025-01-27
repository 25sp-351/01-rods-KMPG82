#pragma once

void print_results(const int LENGTH_OPTIONS[], const int CUTS[],
                   const int VALUES[], const int NUMBER_OF_OPTIONS,
                   const int REMAINDER, const int BEST_VALUE);

void input_cut_options(int **length_options, int **values,
                       int *number_of_options);
