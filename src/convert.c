#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "convert.h"
#include <regex.h>

/* Regex string for determining validity of roman numerals */
static const char regex_string[] = "^M{0,3}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$";

/* Limits */
static const int MAX_LENGTH = 16;
static const int MAX_NUMERAL_VALUE = 3999;
static const int MIN_NUMERAL_VALUE = 1;

/* Conversion table for converting from arabic to roman */
typedef struct {
	const char *	numeral;
	int 			value;
} conversion_struct;

static const conversion_struct CONVERSION_TABLE[13] = {
	{ .numeral = "M", .value = 1000 },
	{ .numeral = "CM", .value = 900 },
	{ .numeral = "D", .value = 500 },
	{ .numeral = "CD", .value = 400 },
	{ .numeral = "C", .value = 100 },
	{ .numeral = "XC", .value = 90 },
	{ .numeral = "L", .value = 50 },
	{ .numeral = "XL", .value = 40 },
	{ .numeral = "X", .value = 10 },
	{ .numeral = "IX", .value = 9 },
	{ .numeral = "V", .value = 5 },
	{ .numeral = "IV", .value = 4 },
	{ .numeral = "I", .value = 1 }
};


/**
 * Determines if a passed argument is a valid roman numeral.
 */
int valid_roman_numeral(const char *numeral){

	/* Verify parameter has a value and is within max length */
	if(numeral == NULL || strlen(numeral) > MAX_LENGTH || numeral[0] == '\0'){
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
int roman_digit_to_integer(const char numeral){
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
int convert_roman_to_arabic(const char *numeral){

	/* Verify that the passed argument is a valid numeral */
	if(valid_roman_numeral(numeral) == 0){
		return 0;
	}

	/* Convert from roman numeral to arabic number form */
	int numeral_length = strlen(numeral);
	int output = 0;
	for (int i = 0; i < numeral_length; i++) {
		char letter = numeral[i];
		if (i + 1 < numeral_length && roman_digit_to_integer(numeral[i]) < roman_digit_to_integer(numeral[i + 1])) {
			output -= roman_digit_to_integer(letter);
		} else {
			output += roman_digit_to_integer(letter);
		}
	}
	return output;
}

/**
 * Converts the passed arabic number into a Roman numeral returned via the passed reference.
 */
void convert_arabic_to_roman(char * buffer, int buffer_len, int num){

	/* validate arguments */
	if(buffer == NULL || buffer_len != MAX_LENGTH || num < MIN_NUMERAL_VALUE || num > MAX_NUMERAL_VALUE){
		return;
	}

	/* Initialize buffer */
	memset(buffer, '\0', buffer_len);


	/* get size of conversion table */
	int len = sizeof(CONVERSION_TABLE) / sizeof(conversion_struct);

	/* convert values */
	for(int i = 0; i < len; i++) {
		const conversion_struct table = CONVERSION_TABLE[i];
		while(num >= table.value) {
			strcat(buffer, table.numeral);
			num -= table.value;
		}
	}
}
