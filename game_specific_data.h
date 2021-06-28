#pragma once

#define EoSD (6)
#define PCB (7)
#define IN (8)
#define PoFV (9)
#define StB (95)
#define MoF (10)
#define SA (11)
#define UFO (12)
#define DS (125)
#define GFW (128)
#define TD (13)
#define DDC (14)
#define ISC (143)
#define LoLK (15)
#define HSiFS (16)
#define VD (165)
#define WBaWC (17)
#define UM (18)

#define internal_game_version game_version

#if internal_game_version < EoSD
#define pc98_engine
#elif (internal_game_version <= PoFV) || (internal_game_version == StB)
#define old_engine
#define engine_types "old_engine_types.h"
#else
#define new_engine
#define engine_types "new_engine_types.h"
#endif