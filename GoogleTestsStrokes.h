#ifndef TRAIN_GOOGLE_TESTS_H_
#define TRAIN_GOOGLE_TESTS_H_

typedef void (*TestFunc)(void);

struct TestCase {
    const char* name;
    TestFunc func;
};

void run_all_tests(void);
void register_test(const char* name, TestFunc func);

#endif // TRAIN_GOOGLE_TESTS_H_