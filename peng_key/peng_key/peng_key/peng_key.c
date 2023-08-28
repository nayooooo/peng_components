#include "peng_key.h"

const char* _peng_key_name(struct peng_key* k)
{
	if (k == OBJ_NULL) return "";
	return k->parent.name;
}

extern struct peng_key_id_act pk_id_act_hash[];

obj_err_t peng_key_init(struct peng_key* k, const char* name)
{
	if (k == OBJ_NULL) return -OBJ_PARAM;
	if (name == OBJ_NULL) return -OBJ_PARAM;

	obj_memcpy(k->parent.name, name, sizeof(k->parent.name));
	k->parent.flag = 0;

	obj_size_t key_num = 0;
	while (pk_id_act_hash[key_num++].id != 0);
	key_num--;
	k->ki = obj_malloc(key_num * sizeof(struct peng_key_infor));
	if (k->ki == OBJ_NULL) return -OBJ_ERROR;
	for (obj_size_t i = 0; i < key_num; i++) {
		k->ki[i].id = pk_id_act_hash[i].id;
		k->ki[i].state = key_error;
	}

	k->name = _peng_key_name;

	return OBJ_EOK;
}
