#ifndef __PENG_KEY_H__
#define __PENG_KEY_H__

#include "object.h"

enum peng_key_state {
	key_error		= 0,
	key_pressed		= 1,
	key_released	= 2,
};

struct peng_key_id_act {
	obj_base_t id;
	obj_err_t (*act)(enum peng_key_state* state);
};

struct peng_key_infor {
	obj_base_t id;
	enum peng_key_state state;
};
typedef struct peng_key_infor* peng_key_infor_t;

struct peng_key {
	struct object parent;

	peng_key_infor_t ki;
	obj_size_t key_num;

	const char*		(*name)			(struct peng_key* k);

	peng_key_infor_t(*find)			(peng_key_infor_t ki, obj_base_t id);
};
typedef struct peng_key* peng_key_t;

obj_err_t peng_key_init(struct peng_key* k, const char* name);

#endif // !__PENG_KEY_H__

