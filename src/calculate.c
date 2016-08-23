#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "calculate.h"
#include "convert.h"


/* Limits */
static const int MAX_LENGTH = 16;
static const int MAX_NUMERAL_VALUE = 3999;
static const int MIN_NUMERAL_VALUE = 1;


/**
 * Adds two roman numerals and sets result to the resultant of the addition.
 */
void addition(const char *first_arg, const char *second_arg, char *result, const int buffer_len){

	/* Validate arguments */
	if(first_arg == NULL || second_arg == NULL || result == NULL || buffer_len > MAX_LENGTH){
		return;
	}

	/* Initialize buffer */
	memset(result, '\0', buffer_len);

	/* Convert arguments and perform operation */
	int first_int = convert_roman_to_arabic(first_arg);
	int second_int = convert_roman_to_arabic(second_arg);
	int resultant = first_int + second_int;

	/* Check that both were valid numerals and that the result of the operation lies within the valid range */
	if(first_int < MIN_NUMERAL_VALUE ||
			first_int > MAX_NUMERAL_VALUE ||
			second_int < MIN_NUMERAL_VALUE ||
			second_int > MAX_NUMERAL_VALUE ||
			resultant > MAX_NUMERAL_VALUE){
		return;
	}

	/* Convert resultant back to numeral form */
	convert_arabic_to_roman(result, buffer_len, resultant);

	/* Verify that result is a valid roman numeral */
	if(valid_roman_numeral(result) == 0){
		memset(result, '\0', buffer_len);
	}
}

/**
 * Subtracts the second argument from the first of two roman numerals and sets result to the resultant of the subtraction.
 */
void subtraction(const char *first_arg, const char *second_arg, char *result, const int buffer_len){

	/* Validate arguments */
	if(first_arg == NULL || second_arg == NULL || result == NULL || buffer_len > MAX_LENGTH){
		return;
	}

	/* Initialize buffer */
	memset(result, '\0', buffer_len);

	/* Convert arguments and perform operation */
	int first_int = convert_roman_to_arabic(first_arg);
	int second_int = convert_roman_to_arabic(second_arg);
	int resultant = first_int - second_int;

	/* Check that both were valid numerals and that the result of the operation lies within the valid range */
	if(first_int < MIN_NUMERAL_VALUE ||
			first_int > MAX_NUMERAL_VALUE ||
			second_int < MIN_NUMERAL_VALUE ||
			second_int > MAX_NUMERAL_VALUE ||
			resultant > MAX_NUMERAL_VALUE ||
			resultant < MIN_NUMERAL_VALUE){
		return;
	}

	/* Convert resultant back to numeral form */
	convert_arabic_to_roman(result, buffer_len, resultant);

	/* Verify that result is a valid roman numeral */
	if(valid_roman_numeral(result) == 0){
		memset(result, '\0', buffer_len);
	}
}
