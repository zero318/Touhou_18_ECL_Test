#pragma once

#include <stdint.h>

#include "util.h"

typedef struct Timer Timer;
struct Timer {
	int32_t previous = -999999;
	int32_t current = 0;
	float current_f = 0.0f;
	uint32_t scale_table_index = 0;
	uint32_t control;


	

	void increment(float);
	void increment_2(void);
	void decrement(float);
};
ValidateFieldOffset(0x0,	Timer, previous);
ValidateFieldOffset(0x4,	Timer, current);
ValidateFieldOffset(0x8,	Timer, current_f);
ValidateFieldOffset(0xC,	Timer, scale_table_index);
ValidateFieldOffset(0x10,	Timer, control);

// =========================

typedef struct InterpFloat InterpFloat;
struct InterpFloat {
	float initial;
	float goal;
	float bezier_1;
	float bezier_2;
	float current;
	Timer time;
	int32_t end_time;
	int32_t method;
};
ValidateFieldOffset(0x0,	InterpFloat, initial);
ValidateFieldOffset(0x4,	InterpFloat, goal);
ValidateFieldOffset(0x8,	InterpFloat, bezier_1);
ValidateFieldOffset(0xC,	InterpFloat, bezier_2);
ValidateFieldOffset(0x10,	InterpFloat, current);
ValidateFieldOffset(0x14,	InterpFloat, time);
ValidateFieldOffset(0x28,	InterpFloat, end_time);
ValidateFieldOffset(0x2C,	InterpFloat, method);

typedef struct InterpFloat2 InterpFloat2;
struct InterpFloat2 {
	Float2 initial;
	Float2 goal;
	Float2 bezier_1;
	Float2 bezier_2;
	Float2 current;
	Timer time;
	int32_t end_time;
	int32_t method;
};
ValidateFieldOffset(0x0,	InterpFloat2, initial);
ValidateFieldOffset(0x8,	InterpFloat2, goal);
ValidateFieldOffset(0x10,	InterpFloat2, bezier_1);
ValidateFieldOffset(0x18,	InterpFloat2, bezier_2);
ValidateFieldOffset(0x20,	InterpFloat2, current);
ValidateFieldOffset(0x28,	InterpFloat2, time);
ValidateFieldOffset(0x3C,	InterpFloat2, end_time);
ValidateFieldOffset(0x40,	InterpFloat2, method);

typedef struct InterpFloat3 InterpFloat3;
struct InterpFloat3 {
	Float3 initial;
	Float3 goal;
	Float3 bezier_1;
	Float3 bezier_2;
	Float3 current;
	Timer time;
	int32_t end_time;
	int32_t method;
};
ValidateFieldOffset(0x0,	InterpFloat3, initial);
ValidateFieldOffset(0xC,	InterpFloat3, goal);
ValidateFieldOffset(0x18,	InterpFloat3, bezier_1);
ValidateFieldOffset(0x24,	InterpFloat3, bezier_2);
ValidateFieldOffset(0x30,	InterpFloat3, current);
ValidateFieldOffset(0x3C,	InterpFloat3, time);
ValidateFieldOffset(0x50,	InterpFloat3, end_time);
ValidateFieldOffset(0x54,	InterpFloat3, method);

typedef struct InterpInt InterpInt;
struct InterpInt {
	int32_t initial;
	int32_t goal;
	int32_t bezier_1;
	int32_t bezier_2;
	int32_t current;
	Timer time;
	int32_t end_time;
	int32_t method;
};
ValidateFieldOffset(0x0,	InterpInt, initial);
ValidateFieldOffset(0x4,	InterpInt, goal);
ValidateFieldOffset(0x8,	InterpInt, bezier_1);
ValidateFieldOffset(0xC,	InterpInt, bezier_2);
ValidateFieldOffset(0x10,	InterpInt, current);
ValidateFieldOffset(0x14,	InterpInt, time);
ValidateFieldOffset(0x28,	InterpInt, end_time);
ValidateFieldOffset(0x2C,	InterpInt, method);

typedef struct InterpInt3 InterpInt3;
struct InterpInt3 {
	Int3 initial;
	Int3 goal;
	Int3 bezier_1;
	Int3 bezier_2;
	Int3 current;
	Timer time;
	int32_t end_time;
	int32_t method;
};
ValidateFieldOffset(0x0,	InterpInt3, initial);
ValidateFieldOffset(0xC,	InterpInt3, goal);
ValidateFieldOffset(0x18,	InterpInt3, bezier_1);
ValidateFieldOffset(0x24,	InterpInt3, bezier_2);
ValidateFieldOffset(0x30,	InterpInt3, current);
ValidateFieldOffset(0x3C,	InterpInt3, time);
ValidateFieldOffset(0x50,	InterpInt3, end_time);
ValidateFieldOffset(0x54,	InterpInt3, method);