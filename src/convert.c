#include <string.h>
#include <stdio.h>
#include "convert.h"
#include <regex.h>

/* Regex string for determining validity of roman numerals */
static char regex_string[] = "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$";

/**
 * Determines if a passed argument is a valid roman numeral.
 * 		Returns 0 if false
 * 		Returns 1 if true
 */
int valid_roman_numeral(char * numeral){

	/* Create and compile a regex for the valid numeral string */
	regex_t regex_comp;
	regcomp(&regex_comp, regex_string, REG_EXTENDED);

	/* Determine if the passed numeral is valid */
	int result = regexec(&regex_comp, numeral, (size_t) 0, NULL, 0);

	/* free up resources */
	regfree(&regex_comp);

	/* Return results */
	if (result == REG_NOMATCH) {
		return 0;
	}
	return 1;
}

/**
 * Takes a single roman numeral digit as an argument and returns its integer equivalent.
 */
int roman_digit_to_integer(char numeral)
{
  switch (numeral) {
	  case 'I': return 1;
	  case 'V': return 5;
	  case 'X': return 10;
	  case 'L': return 50;
	  case 'C': return 100;
	  case 'D': return 500;
	  case 'M': return 1000;
	  default: return 0;
  }
}

/**
 * Converts a Roman numeral to its arabic equivalent or returns 0 if invalid.
 */
int convert_roman_to_arabic(char * numeral){
	int output = 0;
	int numeral_length = strlen(numeral);
	for (int i = 0; i < numeral_length; i++) {
		if (i + 1 < numeral_length && roman_digit_to_integer(numeral[i]) < roman_digit_to_integer(numeral[i + 1])) {
			output -= roman_digit_to_integer(numeral[i]);
		} else {
			output += roman_digit_to_integer(numeral[i]);
		}
	}
	return output;
}
