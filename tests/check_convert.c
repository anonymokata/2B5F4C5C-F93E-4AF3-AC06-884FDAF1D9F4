#include <check.h>
#include "../src/convert.h"


/* check for Roman numeral validity */

START_TEST (check_I_valid)
{
    int valid = valid_roman_numeral("I");
    ck_assert_int_eq(valid, 1);
}
END_TEST

START_TEST (check_B_invalid)
{
    int valid = valid_roman_numeral("B");
    ck_assert_int_eq(valid, 0);
}
END_TEST

START_TEST (check_IIPX_invalid)
{
    int valid = valid_roman_numeral("IIPX");
    ck_assert_int_eq(valid, 0);
}
END_TEST

START_TEST (check_M_valid)
{
    int valid = valid_roman_numeral("M");
    ck_assert_int_eq(valid, 1);
}
END_TEST

START_TEST (check_V_valid)
{
    int valid = valid_roman_numeral("V");
    ck_assert_int_eq(valid, 1);
}
END_TEST

START_TEST (check_VV_invalid)
{
    int valid = valid_roman_numeral("VV");
    ck_assert_int_eq(valid, 0);
}
END_TEST

START_TEST (check_L_valid)
{
    int valid = valid_roman_numeral("L");
    ck_assert_int_eq(valid, 1);
}
END_TEST

START_TEST (check_LL_invalid)
{
    int valid = valid_roman_numeral("LL");
    ck_assert_int_eq(valid, 0);
}
END_TEST

START_TEST (check_D_valid)
{
    int valid = valid_roman_numeral("D");
    ck_assert_int_eq(valid, 1);
}
END_TEST

START_TEST (check_DD_invalid)
{
    int valid = valid_roman_numeral("DD");
    ck_assert_int_eq(valid, 0);
}
END_TEST

START_TEST (check_III_valid)
{
    int valid = valid_roman_numeral("III");
    ck_assert_int_eq(valid, 1);
}
END_TEST

START_TEST (check_IIII_invalid)
{
    int valid = valid_roman_numeral("IIII");
    ck_assert_int_eq(valid, 0);
}
END_TEST

START_TEST (check_XXX_valid)
{
    int valid = valid_roman_numeral("XXX");
    ck_assert_int_eq(valid, 1);
}
END_TEST

START_TEST (check_XXXX_invalid)
{
    int valid = valid_roman_numeral("XXXX");
    ck_assert_int_eq(valid, 0);
}
END_TEST

START_TEST (check_CCC_valid)
{
    int valid = valid_roman_numeral("CCC");
    ck_assert_int_eq(valid, 1);
}
END_TEST

START_TEST (check_CCCC_invalid)
{
    int valid = valid_roman_numeral("CCCC");
    ck_assert_int_eq(valid, 0);
}
END_TEST



/* check for roman numeral --> arabic */

START_TEST (check_I_to_1)
{
    int value = convert_roman_to_arabic("I");
    ck_assert_int_eq(value, 1);
}
END_TEST

START_TEST (check_IV_to_4)
{
    int value = convert_roman_to_arabic("IV");
    ck_assert_int_eq(value, 4);
}
END_TEST

START_TEST (check_V_to_5)
{
    int value = convert_roman_to_arabic("V");
    ck_assert_int_eq(value, 5);
}
END_TEST

START_TEST (check_IX_to_9)
{
    int value = convert_roman_to_arabic("IX");
    ck_assert_int_eq(value, 9);
}
END_TEST

START_TEST (check_X_to_10)
{
    int value = convert_roman_to_arabic("X");
    ck_assert_int_eq(value, 10);
}
END_TEST

START_TEST (check_XL_to_40)
{
    int value = convert_roman_to_arabic("XL");
    ck_assert_int_eq(value, 40);
}
END_TEST

START_TEST (check_L_to_50)
{
    int value = convert_roman_to_arabic("L");
    ck_assert_int_eq(value, 50);
}
END_TEST

