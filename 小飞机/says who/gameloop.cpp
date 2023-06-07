#include<easyx.h>
#include"gameloop.h"
#include"mainscene.h"
void gameloop(struct scene *s , int fps)
{
	timeBeginPeriod(1);
	LARGE_INTEGER start, end, f;
	QueryPerformanceFrequency(&f);

	BeginBatchDraw();
	while (1)
	{
		QueryPerformanceCounter(&start);
		cleardevice();
		s->draw(s);
		s->update(s);
		if (s->isquit(s))
			break;
		
		QueryPerformanceCounter(&end);
		long long elapse = (end.QuadPart - start.QuadPart) / f.QuadPart * 1000000;
		while (elapse < 1000000 / fps)
		{
			Sleep(1);
			ExMessage msg;
			bool isok = peekmessage(&msg, EX_MOUSE);
			if (isok == true)
			{
				s->control(s, &msg);
			}
			QueryPerformanceCounter(&end);
			elapse = (end.QuadPart - start.QuadPart) * 1000000 / f.QuadPart;
		}
		FlushBatchDraw();
	}
	EndBatchDraw();
	timeEndPeriod(1);

}