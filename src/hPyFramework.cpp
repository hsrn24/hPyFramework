#include "hPyFramework.h"

extern "C" {
#include "py/nlr.h"
#include "py/parse.h"
#include "py/compile.h"
#include "py/runtime.h"
#include "py/repl.h"
#include "py/nlr.h"
#include "py/runtime.h"
#include "py/binary.h"
#include "py/gc.h"
}

#include <hFramework.h>
#include <stdio.h>

#include "gen.h"

extern "C" mp_obj_t robocore_setPower(mp_obj_t o_val)
{
	printf("%s", "ASD\r\n");
	// mp_int_t val = mp_obj_get_int(o_val);
	return mp_const_none;
}
extern "C" mp_obj_t match_group(mp_obj_t self_in, mp_obj_t no_in)
{
	mp_obj_hMotor_t *self = (mp_obj_hMotor_t*)self_in;
	mp_int_t val = mp_obj_get_int(no_in);
	switch (self->motorNum)
	{
	case 1: hMot1.setPower(val); break;
	case 2: hMot2.setPower(val); break;
	}
	printf("GROUP\r\n");
	return mp_const_none;
}

extern const mp_obj_module_t mp_module_ure;

void pyRegister()
{
}

