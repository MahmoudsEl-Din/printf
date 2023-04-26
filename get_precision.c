#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(char *format, int *i, int *list) {
  int precision = 0;
  int num_digits;

  // Calculate the number of digits after the decimal point in the formatted string.
  for (num_digits = 0; format[num_digits] != '\0'; num_digits++) {
    if (format[num_digits] == '.') {
      break;
    }
  }

  // Iterate through the list of arguments, and for each argument, calculate the number of digits after the decimal point.
  for (int j = 0; j < *i; j++) {
    num_digits = 0;
    while (list[j] != '\0' && isdigit(list[j])) {
      num_digits++;
      j++;
    }
    precision = max(precision, num_digits);
  }

  return precision;
}
