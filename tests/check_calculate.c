#include <check.h>
#include "../src/calculate.h"

/**
 * Test suite for running tests on calculation functions.
 */
Suite* calculate_test_suite(void)
{
    Suite *s;
    s = suite_create("Numeral Calculate Test Suite");

    return s;
}

