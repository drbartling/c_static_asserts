#ifndef STATIC_ASSERT_H
#define STATIC_ASSERT_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

#ifdef __cplusplus
#    define STATIC_ASSERT static_assert
#else
#    define STATIC_ASSERT _Static_assert
#endif

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)

/**
 * @brief      Compile time assertion on typedef size
 *
 *             Combination of _Static_asserts to help identify if the type is
 *             larger or smaller than expected.
 *
 * @param      t_label        The type label
 * @param      expected_size  The expected size
 *
 */
#define STATIC_ASSERT_TYPE_SIZE(t_label, expected_size)                        \
    STATIC_ASSERT(                                                             \
        !(sizeof(t_label) < expected_size),                                    \
        STR(t_label) " is smaller than " STR(expected_size) " bytes");         \
    STATIC_ASSERT(                                                             \
        !(sizeof(t_label) > expected_size),                                    \
        STR(t_label) " is larger than " STR(expected_size) " bytes");          \
    STATIC_ASSERT(sizeof(t_label) == expected_size,                            \
                  STR(t_label) " must be " STR(expected_size) " bytes")

/**
 * @brief      Fail compilation if ofset of member does not match the expected
 *             offset
 *
 * @param      t_label          Lable for the type
 * @param      member           Label for the member
 * @param      expected_offset  The expected offset
 *
 */
#define STATIC_ASSERT_MEMBER_OFFSET(t_label, member, expected_offset)          \
    STATIC_ASSERT(!(offsetof(t_label, member) < expected_offset),              \
                  STR(member) " offset is less than " STR(expected_offset));   \
    STATIC_ASSERT(                                                             \
        !(offsetof(t_label, member) > expected_offset),                        \
        STR(member) " offset is greater than " STR(expected_offset));          \
    STATIC_ASSERT(offsetof(t_label, member) == expected_offset,                \
                  STR(member) " offset must be " STR(expected_offset))

#ifdef __cplusplus
}
#endif
#endif // STATIC_ASSERT_H
