#include <cmocka.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

#include "../utils/queue/queue.h"

static int setup(void **state) {
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    if (queue == NULL) {
        return -1;
    }

    queue_init(queue);
    *state = queue;

    return 0;
}

static int teardown(void **state) {
    Queue *queue = (Queue *)(*state);
    queue_dispose(queue);
    free(queue);
    return 0;
}

static void test_queue_init(void **state) {
    Queue *queue = (Queue *)(*state);
    assert_true(queue_is_empty(queue));
}

static void test_enqueue_dequeue(void **state) {
    Queue *queue = (Queue *)(*state);
    int test_value = 42;

    queue_push(queue, &test_value);
    assert_false(queue_is_empty(queue));
    int *dequeued_value = (int *)queue_pop(queue);
    assert_ptr_equal(dequeued_value, &test_value);
    assert_true(queue_is_empty(queue));
}

static void test_queue_dispose(void **state) {
    Queue *queue = (Queue *)(*state);
    int test_value = 100;
    queue_push(queue, &test_value);
    queue_dispose(queue);
    assert_true(queue_is_empty(queue));
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_queue_init),
        cmocka_unit_test(test_enqueue_dequeue),
        cmocka_unit_test(test_queue_dispose),
    };

    return cmocka_run_group_tests(tests, setup, teardown);
}
