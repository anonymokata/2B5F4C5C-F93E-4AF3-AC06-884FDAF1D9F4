#include <string.h>
#include <stdio.h>
#include "convert.h"
#include <regex.h>

/* Regex string for determining validity of roman numerals */
static const char regex_string[] = "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$";

/* Limits */
static const int MAX_LENGTH = 16;
static const int MAX_NUMERAL_VALUE = 3999;
static const int MIN_NUMERAL_VALUE = 1;

/**
 * Determines if a passed argument is a valid roman numeral.
 */
int valid_roman_numeral(const char *numeral){

	/* Verify parameter has a value */
	if(numeral == NULL || numeral[0] == '\0'){
		return 0;
	}

	/* Verify that the passed numeral is within max length */
	char roman_numeral[MAX_LENGTH+1];
	memset(roman_numeral, '\0', MAX_LENGTH+1);
	strncpy(roman_numeral, numeral, MAX_LENGTH+1);
	if(roman_numeral[MAX_LENGTH+1] != '\0'){
		return 0;
	}

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
int roman_digit_to_integer(const char *numeral){
	const char num = numeral[0];
	switch (num) {
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
int convert_roman_to_arabic(const char *numeral){
	//TODO
	return 0;
}

/**
 * Converts the passed arabic number into a Roman numeral returned via the passed reference.
 */
void convert_arabic_to_roman(const int num, char *roman_num){
	//TODO
}
