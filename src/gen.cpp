#include "gen.h"
#include <hFramework.h>

using namespace hFramework;

mp_obj_t hSystem_delay_ms(mp_obj_t self_in, mp_obj_t arg0) {
	mp_obj_hSystem_t *self = (mp_obj_hSystem_t*)self_in;
	hSystem *hSelf = (hSystem*)self->hObj;
	mp_int_t val0 = mp_obj_get_int(arg0);
	hSelf->delay_ms(val0);

	return mp_const_none;
}
mp_obj_t hSystem_delay_us(mp_obj_t self_in, mp_obj_t arg0) {
	mp_obj_hSystem_t *self = (mp_obj_hSystem_t*)self_in;
	hSystem *hSelf = (hSystem*)self->hObj;
	mp_int_t val0 = mp_obj_get_int(arg0);
	hSelf->delay_us(val0);

	return mp_const_none;
}
mp_obj_t hMotor_setPower(mp_obj_t self_in, mp_obj_t arg0) {
	mp_obj_hMotor_t *self = (mp_obj_hMotor_t*)self_in;
	hMotor *hSelf = (hMotor*)self->hObj;
	mp_int_t val0 = mp_obj_get_int(arg0);
	hSelf->setPower(val0);

	return mp_const_none;
}
mp_obj_t hMotor_rotAbs(mp_obj_t self_in, mp_obj_t arg0) {
	mp_obj_hMotor_t *self = (mp_obj_hMotor_t*)self_in;
	hMotor *hSelf = (hMotor*)self->hObj;
	mp_int_t val0 = mp_obj_get_int(arg0);
	hSelf->rotAbs(val0);

	return mp_const_none;
}
mp_obj_t hMotor_setParallelMode(mp_obj_t self_in) {
	mp_obj_hMotor_t *self = (mp_obj_hMotor_t*)self_in;
	hMotor *hSelf = (hMotor*)self->hObj;
	hSelf->setParallelMode();

	return mp_const_none;
}
mp_obj_t hMotor_setSingleMode(mp_obj_t self_in) {
	mp_obj_hMotor_t *self = (mp_obj_hMotor_t*)self_in;
	hMotor *hSelf = (hMotor*)self->hObj;
	hSelf->setSingleMode();

	return mp_const_none;
}

extern const mp_obj_type_t hSystem_type;

extern const mp_obj_type_t hMotor_type;

void reg()
{
	qstr_add_const_pool(&hpyframework_pool);

	{
		mp_obj_hSystem_t *v = m_new_obj_var(mp_obj_hSystem_t, char*, 0);
		v->hObj = &sys;
		v->base.type = &hSystem_type;
		mp_store_name(MP_QSTR_sys, (mp_obj_t)v);
	}

	{
		mp_obj_hMotor_t *v = m_new_obj_var(mp_obj_hMotor_t, char*, 0);
		v->hObj = &hMot1;
		v->base.type = &hMotor_type;
		mp_store_name(MP_QSTR_hMot1, (mp_obj_t)v);
	}

	{
		mp_obj_hMotor_t *v = m_new_obj_var(mp_obj_hMotor_t, char*, 0);
		v->hObj = &hMot2;
		v->base.type = &hMotor_type;
		mp_store_name(MP_QSTR_hMot2, (mp_obj_t)v);
	}

	{
		mp_obj_hMotor_t *v = m_new_obj_var(mp_obj_hMotor_t, char*, 0);
		v->hObj = &hMot3;
		v->base.type = &hMotor_type;
		mp_store_name(MP_QSTR_hMot3, (mp_obj_t)v);
	}

	{
		mp_obj_hMotor_t *v = m_new_obj_var(mp_obj_hMotor_t, char*, 0);
		v->hObj = &hMot4;
		v->base.type = &hMotor_type;
		mp_store_name(MP_QSTR_hMot4, (mp_obj_t)v);
	}

	{
		mp_obj_hMotor_t *v = m_new_obj_var(mp_obj_hMotor_t, char*, 0);
		v->hObj = &hMot5;
		v->base.type = &hMotor_type;
		mp_store_name(MP_QSTR_hMot5, (mp_obj_t)v);
	}

	{
		mp_obj_hMotor_t *v = m_new_obj_var(mp_obj_hMotor_t, char*, 0);
		v->hObj = &hMot6;
		v->base.type = &hMotor_type;
		mp_store_name(MP_QSTR_hMot6, (mp_obj_t)v);
	}

}