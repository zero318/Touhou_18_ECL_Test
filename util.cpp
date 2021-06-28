#include <stdio.h>
#include <math.h>

#include <intrin.h>

#include "util.h"

noinline void assume_all_registers_volatile() {
	_mm256_zeroall();
	static volatile double yeetus = 1.0f;
	static volatile char deleetus[512];
	static volatile int your_registers = 5;
	yeetus = sin(cos(tan(yeetus)));
	your_registers += snprintf((char*)deleetus, countof(deleetus), "%f", yeetus);
}

noinline void assume_all_registers_volatile(void* use_arg) {
	_mm256_zeroall();
	static volatile double yeetus = 1.0f;
	static volatile char deleetus[512];
	static volatile int your_registers = 5;
	yeetus = sin(cos(tan(yeetus)));
	your_registers += snprintf((char*)deleetus, countof(deleetus), "%f%p", yeetus, use_arg);
}