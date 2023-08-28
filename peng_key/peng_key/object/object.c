#include "object.h"

#include <stdlib.h>
#include <string.h>

#if obj_size_t != size_t
#error "stack_size_t is not equal to size_t"
#endif

void* obj_malloc(obj_size_t size)
{
	return malloc(size);
}

void obj_free(void* block)
{
	if (block == OBJ_NULL) return;
	free(block);
}

void* obj_memcpy(void* dst, void* src, obj_size_t size)
{
	return memcpy(dst, src, size);
}

int obj_memcmp(const void* buf1, const void* buf2, obj_size_t size)
{
	return memcmp(buf1, buf2, size);
}

obj_size_t obj_strlen(const char* str)
{
	return (obj_size_t)strlen(str);
}
