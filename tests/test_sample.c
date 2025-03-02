#include "unity.h"

void setUp(void) {
    // Set up resources if needed
}

void tearDown(void) {
    // Clean up resources if needed
}

void test_example(void) { TEST_ASSERT_EQUAL(1, 1); }
void test_example_two(void) { TEST_ASSERT_EQUAL(1, 1); }

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_example);
    RUN_TEST(test_example_two);
    return UNITY_END();
}