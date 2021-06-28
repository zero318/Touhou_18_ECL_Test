#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

#include <array>
#include <type_traits>

#define game_version UM
#include "shared_types.h"

const float PI_F = (float)M_PI;
const float TWO_PI_F = (float)M_PI * 2;

noinline float atan2_wrapper(float y, float x) {
	return atan2(y, x);
}

float reduce_angle(float angle) {
	int32_t counter = 0;
	while (angle > PI_F) {
		angle -= TWO_PI_F;
		if (counter++ > 32) break;
	}
	while (angle < -PI_F) {
		angle += TWO_PI_F;
		if (counter++ > 32) break;
	}
	return angle;
}

typedef struct PosVel PosVel;
struct PosVel {
	Float3 position;
	Float3 position_2;
	float vel_norm_or_circle_angular_velocity;
	float angle;
	float circle_radius;
	float circle_radial_speed;
	float some_angle;
	unknown_fields(0x8);
	Float3 maybe_velocity;
	uint32_t flags;
};

typedef struct InterpStrange1 InterpStrange1;
struct InterpStrange1 {
	Float3 current;
	Float3 initial;
	Float3 goal;
	Float3 bezier_1;
	Float3 bezier_2;
	Timer time;
	int32_t end_time;
	int32_t method_for_1D;
	uint32_t unknown_dword_A;
	uint32_t unknown_dword_B;
	int32_t method_for_3D;
	uint32_t flags;
};

typedef struct GameThread GameThread;
struct GameThread {
	unsigned char unknown[0xB0];
	union {
		uint32_t flags;
		struct {
			uint32_t unknown_flag_A : 1;
			uint32_t unknown_flag_B : 1;
			uint32_t skip_flag : 1;
			unknown_bitfields(uint32_t, 7);
			uint32_t unknown_flag_C : 1;
		};
	};
	bool dummy;
	

	int run_thread();
};
ValidateFieldOffset(0xB0, GameThread, flags);
ValidateFieldOffset(0xB4, GameThread, dummy);

typedef struct AbilityShop AbilityShop;
struct AbilityShop {

};

AbilityShop *__restrict static_ability_shop_ptr;

GameThread *__restrict static_game_thread_ptr;

typedef struct AnmVM AnmVM;
typedef int32_t AnmID;

