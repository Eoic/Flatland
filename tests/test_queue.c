#include <stdlib.h>

#include "../utils/queue/queue.h"
#include "unity.h"

static Queue *queue = NULL;

void setUp(void) {
    queue = (Queue *)malloc(sizeof(Queue));
    queue_init(queue);
}

void tearDown(void) {
    queue_dispose(queue);
    free(queue);
    queue = NULL;
}

void test_queue_init(void) { TEST_ASSERT_TRUE(queue_is_empty(queue)); }

void test_enqueue_dequeue(void) {
    int test_value = 42;

    queue_push(queue, &test_value);
    TEST_ASSERT_FALSE(queue_is_empty(queue));

    int *dequeued_value = (int *)queue_pop(queue);
    TEST_ASSERT_EQUAL_PTR(&test_value, dequeued_value);

    TEST_ASSERT_TRUE(queue_is_empty(queue));
}

void test_queue_dispose(void) {
    int test_value = 100;
    queue_push(queue, &test_value);
    queue_dispose(queue);

    TEST_ASSERT_TRUE(queue_is_empty(queue));
}

int main(void) {
    UNITY_BEGIN();

    // RUN_TEST(test_queue_init);
    // RUN_TEST(test_enqueue_dequeue);
    RUN_TEST(test_queue_dispose);

    return UNITY_END();
}
