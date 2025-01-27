#pragma once

void print_results(const int LENGTH_OPTIONS[], const int CUTS[],
                            const int VALUES[], const int LENGTH_OPTIONS_SIZE, const int REMAINDER, const int BEST_VALUE);

void input_cut_options(const int LENGTH_OPTIONS_SIZE, int length_options[],
                       int values[], int cuts[]);