typedef struct AnmVMPrefix AnmVMPrefix;
struct AnmVMPrefix {
	Timer last_stop_time;
	int32_t last_stop_instr_offset;
	uint32_t layer;
	int32_t anim_slot;
	int32_t anim_slot_2;
	int32_t sprite_id;
	int32_t script_id;
	int32_t instr_offset;
	Float3 position;
	Float3 rotation;
	Float3 angular_velocity;
	Float2 scale;
	Float2 scale_2;
	Float2 scale_growth;
	Float2 uv_scale;
	Float2 sprite_size;
	Float2 uv_scroll_pos;
	Float2 anchor_offset;
	unknown_fields(0x4);
	InterpFloat3 position_interp;
	InterpInt3 rgb1_interp;
	InterpInt alpha1_interp;
	InterpFloat3 rotation_interp;
	InterpFloat rotation_2D_interp;
	InterpFloat2 scale_interp;
	InterpFloat2 scale_2_interp;
	InterpFloat2 uv_scale_interp;
	InterpInt3 rgb2_interp;
	InterpInt alpha2_interp;
	InterpFloat u_velocity_interp;
	InterpFloat v_velocity_interp;
	Float2 uv_quad_of_sprite[4];
	Float2 uv_scroll_velocity;
	D3DMATRIX unknown_matrix_A;
	D3DMATRIX unknown_matrix_B;
	D3DMATRIX unknown_matrix_C;
	int32_t pending_switch_label;
	int32_t time_of_last_sprite_set;
	unknown_fields(0x8);
	int32_t anm_int_vars[4];
	float anm_float_vars[4];
	Float3 anm_vars_33_34_35;
	int32_t anm_var_8;
	int32_t anm_var_9;
	float rand_param_one;
	float rand_param_pi;
	int32_t rand_param_int;
	Float3 position_2;
	Float3 last_rendered_quad_in_surface_space[4];
	int32_t mode_of_create_child;
	D3DCOLOR color1;
	D3DCOLOR color2;
	unknown_fields(0x4);
	union {
		uint32_t flags_A;
		struct {
			unknown_bitfields(uint32_t, 2);
			uint32_t unknown_flag_A : 1;	/*00000004*/
		};
	};
	union {
		uint32_t flags_B;
		struct {
			unknown_bitfields(uint32_t, 9);
			uint32_t unknown_flag_B : 1;	/*00000200*/
		};
	};
	union {
		uint32_t flags_C;
	};
	Float2 ins_439;
};
ValidateFieldOffset(0x0,	AnmVMPrefix, last_stop_time);
ValidateFieldOffset(0x14,	AnmVMPrefix, last_stop_instr_offset);
ValidateFieldOffset(0x18,	AnmVMPrefix, layer);
ValidateFieldOffset(0x1C,	AnmVMPrefix, anim_slot);
ValidateFieldOffset(0x20,	AnmVMPrefix, anim_slot_2);
ValidateFieldOffset(0x24,	AnmVMPrefix, sprite_id);
ValidateFieldOffset(0x28,	AnmVMPrefix, script_id);
ValidateFieldOffset(0x2C,	AnmVMPrefix, instr_offset);
ValidateFieldOffset(0x30,	AnmVMPrefix, position);
ValidateFieldOffset(0x3C,	AnmVMPrefix, rotation);
ValidateFieldOffset(0x48,	AnmVMPrefix, angular_velocity);
ValidateFieldOffset(0x54,	AnmVMPrefix, scale);
ValidateFieldOffset(0x5C,	AnmVMPrefix, scale_2);
ValidateFieldOffset(0x64,	AnmVMPrefix, scale_growth);
ValidateFieldOffset(0x6C,	AnmVMPrefix, uv_scale);
ValidateFieldOffset(0x74,	AnmVMPrefix, sprite_size);
ValidateFieldOffset(0x7C,	AnmVMPrefix, uv_scroll_pos);
ValidateFieldOffset(0x84,	AnmVMPrefix, anchor_offset);
ValidateFieldOffset(0x90,	AnmVMPrefix, position_interp);
ValidateFieldOffset(0xE8,	AnmVMPrefix, rgb1_interp);
ValidateFieldOffset(0x140,	AnmVMPrefix, alpha1_interp);
ValidateFieldOffset(0x170,	AnmVMPrefix, rotation_interp);
ValidateFieldOffset(0x1C8,	AnmVMPrefix, rotation_2D_interp);
ValidateFieldOffset(0x1F8,	AnmVMPrefix, scale_interp);
ValidateFieldOffset(0x23C,	AnmVMPrefix, scale_2_interp);
ValidateFieldOffset(0x280,	AnmVMPrefix, uv_scale_interp);
ValidateFieldOffset(0x2C4,	AnmVMPrefix, rgb2_interp);
ValidateFieldOffset(0x31C,	AnmVMPrefix, alpha2_interp);
ValidateFieldOffset(0x34C,	AnmVMPrefix, u_velocity_interp);
ValidateFieldOffset(0x37C,	AnmVMPrefix, v_velocity_interp);
ValidateFieldOffset(0x3AC,	AnmVMPrefix, uv_quad_of_sprite);
ValidateFieldOffset(0x3CC,	AnmVMPrefix, uv_scroll_velocity);
ValidateFieldOffset(0x3D4,	AnmVMPrefix, unknown_matrix_A);
ValidateFieldOffset(0x414,	AnmVMPrefix, unknown_matrix_B);
ValidateFieldOffset(0x454,	AnmVMPrefix, unknown_matrix_C);
ValidateFieldOffset(0x494,	AnmVMPrefix, pending_switch_label);
ValidateFieldOffset(0x498,	AnmVMPrefix, time_of_last_sprite_set);
ValidateFieldOffset(0x4A4,	AnmVMPrefix, anm_int_vars);
ValidateFieldOffset(0x4B4,	AnmVMPrefix, anm_float_vars);
ValidateFieldOffset(0x4C4,	AnmVMPrefix, anm_vars_33_34_35);
ValidateFieldOffset(0x4D0,	AnmVMPrefix, anm_var_8);
ValidateFieldOffset(0x4D4,	AnmVMPrefix, anm_var_9);
ValidateFieldOffset(0x4D8,	AnmVMPrefix, rand_param_one);
ValidateFieldOffset(0x4DC,	AnmVMPrefix, rand_param_pi);
ValidateFieldOffset(0x4E0,	AnmVMPrefix, rand_param_int);
ValidateFieldOffset(0x4E4,	AnmVMPrefix, position_2);
ValidateFieldOffset(0x4F0,	AnmVMPrefix, last_rendered_quad_in_surface_space);
ValidateFieldOffset(0x520,	AnmVMPrefix, mode_of_create_child);
ValidateFieldOffset(0x524,	AnmVMPrefix, color1);
ValidateFieldOffset(0x528,	AnmVMPrefix, color2);
ValidateFieldOffset(0x530,	AnmVMPrefix, flags_A);
ValidateFieldOffset(0x534,	AnmVMPrefix, flags_B);
ValidateFieldOffset(0x538,	AnmVMPrefix, flags_C);
ValidateFieldOffset(0x53C,	AnmVMPrefix, ins_439);


