#include <check.h>
#include "../src/calculate.h"


/* Limits */
static const int MAX_LENGTH = 16;


/* Addition checks */

START_TEST (check_I_plus_I_equals_II)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    addition("I", "I", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "II");
}
END_TEST

START_TEST (check_I_plus_MMMCMXCIX_equals_INVALID)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    addition("I", "MMMCMXCIX", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "");
}
END_TEST

START_TEST (check_MII_plus_CCX_equals_MCCXII)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    addition("MII", "CCX", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "MCCXII");
}
END_TEST

START_TEST (check_L_plus_L_equals_C)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    addition("L", "L", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "C");
}
END_TEST

START_TEST (check_CCC_plus_CC_equals_D)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    addition("CCC", "CC", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "D");
}
END_TEST

START_TEST (check_D_plus_D_equals_M)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    addition("D", "D", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "M");
}
END_TEST

START_TEST (check_IX_plus_IX_equals_XVIII)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    addition("IX", "IX", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "XVIII");
}
END_TEST

START_TEST (check_XC_plus_XC_equals_CLXXX)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    addition("XC", "XC", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "CLXXX");
}
END_TEST

START_TEST (check_X_plus_XXX_equals_XL)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    addition("X", "XXX", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "XL");
}
END_TEST

START_TEST (check_ADDITION_INVALID_BUFFER)
{
    char resultant[MAX_LENGTH + 1];
    memset(resultant, '\0', MAX_LENGTH + 1 );
    addition("X", "XXX", resultant, MAX_LENGTH + 1);
    ck_assert_str_eq(resultant, "");
}
END_TEST



/* Subtraction checks */

START_TEST (check_II_minus_I_equals_I)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    subtraction("II", "I", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "I");
}
END_TEST

START_TEST (check_II_minus_II_equals_INVALID)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    subtraction("II", "II", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "");
}
END_TEST

START_TEST (check_MMMMCCXCVIII_minus_MMI_equals_INVALID)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    subtraction("MMMMCCXCVIII", "MMI", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "");
}
END_TEST

START_TEST (check_V_minus_I_equals_IV)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    subtraction("V", "I", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "IV");
}
END_TEST

START_TEST (check_X_minus_I_equals_IX)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    subtraction("X", "I", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "IX");
}
END_TEST

START_TEST (check_L_minus_I_equals_XLIX)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    subtraction("L", "I", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "XLIX");
}
END_TEST

START_TEST (check_MMM_minus_M_equals_MM)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    subtraction("MMM", "M", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "MM");
}
END_TEST

START_TEST (check_X_minus_XI_equals_INVALID)
{
    char resultant[MAX_LENGTH];
    memset(resultant, '\0', MAX_LENGTH );
    subtraction("X", "XI", resultant, MAX_LENGTH);
    ck_assert_str_eq(resultant, "");
}
END_TEST

START_TEST (check_SUBTRACTION_INVALID_BUFFER)
{
    char resultant[MAX_LENGTH + 1];
    memset(resultant, '\0', MAX_LENGTH + 1 );
    subtraction("X", "XXX", resultant, MAX_LENGTH + 1);
    ck_assert_str_eq(resultant, "");
}
END_TEST



/**
 * Test suite for running tests on calculation functions.
 */
Suite* calculate_test_suite(void)
{
    Suite * test_suite= suite_create("Numeral Calculation Test Suite");

    /* Test Case For Addition */
	TCase * test_case_addition = tcase_create("Test Case Check Addition");
	tcase_add_test(test_case_addition, check_I_plus_I_equals_II);
	tcase_add_test(test_case_addition, check_MII_plus_CCX_equals_MCCXII);
	tcase_add_test(test_case_addition, check_L_plus_L_equals_C);
	tcase_add_test(test_case_addition, check_CCC_plus_CC_equals_D);
	tcase_add_test(test_case_addition, check_D_plus_D_equals_M);
	tcase_add_test(test_case_addition, check_IX_plus_IX_equals_XVIII);
	tcase_add_test(test_case_addition, check_XC_plus_XC_equals_CLXXX);
	tcase_add_test(test_case_addition, check_X_plus_XXX_equals_XL);
	tcase_add_test(test_case_addition, check_I_plus_MMMCMXCIX_equals_INVALID);
	tcase_add_test(test_case_addition, check_ADDITION_INVALID_BUFFER);
	suite_add_tcase(test_suite, test_case_addition);

    /* Test Case For Subtraction */
	TCase * test_case_subtraction = tcase_create("Test Case Check Subtraction");
	tcase_add_test(test_case_subtraction, check_II_minus_I_equals_I);
	tcase_add_test(test_case_subtraction, check_MMMMCCXCVIII_minus_MMI_equals_INVALID);
	tcase_add_test(test_case_subtraction, check_V_minus_I_equals_IV);
	tcase_add_test(test_case_subtraction, check_X_minus_I_equals_IX);
	tcase_add_test(test_case_subtraction, check_L_minus_I_equals_XLIX);
	tcase_add_test(test_case_subtraction, check_MMM_minus_M_equals_MM);
	tcase_add_test(test_case_subtraction, check_X_minus_XI_equals_INVALID);
	tcase_add_test(test_case_subtraction, check_II_minus_II_equals_INVALID);
	tcase_add_test(test_case_subtraction, check_SUBTRACTION_INVALID_BUFFER);
	suite_add_tcase(test_suite, test_case_subtraction);

    return test_suite;
}

