#include"background.h"
void backgrounddraw(struct background*b)
{
	putimage(0, b->ya, b->imgbackground);
	putimage(0, b->yb, b->imgbackground);
}
void backgroundupdate(struct background* b)
{
	b->ya = b->ya + 1;
	b->yb = b->yb + 1;
	if (b->ya == 0)
	{
		b->ya = -750;
		b->yb = 0;
	}
}
void backgroundinit(struct background*b)
{
	b->super.draw = (void(*)(struct sprite*))backgrounddraw;
	b->super.update = (void(*)(struct sprite*))backgroundupdate;
	b->ya = -750;
	b->yb = 0;
	b->imgbackground= new IMAGE;
	loadimage(b->imgbackground, "img/bg.png");
}
void backgrounddestroy(struct background* b)
{
	delete b->imgbackground;
}