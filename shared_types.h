#pragma once

#include <stdint.h>

#include "util.h"

#include "game_specific_data.h"

#if !(defined(old_engine) || defined(new_engine))
#error Invalid game version specified!
#endif

typedef struct Float2 Float2;
struct Float2 {
	float x;
	float y;

	void make_coords_from_vector(float angle, float magnitude) {
		__asm {
			MOV EAX, this
			FLD angle
			FSINCOS
			FMUL magnitude
			FSTP DWORD PTR [EAX]
			FMUL magnitude
			FSTP DWORD PTR [EAX+4]
		}
	}
};
ValidateFieldOffset(0x0,	Float2, x);
ValidateFieldOffset(0x4,	Float2, y);

typedef struct Float3 Float3;
struct Float3 {
	float x;
	float y;
	float z;
};
ValidateFieldOffset(0x0,	Float3, x);
ValidateFieldOffset(0x4,	Float3, y);
ValidateFieldOffset(0x8,	Float3, z);

typedef struct Float4 Float4;
struct Float4 {
	float x;
	float y;
	float z;
	float w;
};
ValidateFieldOffset(0x0,	Float4, x);
ValidateFieldOffset(0x4,	Float4, y);
ValidateFieldOffset(0x8,	Float4, z);
ValidateFieldOffset(0xC,	Float4, w);

typedef struct Int2 Int2;
struct Int2 {
	int32_t x;
	int32_t y;
};
ValidateFieldOffset(0x0,	Int2, x);
ValidateFieldOffset(0x4,	Int2, y);

typedef struct Int3 Int3;
struct Int3 {
	int32_t x;
	int32_t y;
	int32_t z;
};
ValidateFieldOffset(0x0,	Int3, x);
ValidateFieldOffset(0x4,	Int3, y);
ValidateFieldOffset(0x8,	Int3, z);

typedef union D3DCOLOR D3DCOLOR;
union D3DCOLOR {
	uint32_t full;
	struct {
		uint8_t b;
		uint8_t g;
		uint8_t r;
		uint8_t a;
	};
};
ValidateFieldOffset(0x0,	D3DCOLOR, b);
ValidateFieldOffset(0x1,	D3DCOLOR, g);
ValidateFieldOffset(0x2,	D3DCOLOR, r);
ValidateFieldOffset(0x3,	D3DCOLOR, a);

typedef float D3DMATRIX[4][4];

typedef struct RenderVertex044 RenderVertex044;
struct RenderVertex044 {
	Float4 position;
	D3DCOLOR diffuse_color;
};
ValidateFieldOffset(0x0,	RenderVertex044, position);
ValidateFieldOffset(0x10,	RenderVertex044, diffuse_color);

typedef struct RenderVertex144 RenderVertex144;
struct RenderVertex144 {
	Float4 position;
	D3DCOLOR diffuse_color;
	Float2 texture_uv;
};
ValidateFieldOffset(0x0,	RenderVertex144, position);
ValidateFieldOffset(0x10,	RenderVertex144, diffuse_color);
ValidateFieldOffset(0x14,	RenderVertex144, texture_uv);

#include engine_types