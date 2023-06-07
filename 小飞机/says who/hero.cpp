#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"hero.h"
#include"image.h"
enum herostatus herostatussqauence[7] = {
	hero_normal0,
	hero_normal1,
	hero_down0,
	hero_down1,
	hero_down2,
	hero_down3,
	hero_destroy

};
void heroupdate(struct hero* h)
{
	h->heroupdatecnt++;
	if (h->heroupdatecnt >= 15)
	{
		h->heroupdatecnt = 0;
		if (h->life != 0)
		{
			if (h->status == hero_normal0)
				h->status = hero_normal1;
			else if (h->status == hero_normal1)
				h->status = hero_normal0;
		}
		else
		{
			if (h->status < hero_destroy)
				h->status = herostatussqauence[h->status + 1];
		}
	}
}
void herodraw(struct hero* h)
{
	photodeal(h->super.x, h->super.y, h->heromask[h->status], h->hero[h->status]);
}
void heroinit(struct hero* h)
{
	h->super.draw = (void(*)(struct sprite*))herodraw;
	h->super.update = (void(*)(struct sprite*))heroupdate;
	h->heroupdatecnt = 0;
	h->status = hero_normal0;
	h->life = 1;
	h->super.x = 176;
	h->super.y = 600;
	for (int i = 0; i < 6; i++)
	{
		h->hero[i] = new IMAGE;
		h->heromask[i] = new IMAGE;
	}
	char img[50], imgmask[50];
	for (int i = 0; i < 2; i++)
	{
		sprintf(img, "img/hero/hero%d.png", i);
		sprintf(imgmask, "img/hero/hero%d_mask.png", i);
		loadimage(h->hero[i], img);
		loadimage(h->heromask[i], imgmask);
	}
	for (int i = 0; i < 4; i++)
	{
		sprintf(img, "img/hero/hero_down%d.png", i);
		sprintf(imgmask, "img/hero/hero_down%d_mask.png", i);
		loadimage(h->hero[i + 2], img);
		loadimage(h->heromask[i + 2], imgmask);
	}
}
	void herodestroy(struct hero* h)
	{
		for (int i = 0; i < 6; i++)
		{
			delete h->hero[i];
			delete h->heromask[i];
		}
	}

