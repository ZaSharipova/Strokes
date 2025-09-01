#include "GoogleTestsStrokes.h"

#include <stdio.h>
#include <math.h>

#define MAX_TESTS 100

struct TestCase tests[MAX_TESTS];
int test_count;
int current_test_failed;  

void register_test(const char* name, TestFunc func) {
    if (test_count < MAX_TESTS) {
        tests[test_count].name = name;
        tests[test_count].func = func;
        test_count++;
    }
}

void run_all_tests(void) {
    //int passed = 0;
    //printf("Running %d tests...\n\n", test_count);
    for (int i = 0; i < test_count; i++) {

        current_test_failed = 0;
        tests[i].func();

        if (current_test_failed == 0) {
            printf("[PASS] %s\n", tests[i].name);
            //passed++;
        }
        printf("\n");
    }
    //printf("\nSummary: %d/%d passed\n", passed, test_count);
}