#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#include "py/nlr.h"
#include "py/parse.h"
#include "py/compile.h"
#include "py/runtime.h"
#include "py/repl.h"
#include "py/nlr.h"
#include "py/runtime.h"
#include "py/binary.h"

#include "gen.h"

enum
{
	start = MP_QSTR_number_of - 1,
#define QDEF(id, str) id,
#include "qstrgen.h"
#undef QDEF
	MP_QSTR_kd_number_of,
};

const qstr_pool_t kd_pool =
{
	&const_pool,
	MP_QSTR_number_of,
	8, // set so that the first dynamically allocated pool is twice this size; must be <= the len (just below)
	8, // corresponds to number of strings in array just below
	{
#define QDEF(id, str) str,
#include "qstrgen.h"
#undef QDEF
	},
};

void gc_collect()
{
}

static mp_obj_t pyb_help(void)
{
	printf("%s", "ASD\r\n");
	return mp_const_none;
}
mp_obj_t robocore_setPower(mp_obj_t o_val);
STATIC MP_DEFINE_CONST_FUN_OBJ_1(robocore_setPower_obj, robocore_setPower);


mp_obj_t match_group(mp_obj_t self_in, mp_obj_t no_in);
MP_DEFINE_CONST_FUN_OBJ_2(match_group_obj, match_group);

STATIC const mp_map_elem_t match_locals_dict_table[] =
{
	{ MP_OBJ_NEW_QSTR(MP_QSTR_setPower), (mp_obj_t) &match_group_obj },
};

STATIC MP_DEFINE_CONST_DICT(match_locals_dict, match_locals_dict_table);

STATIC const mp_obj_type_t match_type =
{
	.base = { &mp_type_type },
	.name = MP_QSTR_match,
	.print = 0,
	.locals_dict = (mp_obj_t)&match_locals_dict,
};


// STATIC mp_obj_t mod_setPower(mp_obj_t o_val)
// {
// mp_int_t val = mp_obj_get_int(o_val);
// printf("ASD222 %d\r\n", val);
// // hMot.setPower(val);

// mp_obj_hMotor_t *match = m_new_obj_var(mp_obj_hMotor_t, char*, 0);
// match->base.type = &match_type;
// // match->str = "KD";

// return match;
// }
// STATIC MP_DEFINE_CONST_FUN_OBJ_1(mod_get_setPower, mod_setPower);






// STATIC const mp_map_elem_t mp_module_re_globals_table[] =
// {
// { MP_OBJ_NEW_QSTR(MP_QSTR___name__), MP_OBJ_NEW_QSTR(MP_QSTR_f2) },
// { MP_OBJ_NEW_QSTR(MP_QSTR_setPower), (mp_obj_t)&mod_get_setPower },
// // { MP_OBJ_NEW_QSTR(MP_QSTR_match), (mp_obj_t)&mod_re_match_obj },
// // { MP_OBJ_NEW_QSTR(MP_QSTR_search), (mp_obj_t)&mod_re_search_obj },
// // { MP_OBJ_NEW_QSTR(MP_QSTR_DEBUG), MP_OBJ_NEW_SMALL_INT(FLAG_DEBUG) },
// };
// STATIC MP_DEFINE_CONST_DICT(mp_module_re_globals, mp_module_re_globals_table);


// const mp_obj_module_t mp_module_ure =
// {
// .base = { &mp_type_module },
// .name = MP_QSTR_f1,
// .globals = (mp_obj_dict_t*)&mp_module_re_globals,
// };


void reg()
{
	// mp_store_name(QSTR_FROM_STR_STATIC("AA"), (mp_obj_t)&mp_module_ure);
	
	qstr_add_const_pool(&kd_pool);
	
	mp_obj_hMotor_t *match = m_new_obj_var(mp_obj_hMotor_t, char*, 0);
	match->motorNum = 1;
	match->base.type = &match_type;
	
	mp_store_name(QSTR_FROM_STR_STATIC("hMot1"), (mp_obj_t)match);
	
	match = m_new_obj_var(mp_obj_hMotor_t, char*, 0);
	match->motorNum = 2;
	match->base.type = &match_type;
	
	mp_store_name(QSTR_FROM_STR_STATIC("hMot2"), (mp_obj_t)match);
	// mp_store_name(QSTR_FROM_STR_STATIC("QQ"), mp_obj_new_str("qwe", 3, false));
}
