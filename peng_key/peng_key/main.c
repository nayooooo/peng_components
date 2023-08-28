#include "main.h"

#include <stdio.h>

struct peng_key k;

int main()
{
	peng_key_init(&k, "group1");
	printf("k_name: %s\r\n", k.name(&k));

	return 0;
}
