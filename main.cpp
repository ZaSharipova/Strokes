#include <stdio.h>
#include "StrokeFunctions.h"
#include <assert.h>
#include <string.h>

#include "GoogleTestsStrokes.h"
#include "StrokeFunctions.h"

#define MAX_TESTS 100
#define TEST(name) void name(void)
#define REGISTER_TEST(stroke) register_test(#stroke, stroke);

extern struct TestCase tests[MAX_TESTS];
extern int test_count;
extern int current_test_failed;  

#define EXPECT_EQ_SIZE_T(a, b) \
    do {\
        unsigned long _a = (unsigned long)(a);\
        unsigned long _b = (unsigned long)(b);\
        if (_a != _b) {\
            printf("[FAIL] %s %s != %s, %lu != %lu\n", __func__, #a, #b, _a, _b);\
            current_test_failed = 1;\
        }\
    } while(0)

#define EXPECT_EQ_CHAR(a, b)\
    do {\
        const char* _a = (a);\
        const char* _b = (b);\
        if (_a == NULL && _b == NULL) {\
        break;\
    }\
    if (_a == NULL || _b == NULL || strcmp(_a, _b) != 0) {\
        printf("[FAIL] %s %s != %s, %s != %s\n",\
               __func__, #a, #b,\
               _a ? _a : "(null)",\
               _b ? _b : "(null)");\
        current_test_failed = 1;\
    }\
} while(0)

TEST(strchr) {
    EXPECT_EQ_CHAR(NULL, Mstrchr("123", 4));
    EXPECT_EQ_CHAR("45", Mstrchr("12345", 52));
}

TEST(strlen) {
    EXPECT_EQ_SIZE_T((size_t)1, Mstrlen("1"));
    EXPECT_EQ_SIZE_T((size_t)3, Mstrlen("112"));
    EXPECT_EQ_SIZE_T((size_t)0, Mstrlen(""));
}

TEST(strcpy) {
    char dest1[20] = "1234";
    EXPECT_EQ_CHAR("12345", Mstrcpy(dest1, "12345"));

    char dest2[20] = "1234";
    EXPECT_EQ_CHAR("12", Mstrcpy(dest2, "12")); 

    char dest3[20] = "12";
    EXPECT_EQ_CHAR("0", Mstrcpy(dest3, "0"));
}

TEST(strcnpy) {
    char dest1[20] = "1234";
    EXPECT_EQ_CHAR("4534", Mstrncpy(dest1, "45345", 2));

    char dest2[20] = "1234";
    EXPECT_EQ_CHAR("1234", Mstrncpy(dest2, "12", 0));

    char dest3[20] = "12";
    EXPECT_EQ_CHAR("02", Mstrncpy(dest3, "0", 1)); //wertyre
}

TEST(strcat) {
    char dest1[20] = "1234";
    char dest3[20] = "1234";
    EXPECT_EQ_CHAR(strcat(dest1, "12345"), Mstrcat(dest3, "12345"));

    char dest2[20] = "12";
    char dest4[20] = "12";
    EXPECT_EQ_CHAR(strcat(dest2, ""), Mstrcat(dest4, ""));
}

TEST(strncat){
    char dest1[20] = "1234";
    EXPECT_EQ_CHAR("123412", Mstrncat(dest1, "12345", 2));

    char dest2[20] = "1234";
    EXPECT_EQ_CHAR("1234123", Mstrncat(dest2, "12345", 3));
}

// TEST(strdup) {
//     char dest1[20] = "";
//     EXPECT_EQ("", Mstrdup("1234"));
//     char dest2[20] = "12";
//     EXPECT_EQ("", Mstrdup("12"));
// }

TEST(strstr){
    char dest1[20] = "123";
    EXPECT_EQ_CHAR("123", Mstrstr(dest1, "123"));
    char dest2[20] = "1234";
    EXPECT_EQ_CHAR("1234", Mstrstr(dest2, "123"));  
    char dest3[20] = "12";
    EXPECT_EQ_CHAR(NULL, Mstrstr(dest3, "123")); 
}

TEST(strtok){
    char dest1[20] = "123 23";
    EXPECT_EQ_CHAR("123", Mstrtok(dest1, " "));
    char dest2[20] = "1234";
    EXPECT_EQ_CHAR("1234", Mstrtok(dest2, ""));
    char dest3[20] = "";
    EXPECT_EQ_CHAR(NULL, Mstrtok(dest3, "123"));
}

void reg(void) {
    REGISTER_TEST(strchr);
    REGISTER_TEST(strlen);
    REGISTER_TEST(strcpy);
    REGISTER_TEST(strcnpy);
    REGISTER_TEST(strcat);
    REGISTER_TEST(strncat);
    //REGISTER_TEST(strdup);
    REGISTER_TEST(strstr);
    REGISTER_TEST(strtok);    
}

int main(void){
    reg();
    run_all_tests();
    return 0;
}
