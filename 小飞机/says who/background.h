#pragma once
#include"sprite.h"
#include<easyx.h>
struct background {
	struct sprite super;
	int ya, yb;
	IMAGE* imgbackground;
};
void backgroundinit(struct background*);
void backgrounddestroy(struct background*);
