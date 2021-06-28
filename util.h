#pragma once

#include <stddef.h>

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define _MACRO_CAT(arg1, arg2) arg1 ## arg2
#define MACRO_CAT(arg1, arg2) _MACRO_CAT(arg1, arg2)
#define _MACRO_STR(arg) #arg
#define MACRO_STR(arg) _MACRO_STR(arg)
#define MACRO_EVAL(...) __VA_ARGS__

#define unknown_name \
MACRO_CAT(unknown_, __COUNTER__)

#define unknown_fields(size) \
unsigned char unknown_name[size];

#define padding_bytes(size) \
unknown_fields(size)

#define probably_padding_bytes(size) \
padding_bytes(size)

#define unknown_bitfields(type, size) \
type unknown_name : size

#define padding_bitfields(type, size) \
unknown_bitfields((type), (size))

#define probably_padding_bitfields(type, size) \
padding_bitfields((type), (size))

#define ValidateFieldOffset(offset, struct_type, member_name) \
static_assert((offset) == __builtin_offsetof(struct_type, member_name), "Incorrect struct offset! Offset of " MACRO_STR(struct_type) "."#member_name" is not "#offset)

template <typename T>
struct ZUNLinkedList {
	T* data;
	ZUNLinkedList<T>* next;
	ZUNLinkedList<T>* prev;
	ZUNLinkedList<T>* idk;
};

#define countof(array_type) \
(sizeof(array_type) / sizeof(array_type[0]))

template<typename T, size_t size>
constexpr size_t GetArrLength(T(&)[size]) { return size; }

#define noinline __declspec(noinline)

noinline void assume_all_registers_volatile();
noinline void assume_all_registers_volatile(void* use_arg);

template <typename T>
inline T confine_to_range(T min, T input, T max) {
	T temp = __max(min, input);
	return __min(max, temp);
}