typedef struct AnmVMSuffix AnmVMSuffix;
struct AnmVMSuffix {
	int32_t id;
	int32_t fast_id;
	Timer time_in_script;
	Timer unknown_timer_A;
	ZUNLinkedList<AnmVM> node_in_global_list;
	ZUNLinkedList<AnmVM> node_as_child;
	ZUNLinkedList<AnmVM> list_of_children;
	ZUNLinkedList<AnmVM> weird_list;
	ZUNLinkedList<AnmVM>* next_in_layer;
	int32_t unknown_int_A;
	AnmVM* maybe_root_vm;
	AnmVM* parent_vm;
	float slowdown;
	void* special_vertex_buffer_data;
	int32_t special_vertex_buffer_size;
	int32_t index_of_on_wait;
	int32_t index_of_on_tick;
	int32_t index_of_on_draw;
	int32_t index_of_on_destroy;
	int32_t index_of_on_switch;
	int32_t index_of_on_copy_1;
	int32_t index_of_on_copy_2;
	int32_t index_of_sprite_mapping_func;
	Float3 position_3;
	void* associated_game_entity;
	Float3 rotation_related;
};
ValidateFieldOffset(0x0,	AnmVMSuffix, id);
ValidateFieldOffset(0x4,	AnmVMSuffix, fast_id);
ValidateFieldOffset(0x8,	AnmVMSuffix, time_in_script);
ValidateFieldOffset(0x1C,	AnmVMSuffix, unknown_timer_A);
ValidateFieldOffset(0x30,	AnmVMSuffix, node_in_global_list);
ValidateFieldOffset(0x40,	AnmVMSuffix, node_as_child);
ValidateFieldOffset(0x50,	AnmVMSuffix, list_of_children);
ValidateFieldOffset(0x60,	AnmVMSuffix, weird_list);
ValidateFieldOffset(0x70,	AnmVMSuffix, next_in_layer);
ValidateFieldOffset(0x74,	AnmVMSuffix, unknown_int_A);
ValidateFieldOffset(0x78,	AnmVMSuffix, maybe_root_vm);
ValidateFieldOffset(0x7C,	AnmVMSuffix, parent_vm);
ValidateFieldOffset(0x80,	AnmVMSuffix, slowdown);
ValidateFieldOffset(0x84,	AnmVMSuffix, special_vertex_buffer_data);
ValidateFieldOffset(0x88,	AnmVMSuffix, special_vertex_buffer_size);
ValidateFieldOffset(0x8C,	AnmVMSuffix, index_of_on_wait);
ValidateFieldOffset(0x90,	AnmVMSuffix, index_of_on_tick);
ValidateFieldOffset(0x94,	AnmVMSuffix, index_of_on_draw);
ValidateFieldOffset(0x98,	AnmVMSuffix, index_of_on_destroy);
ValidateFieldOffset(0x9C,	AnmVMSuffix, index_of_on_switch);
ValidateFieldOffset(0xA0,	AnmVMSuffix, index_of_on_copy_1);
ValidateFieldOffset(0xA4,	AnmVMSuffix, index_of_on_copy_2);
ValidateFieldOffset(0xA8,	AnmVMSuffix, index_of_sprite_mapping_func);
ValidateFieldOffset(0xAC,	AnmVMSuffix, position_3);
ValidateFieldOffset(0xB8,	AnmVMSuffix, associated_game_entity);
ValidateFieldOffset(0xBC,	AnmVMSuffix, rotation_related);

struct AnmVM {
	AnmVMPrefix p;
	AnmVMSuffix s;
};
ValidateFieldOffset(0x0,	AnmVM, p);
ValidateFieldOffset(0x544,	AnmVM, s);

typedef struct AnmManager AnmManager;
struct AnmManager {
	uintptr_t temp = 12;

	noinline AnmVM* __thiscall get_vm_with_id(AnmID ID) {
		assume_all_registers_volatile();
		return (AnmVM*)(this->temp + ID);
	}
};

static AnmManager *volatile static_anm_manager_ptr = new AnmManager;

typedef struct PlayerOption PlayerOption;
struct PlayerOption {
	unknown_fields(0xF0);
};

typedef struct PlayerBullet PlayerBullet;
struct PlayerBullet {
	unknown_fields(0xF8);
};

typedef struct PlayerDamageSource PlayerDamageSource;
struct PlayerDamageSource {
	unknown_fields(0x9C);
};

typedef struct PlayerInner PlayerInner;
struct PlayerInner {
	unknown_fields(0x50);
	PlayerOption options[4];
	PlayerOption equipment[12];
	PlayerBullet bullets[512];
	int32_t last_created_damage_source_index;
	PlayerDamageSource damage_sources[1025];
	unknown_fields(0x9C);
	int32_t state;
	unknown_fields(0x20);
	Timer shoot_key_short_timer;
	Timer shoot_key_long_timer;
	unknown_fields(0xA4);
	union {
		uint32_t flags;
		struct {
			unknown_bitfields(uint32_t, 5);
			uint32_t unknown_flag_A : 1;
		};
	};
	unknown_fields(0x168);
	int32_t num_deathbomb_frames;
	unknown_fields(0x18);
};
ValidateFieldOffset(0x50,		PlayerInner, options);
ValidateFieldOffset(0x410,		PlayerInner, equipment);
ValidateFieldOffset(0xF50,		PlayerInner, bullets);
ValidateFieldOffset(0x1FF50,	PlayerInner, last_created_damage_source_index);
ValidateFieldOffset(0x1FF54,	PlayerInner, damage_sources);
ValidateFieldOffset(0x4708C,	PlayerInner, state);
ValidateFieldOffset(0x470B0,	PlayerInner, shoot_key_short_timer);
ValidateFieldOffset(0x470C4,	PlayerInner, shoot_key_long_timer);
ValidateFieldOffset(0x4717C,	PlayerInner, flags);
ValidateFieldOffset(0x472E8,	PlayerInner, num_deathbomb_frames);

