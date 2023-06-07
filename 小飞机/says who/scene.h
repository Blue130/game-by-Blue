#pragma once
#include<easyx.h>
struct scene{
	void (*draw)(struct scene*);
	void (*update)(struct scene*);
	void (*control)(struct scene*, ExMessage* msg);
	bool (*isquit)(struct scene*);
};
