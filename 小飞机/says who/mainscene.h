#pragma once
#include"scene.h"
#include"background.h"
#include"hero.h"
#include"vector.h"

struct mainscene {
	struct scene super;
	hero* hero;
	background* bk;
	vector vecelements;
};
void mainsceneinit(struct mainscene* s);
void mainscenedestroy(struct mainscene* s);
void mainscenedraw(struct mainscene* s);
void mainsceneupdate(struct mainscene* s);
void mainscenecontrol(struct mainscene* s, ExMessage* msg);
bool mainsceneisquit(struct mainscene* s);
