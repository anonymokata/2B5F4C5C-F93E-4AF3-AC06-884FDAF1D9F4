#include <stdio.h>
#include "calculate.h"
#include "convert.h"

/**
 * Adds two roman numerals and sets result to the resultant of the addition.
 */
void addition(char * first_arg, char * second_arg, char * result){
	int first_int = convert_roman_to_arabic(first_arg);
	int second_int = convert_roman_to_arabic(second_arg);
	if(first_int > 0 && second_int > 0){
		int resultant = first_int + second_int;
		if(resultant > 0 && resultant < 4000){
			convert_arabic_to_roman(resultant, result);
		}
	}
}

/**
 * Subtracts the second argument from the first of two roman numerals and sets result to the resultant of the subtraction.
 */
void subtraction(char * first_arg, char * second_arg, char * result){
	int first_int = convert_roman_to_arabic(first_arg);
	int second_int = convert_roman_to_arabic(second_arg);
	if(first_int > 0 && second_int > 0){
		int resultant = first_int - second_int;
		if(resultant > 0 && resultant < 4000){
			convert_arabic_to_roman(resultant, result);
		}
	}
}
