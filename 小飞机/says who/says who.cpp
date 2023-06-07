#include"mainscene.h"
#include"gameloop.h"
void main()
{
	initgraph(422, 750);
	setbkcolor(WHITE);
	cleardevice();
	mainscene ms;
	mainsceneinit(&ms);
		gameloop((struct scene*)&ms, 60);
		mainscenedestroy(&ms);
	closegraph();
}