typedef struct Player Player;
struct Player {
	unknown_fields(0x14);
	AnmVM vm;
	PlayerInner inner;
	unknown_fields(0x28);
	InterpFloat scale_interp;
	float scale;
	float damage_multiplier;
	unknown_fields(0x4);
	float might_be_attract_speed;
	float item_collect_radius;
	float item_attract_radius_focused;
	float item_attract_radius_unfocused;
	float poc_height;
	float unknown_float_A;
	float unknown_float_B;
	float unknown_float_C;
	float unknown_float_D;
	float unknown_float_E;
	float unknown_float_F;
	float unknown_float_G;
	float unknown_float_H;
	unknown_fields(0x18);
};
ValidateFieldOffset(0x14,		Player, vm);
ValidateFieldOffset(0x620,		Player, inner);
ValidateFieldOffset(0x4794C,	Player, scale_interp);
ValidateFieldOffset(0x4797C,	Player, scale);
ValidateFieldOffset(0x47980,	Player, damage_multiplier);
ValidateFieldOffset(0x47988,	Player, might_be_attract_speed);
ValidateFieldOffset(0x4798C,	Player, item_collect_radius);
ValidateFieldOffset(0x47990,	Player, item_attract_radius_focused);
ValidateFieldOffset(0x47994,	Player, item_attract_radius_unfocused);
ValidateFieldOffset(0x47998,	Player, poc_height);
ValidateFieldOffset(0x4799C,	Player, unknown_float_A);
ValidateFieldOffset(0x479A0,	Player, unknown_float_B);
ValidateFieldOffset(0x479A4,	Player, unknown_float_C);
ValidateFieldOffset(0x479A8,	Player, unknown_float_D);
ValidateFieldOffset(0x479AC,	Player, unknown_float_E);
ValidateFieldOffset(0x479B0,	Player, unknown_float_F);
ValidateFieldOffset(0x479B4,	Player, unknown_float_G);
ValidateFieldOffset(0x479B8,	Player, unknown_float_H);

Player* static_player_ptr;

typedef struct EnemyFull EnemyFull;
typedef struct Enemy Enemy;

typedef struct BulletEx BulletEx;
struct BulletEx {
	float r;
	float s;
	float m;
	float n;
	int32_t a;
	int32_t b;
	int32_t c;
	int32_t d;
	int32_t type;
	int32_t async;
	char* string;
};

typedef struct BulletMgr BulletMgr;
struct BulletMgr {
	int32_t type;
	int32_t color;
	Float3 unknown_float3_A;
	float angle_aim;
	float angle_between;
	float speed_first;
	float speed_last;
	float distance;
	BulletEx ex[18];
	unknown_fields(0x10);
	int32_t laser_time_start;
	int32_t laser_trans_1;
	int32_t laser_duration;
	int32_t laser_trans_2;
	int32_t laser_time_end;
	int16_t cnt_count;
	int16_t cnt_layers;
	int32_t aim_type;
	int32_t sound_flag;
	int32_t shot_sound;
	int32_t shot_transform_sound;
	int32_t start_transform;
	int32_t unknown_int_A;
};

typedef struct BulletOffset BulletOffset;
struct BulletOffset {
	Float2 xy;
	float unknown_float_A;
};

typedef struct EnemyLife EnemyLife;
struct EnemyLife {
	int32_t current;
	int32_t maximum;
	int32_t remaining_current_attack;
	int32_t current_scaled_by_seven;
	int32_t starting_value_for_next_attack;
	int32_t total_damage_including_ignored;
	int32_t is_spell;
};

typedef struct EnemyDrop EnemyDrop;
struct EnemyDrop {
	int32_t main_drop;
	int32_t ex_drop[34];
	float width;
	float height;
};

typedef struct EnemyInterrupt EnemyInterrupt;
struct EnemyInterrupt {
	int32_t hp_value;
	int32_t time;
	char sub_name_1[64];
	char sub_name_2[64];
};

typedef struct EnemyFog EnemyFog;
struct EnemyFog {
	void* fog_ptr;
	unknown_fields(0x4);
	float fog_radius;
	float unknown_float_A;
	int32_t fog_color;
	float unknown_angle_A;
	float unknown_angle_B;
};

// 0x4CCBF0
static float game_speed;

static float* time_scaling_table[] = { &game_speed };
static inline constexpr size_t length_of_time_scaling_table = countof(time_scaling_table);

inline float* get_time_scale(size_t& index) {
	size_t scaling_index = index;
	if (scaling_index >= length_of_time_scaling_table) {
		scaling_index = index = (length_of_time_scaling_table - 1);
	}
	return time_scaling_table[scaling_index];
}

struct Enemy {
	PosVel prev_final_position;
	PosVel final_position;
	PosVel abs_position;
	PosVel rel_position;
	Float2 hurtbox_size;
	Float2 hitbox_size;
	float hurtbox_rotation;
	AnmID anm_vm_ids[16];
	Float3 anm_positions[16];
	AnmID unknown_anm_ids_A[16];
	int32_t selected_anm_index;
	int32_t anm_slot_0_anm_index;
	int32_t anm_slot_0_script;
	int32_t anm_main;
	int32_t probably_cur_subscript_for_anm_main;
	int32_t ecl_unknown_550;
	int32_t anm_layers;
	Float3 position_of_last_damage_source_to_hit;
	int32_t ecl_int_vars[4];
	float ecl_float_vars[8];
	Timer ecl_time;
	Timer time_alive;
	float slowdown;
	ZUNLinkedList<EnemyFull> node_in_global_storage;
	InterpStrange1 abs_position_interp;
	InterpStrange1 rel_position_interp;
	InterpFloat abs_angle_interp;
	InterpFloat abs_speed_interp;
	InterpFloat rel_angle_interp;
	InterpFloat rel_speed_interp;
	InterpFloat2 abs_radial_dist_interp;
	InterpFloat2 rel_radial_dist_interp;
	InterpFloat2 abs_ellipse_interp;
	InterpFloat2 rel_ellipse_interp;
	BulletMgr bullet_mgrs[16];
	int32_t et_ex_indices[16];
	BulletOffset bullet_mgr_offsets[16];
	BulletOffset bullet_mgr_origins[16];
	Float2 final_sprite_size;
	Float2 move_limit_center;
	Float2 move_limit_size;
	int32_t score_reward;
	EnemyLife life;
	EnemyDrop drop;
	int32_t some_kind_of_extra_damage;
	int32_t death_sound;
	int32_t death_anm_script;
	int32_t death_anm_index;
	int32_t frames_before_next_hurt_fx;

