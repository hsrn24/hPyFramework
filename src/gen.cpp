#include "gen.h"
#include <hFramework.h>

using namespace hFramework;

mp_obj_t hSystem_delay_ms(mp_obj_t self_in, mp_obj_t arg0)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hSystem *hSelf = (hSystem*)self->hObj;
	mp_int_t val0 = mp_obj_get_int(arg0);
	hSelf->delay_ms(val0);
	return mp_const_none;
}
mp_obj_t hSystem_delay_us(mp_obj_t self_in, mp_obj_t arg0)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hSystem *hSelf = (hSystem*)self->hObj;
	mp_int_t val0 = mp_obj_get_int(arg0);
	hSelf->delay_us(val0);
	return mp_const_none;
}
mp_obj_t hLED_on(mp_obj_t self_in)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hLED *hSelf = (hLED*)self->hObj;
	hSelf->on();
	return mp_const_none;
}
mp_obj_t hLED_off(mp_obj_t self_in)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hLED *hSelf = (hLED*)self->hObj;
	hSelf->off();
	return mp_const_none;
}
mp_obj_t hLED_toggle(mp_obj_t self_in)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hLED *hSelf = (hLED*)self->hObj;
	hSelf->toggle();
	return mp_const_none;
}
mp_obj_t hMotor_setPower(mp_obj_t self_in, mp_obj_t arg0)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hMotor *hSelf = (hMotor*)self->hObj;
	mp_int_t val0 = mp_obj_get_int(arg0);
	hSelf->setPower(val0);
	return mp_const_none;
}
mp_obj_t hMotor_rotAbs(mp_obj_t self_in, mp_obj_t arg0)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hMotor *hSelf = (hMotor*)self->hObj;
	mp_int_t val0 = mp_obj_get_int(arg0);
	hSelf->rotAbs(val0);
	return mp_const_none;
}
mp_obj_t hMotor_setParallelMode(mp_obj_t self_in)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hMotor *hSelf = (hMotor*)self->hObj;
	hSelf->setParallelMode();
	return mp_const_none;
}
mp_obj_t hMotor_setSingleMode(mp_obj_t self_in)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hMotor *hSelf = (hMotor*)self->hObj;
	hSelf->setSingleMode();
	return mp_const_none;
}
mp_obj_t hMotor_resetEncoderCnt(mp_obj_t self_in)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hMotor *hSelf = (hMotor*)self->hObj;
	hSelf->resetEncoderCnt();
	return mp_const_none;
}
mp_obj_t hMotor_getEncoderCnt(mp_obj_t self_in)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hMotor *hSelf = (hMotor*)self->hObj;
	int ret = hSelf->getEncoderCnt();
	return mp_obj_new_int(ret);
}
mp_obj_t hButton_isPressed(mp_obj_t self_in)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hButton *hSelf = (hButton*)self->hObj;
	bool ret = hSelf->isPressed();
	return ret ? mp_const_true : mp_const_false;
}
mp_obj_t hButton_waitForPressed(mp_obj_t self_in, mp_obj_t arg0)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hButton *hSelf = (hButton*)self->hObj;
	mp_int_t val0 = mp_obj_get_int(arg0);
	bool ret = hSelf->waitForPressed(val0);
	return ret ? mp_const_true : mp_const_false;
}
mp_obj_t hButton_waitForReleased(mp_obj_t self_in, mp_obj_t arg0)
{
	mp_obj_hObject_t *self = (mp_obj_hObject_t*)self_in;
	hButton *hSelf = (hButton*)self->hObj;
	mp_int_t val0 = mp_obj_get_int(arg0);
	bool ret = hSelf->waitForReleased(val0);
	return ret ? mp_const_true : mp_const_false;
}

extern const mp_obj_type_t hSystem_type;
extern const mp_obj_type_t hLED_type;
extern const mp_obj_type_t hMotor_type;
extern const mp_obj_type_t hButton_type;

void reg()
{
	qstr_add_const_pool(&hpyframework_pool);

	mp_obj_hObject_t *v;

	v = m_new_obj_var(mp_obj_hObject_t, char*, 0);
	v->hObj = &sys;
	v->base.type = &hSystem_type;
	mp_store_name(MP_QSTR_sys, (mp_obj_t)v);

	v = m_new_obj_var(mp_obj_hObject_t, char*, 0);
	v->hObj = &LED1;
	v->base.type = &hLED_type;
	mp_store_name(MP_QSTR_LED1, (mp_obj_t)v);

	v = m_new_obj_var(mp_obj_hObject_t, char*, 0);
	v->hObj = &LED2;
	v->base.type = &hLED_type;
	mp_store_name(MP_QSTR_LED2, (mp_obj_t)v);

	v = m_new_obj_var(mp_obj_hObject_t, char*, 0);
	v->hObj = &LED3;
	v->base.type = &hLED_type;
	mp_store_name(MP_QSTR_LED3, (mp_obj_t)v);

	v = m_new_obj_var(mp_obj_hObject_t, char*, 0);
	v->hObj = &hMot1;
	v->base.type = &hMotor_type;
	mp_store_name(MP_QSTR_hMot1, (mp_obj_t)v);

	v = m_new_obj_var(mp_obj_hObject_t, char*, 0);
	v->hObj = &hMot2;
	v->base.type = &hMotor_type;
	mp_store_name(MP_QSTR_hMot2, (mp_obj_t)v);

	v = m_new_obj_var(mp_obj_hObject_t, char*, 0);
	v->hObj = &hMot3;
	v->base.type = &hMotor_type;
	mp_store_name(MP_QSTR_hMot3, (mp_obj_t)v);

	v = m_new_obj_var(mp_obj_hObject_t, char*, 0);
	v->hObj = &hMot4;
	v->base.type = &hMotor_type;
	mp_store_name(MP_QSTR_hMot4, (mp_obj_t)v);

	v = m_new_obj_var(mp_obj_hObject_t, char*, 0);
	v->hObj = &hMot5;
	v->base.type = &hMotor_type;
	mp_store_name(MP_QSTR_hMot5, (mp_obj_t)v);

	v = m_new_obj_var(mp_obj_hObject_t, char*, 0);
	v->hObj = &hMot6;
	v->base.type = &hMotor_type;
	mp_store_name(MP_QSTR_hMot6, (mp_obj_t)v);

	v = m_new_obj_var(mp_obj_hObject_t, char*, 0);
	v->hObj = &hBtn1;
	v->base.type = &hButton_type;
	mp_store_name(MP_QSTR_hBtn1, (mp_obj_t)v);

	v = m_new_obj_var(mp_obj_hObject_t, char*, 0);
	v->hObj = &hBtn2;
	v->base.type = &hButton_type;
	mp_store_name(MP_QSTR_hBtn2, (mp_obj_t)v);

}
