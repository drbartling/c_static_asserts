#include "static_assert.h"

#include <stdint.h>
#include <stdio.h>

typedef struct __attribute__((packed)) {
    int8_t  small_num;
    int32_t big_num;
    int16_t med_num;
} my_struct_t;
STATIC_ASSERT_TYPE_SIZE(my_struct_t, 7);
STATIC_ASSERT_MEMBER_OFFSET(my_struct_t, big_num, 1);
STATIC_ASSERT_MEMBER_OFFSET(my_struct_t, med_num, 5);

typedef enum __attribute__((packed)) {
    fruit,
    vegetable,
} union_tag_t;
// STATIC_ASSERT_TYPE_SIZE(union_tag_t, 1);

typedef enum __attribute__((packed)) {
    apple,
    pear,
    banana,
} tasty_fruit_t;
// STATIC_ASSERT_TYPE_SIZE(tasty_fruit_t, 1);

typedef struct __attribute__((packed)) {
    int8_t empty[0]; // Empty array for zero size. Vegetables are not tasty /s
} tasty_vegetable_t;
// STATIC_ASSERT_TYPE_SIZE(tasty_vegetable_t, 0);

typedef struct __attribute__((packed)) {
    union_tag_t tag;
    union {
        tasty_fruit_t     fruit;
        tasty_vegetable_t vegetable;
    };
} tasty_food_t;
// STATIC_ASSERT_TYPE_SIZE(tasty_food_t, 2);

int
main(int argc, char const *argv[])
{
    printf("\r\n");
    printf("sizeof(my_struct_t): %d\r\n", (int)sizeof(my_struct_t));
    printf("Offset of big_num is: %d\r\n", (int)offsetof(my_struct_t, big_num));
    printf("Offset of med_num is: %d\r\n", (int)offsetof(my_struct_t, med_num));

    printf("sizeof(union_tag_t): %d\r\n", (int)sizeof(union_tag_t));
    printf("sizeof(tasty_fruit_t): %d\r\n", (int)sizeof(tasty_fruit_t));
    printf("sizeof(tasty_vegetable_t): %d\r\n", (int)sizeof(tasty_vegetable_t));
    printf("sizeof(tasty_food_t): %d\r\n", (int)sizeof(tasty_food_t));

    return 0;
}
