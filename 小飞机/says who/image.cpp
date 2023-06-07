#include"image.h"
void photodeal(int x, int y, const IMAGE* mask, const IMAGE* image)
{
	putimage(x, y, mask, SRCAND);
	putimage(x, y, image, SRCPAINT);
}