#include "gen.h"


qstr_pool_t hpyframework_pool =
{
	0,
	0,
	3, // set so that the first dynamically allocated pool is twice this size; must be <= the len (just below)
	29, // corresponds to number of strings in array just below
	0x05000000,
	{
		(const byte*)"\xb9\x6d\x04" "LED1",
		(const byte*)"\xba\x6d\x04" "LED2",
		(const byte*)"\xbb\x6d\x04" "LED3",
		(const byte*)"\x8a\x68\x05" "hMot1",
		(const byte*)"\x89\x68\x05" "hMot2",
		(const byte*)"\x88\x68\x05" "hMot3",
		(const byte*)"\x8f\x68\x05" "hMot4",
		(const byte*)"\x8e\x68\x05" "hMot5",
		(const byte*)"\x8d\x68\x05" "hMot6",
		(const byte*)"\x64\x9b\x05" "hBtn1",
		(const byte*)"\x67\x9b\x05" "hBtn2",
		(const byte*)"\x48\xf6\x07" "hSystem",
		(const byte*)"\xb1\x87\x08" "delay_ms",
		(const byte*)"\xa9\x8a\x08" "delay_us",
		(const byte*)"\xc0\xb3\x04" "hLED",
		(const byte*)"\x64\x6f\x02" "on",
		(const byte*)"\x8a\x5c\x03" "off",
		(const byte*)"\xb7\x43\x06" "toggle",
		(const byte*)"\x26\x83\x06" "hMotor",
		(const byte*)"\xd8\x3d\x08" "setPower",
		(const byte*)"\x3c\x1d\x06" "rotAbs",
		(const byte*)"\x6f\x62\x0f" "setParallelMode",
		(const byte*)"\xbe\x4f\x0d" "setSingleMode",
		(const byte*)"\x5d\x45\x0f" "resetEncoderCnt",
		(const byte*)"\x3e\x48\x0d" "getEncoderCnt",
		(const byte*)"\x9b\x48\x07" "hButton",
		(const byte*)"\x99\x2f\x09" "isPressed",
		(const byte*)"\xd3\x27\x0e" "waitForPressed",
		(const byte*)"\x58\x62\x0f" "waitForReleased",
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

mp_obj_t hLED_on(mp_obj_t self_in);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hLED_on_obj, 1, 1, hLED_on);
mp_obj_t hLED_off(mp_obj_t self_in);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hLED_off_obj, 1, 1, hLED_off);
mp_obj_t hLED_toggle(mp_obj_t self_in);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hLED_toggle_obj, 1, 1, hLED_toggle);

STATIC const mp_map_elem_t hLED_locals_dict_table[] =
{
	{ MP_OBJ_NEW_QSTR(MP_QSTR_on), (mp_obj_t)&hLED_on_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_off), (mp_obj_t)&hLED_off_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_toggle), (mp_obj_t)&hLED_toggle_obj },
};
STATIC MP_DEFINE_CONST_DICT(hLED_locals_dict, hLED_locals_dict_table);
const mp_obj_type_t hLED_type =
{
	.base = { &mp_type_type },
	.name = MP_QSTR_hLED,
	.print = 0,
	.locals_dict = (mp_obj_t)&hLED_locals_dict,
};

mp_obj_t hMotor_setPower(mp_obj_t self_in, mp_obj_t arg0);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hMotor_setPower_obj, 2, 2, hMotor_setPower);
mp_obj_t hMotor_rotAbs(mp_obj_t self_in, mp_obj_t arg0);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hMotor_rotAbs_obj, 2, 2, hMotor_rotAbs);
mp_obj_t hMotor_setParallelMode(mp_obj_t self_in);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hMotor_setParallelMode_obj, 1, 1, hMotor_setParallelMode);
mp_obj_t hMotor_setSingleMode(mp_obj_t self_in);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hMotor_setSingleMode_obj, 1, 1, hMotor_setSingleMode);
mp_obj_t hMotor_resetEncoderCnt(mp_obj_t self_in);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hMotor_resetEncoderCnt_obj, 1, 1, hMotor_resetEncoderCnt);
mp_obj_t hMotor_getEncoderCnt(mp_obj_t self_in);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hMotor_getEncoderCnt_obj, 1, 1, hMotor_getEncoderCnt);

STATIC const mp_map_elem_t hMotor_locals_dict_table[] =
{
	{ MP_OBJ_NEW_QSTR(MP_QSTR_setPower), (mp_obj_t)&hMotor_setPower_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_rotAbs), (mp_obj_t)&hMotor_rotAbs_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_setParallelMode), (mp_obj_t)&hMotor_setParallelMode_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_setSingleMode), (mp_obj_t)&hMotor_setSingleMode_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_resetEncoderCnt), (mp_obj_t)&hMotor_resetEncoderCnt_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_getEncoderCnt), (mp_obj_t)&hMotor_getEncoderCnt_obj },
};
STATIC MP_DEFINE_CONST_DICT(hMotor_locals_dict, hMotor_locals_dict_table);
const mp_obj_type_t hMotor_type =
{
	.base = { &mp_type_type },
	.name = MP_QSTR_hMotor,
	.print = 0,
	.locals_dict = (mp_obj_t)&hMotor_locals_dict,
};

mp_obj_t hButton_isPressed(mp_obj_t self_in);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hButton_isPressed_obj, 1, 1, hButton_isPressed);
mp_obj_t hButton_waitForPressed(mp_obj_t self_in, mp_obj_t arg0);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hButton_waitForPressed_obj, 2, 2, hButton_waitForPressed);
mp_obj_t hButton_waitForReleased(mp_obj_t self_in, mp_obj_t arg0);
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(hButton_waitForReleased_obj, 2, 2, hButton_waitForReleased);

STATIC const mp_map_elem_t hButton_locals_dict_table[] =
{
	{ MP_OBJ_NEW_QSTR(MP_QSTR_isPressed), (mp_obj_t)&hButton_isPressed_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_waitForPressed), (mp_obj_t)&hButton_waitForPressed_obj },
	{ MP_OBJ_NEW_QSTR(MP_QSTR_waitForReleased), (mp_obj_t)&hButton_waitForReleased_obj },
};
STATIC MP_DEFINE_CONST_DICT(hButton_locals_dict, hButton_locals_dict_table);
const mp_obj_type_t hButton_type =
{
	.base = { &mp_type_type },
	.name = MP_QSTR_hButton,
	.print = 0,
	.locals_dict = (mp_obj_t)&hButton_locals_dict,
};
