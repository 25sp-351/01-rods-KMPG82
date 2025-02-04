#pragma once

void print_results(const int *length_options, const int *cuts,
                   const int *values, int number_of_length_options,
                   int remainder, int best_value);

void input_cut_options(int *length_options, int *values,
                       int *number_of_length_options, int *array_size);

void sort(int *length_options, int *values, int number_of_length_options);
