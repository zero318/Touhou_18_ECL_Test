#pragma once

#include <stdint.h>

#include "util.h"

typedef struct Timer Timer;
struct Timer {
	int32_t previous;
	float subframe;
	int32_t current;
};
ValidateFieldOffset(0x0,	Timer, previous);
ValidateFieldOffset(0x4,	Timer, subframe);
ValidateFieldOffset(0x8,	Timer, current);

// =========================

