#ifndef PACKED_H_
#define PACKED_H_
#ifdef __cplusplus
extern "C" {
#endif

#if defined(__clang__)
#    define PACKED_STRUCT(name) struct __attribute__((packed)) name
#elif defined(_MSC_VER)
#    define PACKED_STRUCT(name)                                                \
        __pragma(pack(push, 1)) struct name __pragma(pack(pop))
#elif defined(__GNUC__)
#    define PACKED_STRUCT(name) struct __attribute__((packed)) name
#endif

#if defined(__clang__)
#    define PACKED_ENUM(name) enum name : int8_t
#elif defined(_MSC_VER)
#    define PACKED_ENUM(name)                                                  \
        __pragma(pack(push, 1)) enum name __pragma(pack(pop))
#elif defined(__GNUC__)
#    define PACKED_ENUM(name) enum __attribute__((packed)) name
#endif

#ifdef __cplusplus
}
#endif
#endif // PACKED_H_
