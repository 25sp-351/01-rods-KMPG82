#pragma once

void print_results(const int length_options[], const int cuts[],
                   const int values[], const int number_of_options,
                   const int remainder, const int best_value);

void input_cut_options(int **length_options, int **values,
                       int *number_of_options);