	// This field wasn't in WBaWC and I don't really know where it is relative to the other fields
	// For now I'm just making sure it's located at the correct offset relative to the invuln_timer
	Timer timer_50B8;
	unknown_fields(0x30);

	unknown_fields(0x4);
	int32_t hit_sound;
	Timer invuln_timer;
	Timer no_hitbox_timer;
	Timer unknown_timer_A;
	float bomb_damage_multiplier;
	union {
		uint32_t flags_low;
		struct {
			unknown_bitfields(uint32_t, 18);
			uint32_t unknown_flag_A : 1;		/*00040000*/
			unknown_bitfields(uint32_t, 6);
			uint32_t unknown_flag_B : 1;		/*02000000*/
			uint32_t unknown_flag_D : 1;		/*04000000*/
		};
	};
	union {
		uint32_t flags_high;
		struct {
			uint32_t unknown_flag_C : 1;		/*00000001*/
		};
	};
	int32_t bombshield_on_anm_main;
	int32_t bombshield_off_anm_main;
	int32_t own_boss_id;
	float et_protect_range;
	EnemyInterrupt interrupts[8];
	EnemyFull* full;
	EnemyFog fog;
	char set_death[64];
	int32_t(__thiscall *ecl_func_set_A_func)(Enemy*);
	uint32_t is_func_set_2;
	void* ecl_func_set_B_func;
	void* ecl_func_set_C_func;
	int32_t own_chapter;
	int32_t ecl_570_bool;

	noinline int32_t step_interpolators(void) {
		assume_all_registers_volatile(this);
		static volatile int32_t ret;
		return (int32_t)ret;
	}

	noinline int32_t update(void);

	noinline int32_t step_game_logic(void);

	noinline void update_fog(void);
};
ValidateFieldOffset(0x0,	Enemy, prev_final_position);
ValidateFieldOffset(0x44,	Enemy, final_position);
ValidateFieldOffset(0x88,	Enemy, abs_position);
ValidateFieldOffset(0xCC,	Enemy, rel_position);
ValidateFieldOffset(0x110,	Enemy, hurtbox_size);
ValidateFieldOffset(0x118,	Enemy, hitbox_size);
ValidateFieldOffset(0x120,	Enemy, hurtbox_rotation);
ValidateFieldOffset(0x124,	Enemy, anm_vm_ids);
ValidateFieldOffset(0x164,	Enemy, anm_positions);
ValidateFieldOffset(0x224,	Enemy, unknown_anm_ids_A);
ValidateFieldOffset(0x264,	Enemy, selected_anm_index);
ValidateFieldOffset(0x268,	Enemy, anm_slot_0_anm_index);
ValidateFieldOffset(0x26C,	Enemy, anm_slot_0_script);
ValidateFieldOffset(0x270,	Enemy, anm_main);
ValidateFieldOffset(0x274,	Enemy, probably_cur_subscript_for_anm_main);
ValidateFieldOffset(0x278,	Enemy, ecl_unknown_550);
ValidateFieldOffset(0x27C,	Enemy, anm_layers);
ValidateFieldOffset(0x280,	Enemy, position_of_last_damage_source_to_hit);
ValidateFieldOffset(0x28C,	Enemy, ecl_int_vars);
ValidateFieldOffset(0x29C,	Enemy, ecl_float_vars);
ValidateFieldOffset(0x2BC,	Enemy, ecl_time);
ValidateFieldOffset(0x2D0,	Enemy, time_alive);

typedef struct EclInstr EclInstr;
struct EclInstr {
	uint32_t time;
	uint16_t opcode;
	uint16_t offset_to_next;
	uint16_t param_mask;
	uint8_t difficulty_mask;
	uint8_t param_count;
	uint32_t stack_refs;
	unsigned char data[];
};
ValidateFieldOffset(0x0,	EclInstr, time);
ValidateFieldOffset(0x4,	EclInstr, opcode);
ValidateFieldOffset(0x6,	EclInstr, offset_to_next);
ValidateFieldOffset(0x8,	EclInstr, param_mask);
ValidateFieldOffset(0xA,	EclInstr, difficulty_mask);
ValidateFieldOffset(0xB,	EclInstr, param_count);
ValidateFieldOffset(0xC,	EclInstr, stack_refs);
ValidateFieldOffset(0x10,	EclInstr, data);