START_TEST (check_XC_to_90)
{
    int value = convert_roman_to_arabic("XC");
    ck_assert_int_eq(value, 90);
}
END_TEST

START_TEST (check_CD_to_400)
{
    int value = convert_roman_to_arabic("CD");
    ck_assert_int_eq(value, 400);
}
END_TEST

START_TEST (check_D_to_500)
{
    int value = convert_roman_to_arabic("D");
    ck_assert_int_eq(value, 500);
}
END_TEST

START_TEST (check_CM_to_900)
{
    int value = convert_roman_to_arabic("CM");
    ck_assert_int_eq(value, 900);
}
END_TEST

START_TEST (check_M_to_1000)
{
    int value = convert_roman_to_arabic("M");
    ck_assert_int_eq(value, 1000);
}
END_TEST

START_TEST (check_MMMCMXCIX_to_3999)
{
    int value = convert_roman_to_arabic("MMMCMXCIX");
    ck_assert_int_eq(value, 3999);
}
END_TEST








/**
 * Test suite for running tests on conversion functions.
 */
Suite* convert_test_suite(void)
{
    Suite * test_suite= suite_create("Numeral Conversion Test Suite");

    /* Test Case For Validating Numerals */
    TCase * test_case_valid_numerals = tcase_create("Test Case Check Validity");
    tcase_add_test(test_case_valid_numerals, check_I_valid);
    tcase_add_test(test_case_valid_numerals, check_B_invalid);
    tcase_add_test(test_case_valid_numerals, check_IIPX_invalid);
    tcase_add_test(test_case_valid_numerals, check_M_valid);
    tcase_add_test(test_case_valid_numerals, check_V_valid);
    tcase_add_test(test_case_valid_numerals, check_VV_invalid);
    tcase_add_test(test_case_valid_numerals, check_L_valid);
    tcase_add_test(test_case_valid_numerals, check_LL_invalid);
    tcase_add_test(test_case_valid_numerals, check_D_valid);
    tcase_add_test(test_case_valid_numerals, check_DD_invalid);
    tcase_add_test(test_case_valid_numerals, check_III_valid);
    tcase_add_test(test_case_valid_numerals, check_IIII_invalid);
    tcase_add_test(test_case_valid_numerals, check_XXX_valid);
    tcase_add_test(test_case_valid_numerals, check_XXXX_invalid);
    tcase_add_test(test_case_valid_numerals, check_CCC_valid);
    tcase_add_test(test_case_valid_numerals, check_CCCC_invalid);
    suite_add_tcase(test_suite, test_case_valid_numerals);

    /* Test Case For Converting From Roman Numeral To Arabiuc */
    TCase * test_case_roman_to_arabic = tcase_create("Test Case Check Roman to Arabic");
    tcase_add_test(test_case_valid_numerals, check_I_to_1);
    tcase_add_test(test_case_valid_numerals, check_IV_to_4);
    tcase_add_test(test_case_valid_numerals, check_V_to_5);
    tcase_add_test(test_case_valid_numerals, check_IX_to_9);
    tcase_add_test(test_case_valid_numerals, check_X_to_10);
    tcase_add_test(test_case_valid_numerals, check_XL_to_40);
    tcase_add_test(test_case_valid_numerals, check_L_to_50);
    tcase_add_test(test_case_valid_numerals, check_XC_to_90);
    tcase_add_test(test_case_valid_numerals, check_CD_to_400);
    tcase_add_test(test_case_valid_numerals, check_D_to_500);
    tcase_add_test(test_case_valid_numerals, check_CM_to_900);
    tcase_add_test(test_case_valid_numerals, check_M_to_1000);
    tcase_add_test(test_case_valid_numerals, check_MMMCMXCIX_to_3999);
    suite_add_tcase(test_suite, test_case_roman_to_arabic);

    return test_suite;
}

