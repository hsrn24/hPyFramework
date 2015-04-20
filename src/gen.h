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
	MP_QSTR_LED1,
	MP_QSTR_LED2,
	MP_QSTR_LED3,
	MP_QSTR_hMot1,
	MP_QSTR_hMot2,
	MP_QSTR_hMot3,
	MP_QSTR_hMot4,
	MP_QSTR_hMot5,
	MP_QSTR_hMot6,
	MP_QSTR_hBtn1,
	MP_QSTR_hBtn2,
	MP_QSTR_hSystem,
	MP_QSTR_delay_ms,
	MP_QSTR_delay_us,
	MP_QSTR_hLED,
	MP_QSTR_on,
	MP_QSTR_off,
	MP_QSTR_toggle,
	MP_QSTR_hMotor,
	MP_QSTR_setPower,
	MP_QSTR_rotAbs,
	MP_QSTR_setParallelMode,
	MP_QSTR_setSingleMode,
	MP_QSTR_resetEncoderCnt,
	MP_QSTR_getEncoderCnt,
	MP_QSTR_hButton,
	MP_QSTR_isPressed,
	MP_QSTR_waitForPressed,
	MP_QSTR_waitForReleased,
	MP_QSTR_hPyFramework_number_of,
};

#ifdef __cplusplus
extern "C" {
#endif
mp_obj_t hSystem_delay_ms(mp_obj_t self_in, mp_obj_t arg0);
mp_obj_t hSystem_delay_us(mp_obj_t self_in, mp_obj_t arg0);
mp_obj_t hLED_on(mp_obj_t self_in);
mp_obj_t hLED_off(mp_obj_t self_in);
mp_obj_t hLED_toggle(mp_obj_t self_in);
mp_obj_t hMotor_setPower(mp_obj_t self_in, mp_obj_t arg0);
mp_obj_t hMotor_rotAbs(mp_obj_t self_in, mp_obj_t arg0);
mp_obj_t hMotor_setParallelMode(mp_obj_t self_in);
mp_obj_t hMotor_setSingleMode(mp_obj_t self_in);
mp_obj_t hMotor_resetEncoderCnt(mp_obj_t self_in);
mp_obj_t hMotor_getEncoderCnt(mp_obj_t self_in);
mp_obj_t hButton_isPressed(mp_obj_t self_in);
mp_obj_t hButton_waitForPressed(mp_obj_t self_in, mp_obj_t arg0);
mp_obj_t hButton_waitForReleased(mp_obj_t self_in, mp_obj_t arg0);

#ifdef __cplusplus
}
#endif

typedef struct _mp_obj_hSystem_t
{
	mp_obj_base_t base;
	void *hObj;
} mp_obj_hSystem_t;

typedef struct _mp_obj_hLED_t
{
	mp_obj_base_t base;
	void *hObj;
} mp_obj_hLED_t;

typedef struct _mp_obj_hMotor_t
{
	mp_obj_base_t base;
	void *hObj;
} mp_obj_hMotor_t;

typedef struct _mp_obj_hButton_t
{
	mp_obj_base_t base;
	void *hObj;
} mp_obj_hButton_t;