typedef struct EclSubHeader EclSubHeader;
struct EclSubHeader {
	int32_t magic;
	uint32_t data_offset;
	unknown_fields(0x8);
	unsigned char instructions[]; // Actually EclInstr[]
};
ValidateFieldOffset(0x0,	EclSubHeader, magic);
ValidateFieldOffset(0x4,	EclSubHeader, data_offset);
ValidateFieldOffset(0x10,	EclSubHeader, instructions);

typedef struct EclSubroutinePtr EclSubroutinePtr;
struct EclSubroutinePtr {
	char* name;
	EclSubHeader* sub_header;
};
ValidateFieldOffset(0x0,	EclSubroutinePtr, name);
ValidateFieldOffset(0x4,	EclSubroutinePtr, sub_header);

typedef struct EclFileManager EclFileManager;
struct EclFileManager {
	void* vtable;
	int32_t file_count;
	int32_t subroutine_count;
	void* file_data[0x20];
	EclSubroutinePtr (*subroutines)[];
};
ValidateFieldOffset(0x0,	EclFileManager, vtable);
ValidateFieldOffset(0x4,	EclFileManager, file_count);
ValidateFieldOffset(0x8,	EclFileManager, subroutine_count);
ValidateFieldOffset(0xC,	EclFileManager, file_data);
ValidateFieldOffset(0x8C,	EclFileManager, subroutines);

#define EclStackCount 0x400
#define EclStackSize sizeof(EclStackItem[EclStackCount])

typedef struct EclLocation EclLocation;
struct EclLocation {
	int32_t sub_index;
	int32_t instr_offset;
};
ValidateFieldOffset(0x0,	EclLocation, sub_index);
ValidateFieldOffset(0x4,	EclLocation, instr_offset);

typedef union EclStackItem EclStackItem;
union EclStackItem {
	int32_t integer;
	float real;
	char character;
};
ValidateFieldOffset(0x0,	EclStackItem, integer);
ValidateFieldOffset(0x0,	EclStackItem, real);
ValidateFieldOffset(0x0,	EclStackItem, character);

typedef struct EclRunContext EclRunContext;
struct EclRunContext {
	float time;
	int32_t current_sub_index;
	int32_t current_instr_offset;
	union {
		EclStackItem stack[EclStackCount];
		unsigned char stack_[EclStackSize];
	};
	int32_t stack_top_offset; // Like ESP
	int32_t stack_locals_offset; // Like EBP
	int32_t async_id;
	ZUNLinkedList<EclRunContext>* parent;
	unknown_fields(0x4);
	uint8_t current_difficulty_mask;
	probably_padding_bytes(0x3);
	InterpFloat float_interps[8];
	EclLocation float_interp_locations[8];
	unknown_fields(0x4);
};
ValidateFieldOffset(0x0,	EclRunContext, time);
ValidateFieldOffset(0x4,	EclRunContext, current_sub_index);
ValidateFieldOffset(0x8,	EclRunContext, current_instr_offset);
ValidateFieldOffset(0xC,	EclRunContext, stack);
ValidateFieldOffset(0x100C,	EclRunContext, stack_top_offset);
ValidateFieldOffset(0x1010,	EclRunContext, stack_locals_offset);
ValidateFieldOffset(0x1014,	EclRunContext, async_id);
ValidateFieldOffset(0x1018,	EclRunContext, parent);
ValidateFieldOffset(0x1020,	EclRunContext, current_difficulty_mask);
ValidateFieldOffset(0x1024,	EclRunContext, float_interps);
ValidateFieldOffset(0x11A4,	EclRunContext, float_interp_locations);

typedef struct EclRunContextHolder EclRunContextHolder;
struct EclRunContextHolder {
	EclRunContext* current_context;
	EclRunContext primary_context;
};
ValidateFieldOffset(0x0,	EclRunContextHolder, current_context);
ValidateFieldOffset(0x4,	EclRunContextHolder, primary_context);

typedef struct EnemyFullVTable EnemyFullVTable;
struct EnemyFullVTable {
	unknown_fields(0x14);
	void (__stdcall*unknown_func_A)(int32_t);
};



struct EnemyFull {
	EnemyFullVTable** vtable;
	/* ... */	void* next_in_some_list;
	/* ... */	void* prev_in_some_list;
	/* ... */	EclRunContextHolder context;
	/* ... */
	/*0x1218*/	EclFileManager* file_manager;
	/*0x121C*/	EclRunContext* primary_context;
	/*0x1220*/	ZUNLinkedList<EclRunContext>* async_context_list;
	/* ... */	void* unused_async_list_ptr_A;
	/* ... */	void* unused_async_list_ptr_B;
	/* ... */	unsigned char unknownA[4];
	/*0x122C*/	Enemy enemy_inner;
	/* ... */	void* on_death_callback;
	/* ... */	int32_t enemy_id;
	/* ... */	int32_t ecl_global_var_9909;
	/* ... */	uint32_t __field_572C;

