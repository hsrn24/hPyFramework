#ifdef __cplusplus
extern "C" {
#endif
#include "py/nlr.h"
#include "py/parse.h"
#include "py/compile.h"
#include "py/runtime.h"
#include "py/repl.h"
#include "py/nlr.h"
#include "py/runtime.h"
#include "py/binary.h"

void reg();

extern const qstr_pool_t hpyframework_pool;
#ifdef __cplusplus
}
#endif

enum
{
	start = MP_QSTR_number_of - 1,
	MP_QSTR_hMot1,
	MP_QSTR_hMot2,
	MP_QSTR_hMot3,
	MP_QSTR_hMot4,
	MP_QSTR_hMot5,
	MP_QSTR_hMot6,
	MP_QSTR_hSystem,
	MP_QSTR_delay_ms,
	MP_QSTR_delay_us,
	MP_QSTR_hMotor,
	MP_QSTR_setPower,
	MP_QSTR_rotAbs,
	MP_QSTR_setParallelMode,
	MP_QSTR_setSingleMode,
	MP_QSTR_hPyFramework_number_of,
};

#ifdef __cplusplus
extern "C" {
#endif
mp_obj_t hSystem_delay_ms(mp_obj_t self_in, mp_obj_t arg0);
mp_obj_t hSystem_delay_us(mp_obj_t self_in, mp_obj_t arg0);
mp_obj_t hMotor_setPower(mp_obj_t self_in, mp_obj_t arg0);
mp_obj_t hMotor_rotAbs(mp_obj_t self_in, mp_obj_t arg0);
mp_obj_t hMotor_setParallelMode(mp_obj_t self_in);
mp_obj_t hMotor_setSingleMode(mp_obj_t self_in);

#ifdef __cplusplus
}
#endif

typedef struct _mp_obj_hSystem_t
{
	mp_obj_base_t base;
	void *hObj;
} mp_obj_hSystem_t;

typedef struct _mp_obj_hMotor_t
{
	mp_obj_base_t base;
	void *hObj;
} mp_obj_hMotor_t;
