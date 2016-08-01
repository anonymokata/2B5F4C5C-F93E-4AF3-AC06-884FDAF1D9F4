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