	noinline int32_t update() {
		int32_t ret;
		float slowdown = this->enemy_inner.slowdown;
		if (0.0f >= slowdown) {
			if (this->enemy_inner.unknown_flag_C) {
				AnmID* anm_vm_id = this->enemy_inner.anm_vm_ids;
				size_t i = countof(this->enemy_inner.anm_vm_ids);
				do {
					AnmVM* vm = static_anm_manager_ptr->get_vm_with_id(*anm_vm_id);
					if (!vm) {
						*anm_vm_id = NULL;
					} else {
						vm->s.slowdown = 0.0f;
					}
					++anm_vm_id;
				} while (--i);
			}
			ret = this->enemy_inner.update();
		}
		else {
			float local_game_speed = game_speed;
			AnmID* anm_vm_id = this->enemy_inner.anm_vm_ids;
			slowdown *= local_game_speed;
			size_t i = countof(this->enemy_inner.anm_vm_ids);
			game_speed = confine_to_range(0.0f, local_game_speed - slowdown, 1.0f);
			do {
				AnmVM* vm = static_anm_manager_ptr->get_vm_with_id(*anm_vm_id);
				if (!vm) {
					*anm_vm_id = NULL;
				} else {
					vm->s.slowdown = this->enemy_inner.slowdown;
				}
				++anm_vm_id;
			} while (--i);
			ret = this->enemy_inner.update();
			game_speed = local_game_speed;
			this->enemy_inner.unknown_flag_C = true;
		}
		return ret;
	}

	noinline int32_t ecl_run(float current_gamespeed) {
		assume_all_registers_volatile(this);
		return 1 + current_gamespeed + (uintptr_t)this;
	}
};
ValidateFieldOffset(0x0,	EnemyFull, vtable);
ValidateFieldOffset(0x4,	EnemyFull, next_in_some_list);
ValidateFieldOffset(0x8,	EnemyFull, prev_in_some_list);

noinline void Enemy::update_fog(void) {
	if (this->fog.fog_ptr) {
		assume_all_registers_volatile(this);
	}
}

noinline int32_t Enemy::step_game_logic(void) {
	assume_all_registers_volatile(this);
	return 0;
}

noinline int32_t Enemy::update(void) {
	if (!this->unknown_flag_A) {
		this->unknown_flag_A = true;
		if (this->step_interpolators()) {
			return -1;
		}
		if (this->full->ecl_run(*time_scaling_table[this->ecl_time.scale_table_index])) {
			return -1;
		}
		if (this->ecl_func_set_A_func != NULL) {
			if (this->ecl_func_set_A_func(this)) {
				return -1;
			}
		}
		if (this->step_game_logic()) {
			return -1;
		}
		this->update_fog();

		AnmID* anm_vm_id = this->anm_vm_ids;

		// Anything less awful than this gets optimized to better code than the original
		static constexpr size_t offset_to_other_ids = offsetof(Enemy, unknown_anm_ids_A) - offsetof(Enemy, anm_vm_ids);

		if (!this->unknown_flag_D) {
			size_t i = 14;
			Float3* anm_pos = this->anm_positions;
			do {
				AnmVM* vm = static_anm_manager_ptr->get_vm_with_id(*anm_vm_id);
				if (!vm) {
					*anm_vm_id = NULL;
				} else {
					Float3 temp_pos = {
						.x = anm_pos->x + this->final_position.position.x,
						.y = anm_pos->y + this->final_position.position.y,
						.z = anm_pos->z + this->final_position.position.z
					};
					int32_t anm_vm_id_index = *(AnmID*)((uintptr_t)anm_vm_id + offset_to_other_ids);
					if (anm_vm_id_index >= 0) {
						AnmVM* other_vm = static_anm_manager_ptr->get_vm_with_id(this->anm_vm_ids[anm_vm_id_index]);
						if (!other_vm) {
							this->anm_vm_ids[*(AnmID*)((uintptr_t)anm_vm_id + offset_to_other_ids)] = NULL;
						} else {
							temp_pos.x += other_vm->p.position.x;
							temp_pos.y += other_vm->p.position.y;
							temp_pos.z += other_vm->p.position.z;
						}
					}
					// Somehow the compiler wasn't able to optimize this assignment in the original
					// and I have no idea how to confuse the compiler enough to produce that code
					vm->s.position_3 = temp_pos;
					if (vm->p.unknown_flag_B) {
						float angle = atan2_wrapper(this->final_position.maybe_velocity.y, this->final_position.maybe_velocity.x);
						vm->p.unknown_flag_A = true;
						vm->p.rotation.z = angle;
						this->hurtbox_rotation = angle;
					}
				}
				++anm_pos;
				++anm_vm_id;
			} while (--i);
		} else {
			size_t i = 14;
			do {
				AnmVM* vm = static_anm_manager_ptr->get_vm_with_id(*anm_vm_id);
				if (!vm) {
					*anm_vm_id = NULL;
				} else {
					vm->s.position_3 = this->final_position.position;
				}
				++anm_vm_id;
			} while (--i);
		}
		this->timer_50B8.increment(1.0f); // This call should be inlined, but doesn't want to
		if (this->invuln_timer.current > 0) {
			this->invuln_timer.decrement(1.0f);
		}
		if (this->no_hitbox_timer.current > 0) {
			this->no_hitbox_timer.decrement(1.0f);
		}
		this->time_alive.increment(1.0f);
		this->ecl_time.increment(1.0f);
		return 0;
	}
}

