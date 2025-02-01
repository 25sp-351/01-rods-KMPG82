#pragma once

int rod_cutting(const int rod_length, const int *length_options,
                const int *length_values, const int number_of_options,
                int *cuts, int *remainder);
