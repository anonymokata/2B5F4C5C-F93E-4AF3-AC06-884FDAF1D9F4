#include <stdlib.h>
#include "check_calculate.c"
#include "check_convert.c"

/**
 * Runs a suite runner containing both test suites (calculate and convert) to perform all tests.
 */
int main(void)
{
	/* create test suite references and add all to a suite runner */
    Suite 	*suite_calculate	= calculate_test_suite();
    Suite 	*suite_convert		= convert_test_suite();
    SRunner *suite_runner		= srunner_create(suite_calculate);
    srunner_add_suite(suite_runner, suite_convert);

    /* run all tests within suite runner and get count of fails */
    srunner_run_all(suite_runner, CK_SILENT);
    int fail_ct 				= srunner_ntests_failed(suite_runner);

    /* Print results */
    if(fail_ct == 0){
    	srunner_print(suite_runner, CK_NORMAL);
    } else {
    	srunner_print(suite_runner, CK_VERBOSE);
    }

    /* free the suite runner of all suites and corresponding test cases */
    srunner_free(suite_runner);

    return 0;
}