// Differences from the unknown jank of the original:
// -
void Timer::increment(float) {

	float* time_scale_ptr = get_time_scale(this->scale_table_index);

	int32_t current_time = this->current;
	this->previous = current_time;

	float time_scale;

	/*if (time_scale_ptr && (!(*time_scale_ptr > 0.99f) || !(1.01f > *time_scale_ptr))) {
		time_scale = *time_scale_ptr + this->current_f;
		current_time = (int32_t)time_scale;
	} else {
		time_scale = this->current_f + 1.0f;
		current_time++;
	}*/

	// For some reason this block produces very different (and better) code than
	// the original game unless this one goto is used.
	if (time_scale_ptr && (!(*time_scale_ptr > 0.99f) || !(1.01f > *time_scale_ptr))) {
		time_scale = *time_scale_ptr + this->current_f;
		current_time = (int32_t)time_scale;
		goto SetTime;
	}
	time_scale = this->current_f + 1.0f;
	current_time++;
SetTime:
	this->current_f = time_scale;
	this->current = current_time;
	return;
}

void Timer::increment_2() {

	float* time_scale_ptr = get_time_scale(this->scale_table_index);
	int32_t current_time = this->current;
	this->previous = current_time;
	float time_scale;
	if (time_scale_ptr != NULL) {
		time_scale = *time_scale_ptr;
		if (!(time_scale > 0.99f) || !(1.01f > time_scale)) {
			this->current = (int32_t)(this->current_f += time_scale);
			return;
		}
	}
	this->current_f += 1.0f;
	this->current = ++current_time;
	return;
}

void Timer::decrement(float) {
	
	float* time_scale_ptr = get_time_scale(this->scale_table_index);

	int32_t current_time = this->current;
	this->previous = current_time;

	float time_scale;
	if (time_scale_ptr && (!(*time_scale_ptr > 0.99f) || !(1.01f > *time_scale_ptr))) {
		time_scale = this->current_f - *time_scale_ptr * 1.0f;
		current_time = (int32_t)time_scale;
		goto SetTime;
	}
	time_scale = this->current_f - 1.0f;
SetTime:
	this->current = this->current_f = time_scale;
	return;

	/*float* time_scale_ptr = get_time_scale(this->scale_table_index);
	int32_t current_time = this->current;
	this->previous = current_time;
	float time_scale;
	if (time_scale_ptr != NULL) {
		time_scale = *time_scale_ptr;
		if (!(time_scale > 0.99f) || 1.01f <= time_scale) {
			time_scale *= default_scale;
			this->current = (int32_t)(this->current_f -= time_scale);
			return;
		}
	}
	this->current = (int32_t)(this->current_f -= default_scale);
	return;*/
}

typedef struct EnemyManager EnemyManager;
struct EnemyManager {

	unknown_fields(0x4);
	void* on_tick_func;
	void* on_draw_func;
	int32_t ecl_global_ints[4];
	float ecl_global_floats[8];
	int32_t miss_count;
	int32_t bomb_count;
	int32_t can_still_capture_spell;
	int32_t boss_ids[4];
	unknown_fields(0x34);
	int32_t enemy_limit;
	unknown_fields(0x4);
	int32_t last_enemy_id;
	Timer time_in_stage;
	int32_t unknown_dword_A;
	int32_t unknown_dword_B;
	unknown_fields(0xB0);
	void* anms_in_anim_list[6];
	unknown_fields(0x4);

	unknown_fields(0xC);
	ZUNLinkedList<EnemyFull>* active_enemy_list_head;
	ZUNLinkedList<EnemyFull>* active_enemy_list_tail;
	unknown_fields(0x4);
	int32_t enemy_count_real;
	unknown_fields(0x4);

	noinline int on_tick() {
		GameThread* game_thread_ptr = static_game_thread_ptr;
		if (game_thread_ptr != NULL &&
			!(game_thread_ptr->skip_flag | game_thread_ptr->unknown_flag_A) &&
			!game_thread_ptr->unknown_flag_C &&
			!game_thread_ptr->unknown_flag_B &&
			static_ability_shop_ptr == NULL
		) {
			ZUNLinkedList<EnemyFull>* enemy_list = this->active_enemy_list_head;
			this->unknown_dword_A = 0;
			this->unknown_dword_B = 0;
			while (enemy_list) {
				ZUNLinkedList<EnemyFull>* next_enemy_list = enemy_list->next;
				if (!enemy_list->data->enemy_inner.unknown_flag_B && !enemy_list->data->update()) {
					enemy_list->data->enemy_inner.unknown_flag_A = 0;
				}
				else if (enemy_list->data->vtable) {
					(*enemy_list->data->vtable)->unknown_func_A(1);
				}
				enemy_list = next_enemy_list;
			}
			if (static_player_ptr->damage_multiplier > 1.01f) {
				static_player_ptr->inner.unknown_flag_A = 1;
			} else {
				static_player_ptr->inner.unknown_flag_A = 0;
			}
			static_player_ptr->damage_multiplier = 1.0f;
			this->time_in_stage.increment(1.0f);
		}
		return 1;
	}
};
ValidateFieldOffset(0x98,	EnemyManager, time_in_stage);
ValidateFieldOffset(0xA4,	EnemyManager, time_in_stage.scale_table_index);
ValidateFieldOffset(0xAC,	EnemyManager, unknown_dword_A);
ValidateFieldOffset(0xB0,	EnemyManager, unknown_dword_B);
ValidateFieldOffset(0x18C,	EnemyManager, active_enemy_list_head);


void dummy_for_types() {
	Float2 yeetus;
	yeetus.make_coords_from_vector(5.0f, 2.0f);
	EnemyManager test;
	test.on_tick();
}