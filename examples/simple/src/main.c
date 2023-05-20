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

int
main(int argc, char const *argv[])
{
    printf("\r\n");
    printf("sizeof(my_struct_t): %d\r\n", (int)sizeof(my_struct_t));
    printf("Offset of big_num is: %d\r\n", (int)offsetof(my_struct_t, big_num));
    printf("Offset of med_num is: %d\r\n", (int)offsetof(my_struct_t, med_num));

    return 0;
}
