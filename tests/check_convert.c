#include <check.h>
#include "../src/convert.h"

/**
 * Test suite for running tests on conversion functions.
 */
Suite* convert_test_suite(void)
{
    Suite *s;
    s = suite_create("Numeral Convert Test Suite");

    return s;
}
