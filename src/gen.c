#include "gen.h"


const qstr_pool_t hpyframework_pool =
{
	&const_pool,
	MP_QSTR_number_of,
	3, // set so that the first dynamically allocated pool is twice this size; must be <= the len (just below)
	14, // corresponds to number of strings in array just below
	{
		(const byte*)"\x8a\x68\x05" "hMot1",
		(const byte*)"\x89\x68\x05" "hMot2",
		(const byte*)"\x88\x68\x05" "hMot3",
		(const byte*)"\x8f\x68\x05" "hMot4",
		(const byte*)"\x8e\x68\x05" "hMot5",
		(const byte*)"\x8d\x68\x05" "hMot6",
		(const byte*)"\x48\xf6\x07" "hSystem",
		(const byte*)"\xb1\x87\x08" "delay_ms",
		(const byte*)"\xa9\x8a\x08" "delay_us",
		(const byte*)"\x26\x83\x06" "hMotor",
		(const byte*)"\xd8\x3d\x08" "setPower",
		(const byte*)"\x3c\x1d\x06" "rotAbs",
		(const byte*)"\x6f\x62\x0f" "setParallelMode",
		(const byte*)"\xbe\x4f\x0d" "setSingleMode",
	},
};

mp_obj_t hSystem_delay_ms(mp_obj_t self_in, mp_obj_t arg0);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hSystem_delay_ms_obj, 2, 2, hSystem_delay_ms);
mp_obj_t hSystem_delay_us(mp_obj_t self_in, mp_obj_t arg0);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hSystem_delay_us_obj, 2, 2, hSystem_delay_us);

STATIC const mp_map_elem_t hSystem_locals_dict_table[] =
{
	{ MP_OBJ_NEW_QSTR(MP_QSTR_delay_ms), (mp_obj_t)&hSystem_delay_ms_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_delay_us), (mp_obj_t)&hSystem_delay_us_obj },
};
STATIC MP_DEFINE_CONST_DICT(hSystem_locals_dict, hSystem_locals_dict_table);
const mp_obj_type_t hSystem_type =
{
	.base = { &mp_type_type },
	.name = MP_QSTR_hSystem,
	.print = 0,
	.locals_dict = (mp_obj_t)&hSystem_locals_dict,
};

mp_obj_t hMotor_setPower(mp_obj_t self_in, mp_obj_t arg0);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hMotor_setPower_obj, 2, 2, hMotor_setPower);
mp_obj_t hMotor_rotAbs(mp_obj_t self_in, mp_obj_t arg0);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hMotor_rotAbs_obj, 2, 2, hMotor_rotAbs);
mp_obj_t hMotor_setParallelMode(mp_obj_t self_in);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hMotor_setParallelMode_obj, 1, 1, hMotor_setParallelMode);
mp_obj_t hMotor_setSingleMode(mp_obj_t self_in);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hMotor_setSingleMode_obj, 1, 1, hMotor_setSingleMode);

STATIC const mp_map_elem_t hMotor_locals_dict_table[] =
{
	{ MP_OBJ_NEW_QSTR(MP_QSTR_setPower), (mp_obj_t)&hMotor_setPower_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_rotAbs), (mp_obj_t)&hMotor_rotAbs_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_setParallelMode), (mp_obj_t)&hMotor_setParallelMode_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_setSingleMode), (mp_obj_t)&hMotor_setSingleMode_obj },
};
STATIC MP_DEFINE_CONST_DICT(hMotor_locals_dict, hMotor_locals_dict_table);
const mp_obj_type_t hMotor_type =
{
	.base = { &mp_type_type },
	.name = MP_QSTR_hMotor,
	.print = 0,
	.locals_dict = (mp_obj_t)&hMotor_locals_dict,
};
