#ifndef STATIC_ASSERT_H
#define STATIC_ASSERT_H
#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
#define STATIC_ASSERT static_assert
#else
#define STATIC_ASSERT _Static_assert
#endif

/**
 * @brief      Stringify helper
 *
 *             Required preprocessor indirection
 *
 * @warning    Do note call directly.  Use STR() instead.
 *
 * @param      x     Item to stringify
 *
 * @return     Stringified result
 * @see        STR()
 */
#define STR_HELPER(x) #x

/**
 * @brief      Converts input into string
 *
 * @param      x     Datum to convert to string
 *
 * @return     String constant produced by preprocessor
 */
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
 * @return     Compile time error if assertion fails
 */
#define STATIC_ASSERT_TYPE_SIZE(t_label, expected_size)                \
    STATIC_ASSERT(                                                     \
        !(sizeof(t_label) < expected_size),                            \
        STR(t_label) " is smaller than " STR(expected_size) " bytes"); \
    STATIC_ASSERT(                                                     \
        !(sizeof(t_label) > expected_size),                            \
        STR(t_label) " is larger than " STR(expected_size) " bytes");  \
    STATIC_ASSERT(sizeof(t_label) == expected_size,                    \
                  STR(t_label) " must be " STR(expected_size) " bytes");

#define STATIC_ASSERT_MEMBER_OFFSET(t_label, member, offset) \
    STATIC_ASSERT((uint8_t *)(&((t_label *)0x0)->member) == (uint8_t *)offset)

#ifdef __cplusplus
}
#endif
#endif // STATIC_ASSERT_H
