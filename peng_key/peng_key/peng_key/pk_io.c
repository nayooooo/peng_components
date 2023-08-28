#include "peng_key.h"

#ifndef __WEAK
#	define __WEAK
#endif // !__WEAK

struct peng_key_id_act pk_id_act_hash[] = {
	{ 0, NULL }
};

__WEAK obj_err_t _pk_io_single_get_state(obj_base_t id, enum peng_key_state* state)
{
	*state = key_error;

	return -OBJ_ERROR;
}
