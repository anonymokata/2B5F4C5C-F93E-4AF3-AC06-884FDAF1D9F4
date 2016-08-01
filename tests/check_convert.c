#include <check.h>
#include "../src/convert.h"


/* check for invalid characters */

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

/* check for numerals with a limit of one */

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

/* check for numerals with a limit of three */

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






/**
 * Test suite for running tests on conversion functions.
 */
Suite* convert_test_suite(void)
{
    Suite * s;
    s = suite_create("Numeral Conversion Test Suite");

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
    suite_add_tcase(s, test_case_valid_numerals);

    return s;
}

