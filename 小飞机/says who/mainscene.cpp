#include"mainscene.h"
void mainsceneinit(struct mainscene* s)
{
	s->super.draw = (void(*)(struct scene*))mainscenedraw;
	s->super.update = (void(*)(struct scene*))mainsceneupdate;
	s->super.control = (void(*)(struct scene*, ExMessage * msg))mainscenecontrol;
	s->super.isquit = (bool(*)(struct scene*))mainsceneisquit;
	s->hero = (struct hero*)malloc(sizeof(struct hero));
	heroinit(s->hero);

	s->bk = (struct background*)malloc(sizeof(struct background));
	backgroundinit(s->bk);
	vectorInit(&s->vecelements);
}
void mainscenedestroy(struct mainscene* s)
{
	herodestroy(s->hero);
	backgrounddestroy(s->bk);
	free(s->bk);
	vectorDestroy(&s->vecelements);
}
void mainscenedraw(struct mainscene* s)
{
	s->vecelements.clear(&s->vecelements);
	s->vecelements.append(&s->vecelements, s->bk);
	s->vecelements.append(&s->vecelements, s->hero);

	for (int i = 0; i < s->vecelements.size; i++)
	{
		struct sprite* psprite = (struct sprite*)(s->vecelements.pData[i]);
		psprite->draw(psprite);
	}
}
void mainsceneupdate(struct mainscene* s)
{
	for (int i = 0; i < s->vecelements.size; i++)
	{
		struct sprite* psprite = (struct sprite*)(s->vecelements.pData[i]);
		psprite->update(psprite);
	}
}
void mainscenecontrol(struct mainscene* s, ExMessage* msg)
{
	if (msg->message == WM_MOUSEMOVE)
	{
		s->hero->super.x = msg->x - 35;
		s->hero->super.y = msg->y - 35;
	}
}
bool mainsceneisquit(struct mainscene* s)
{
	if (s->hero->status == hero_destroy)
	{
		return true;
	}
	else return false;
}