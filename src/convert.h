#ifndef ROMAN_CONVERTER_H
#define ROMAN_CONVERTER_H

int valid_roman_numeral(const char *numeral);
int roman_digit_to_integer(const char numeral);
int convert_roman_to_arabic(const char *numeral);
void convert_arabic_to_roman(int num, char *roman_num);

#endif
