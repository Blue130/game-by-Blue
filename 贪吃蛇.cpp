#include<stdio.h>
#include<easyx.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define deta 40
enum direction {R,L,U,D};
typedef struct snake
{
	int x;
	int y;
}node;								//创造蛇在网格中的坐标数据
void paintline()
{
	int i, j;
	for (i = 0; i <= 800; i+=40)
	{
		line(i, 0, i, 600);
	}
	for (j = 0; j <= 600; j+=40)
	{
		line(0, j, 800, j);
	}
}
void snakepaint(node* snake, int lenth)
{
	setfillcolor(WHITE);
	int i;
	long x1, x2, y1, y2;
	for (i = 0; i < lenth; i++)
	{
		x1 = snake[i].x * deta;
		y1 = snake[i].y * deta;
		x2 = (snake[i].x + 1) * deta;
		y2 = (snake[i].y + 1) * deta;
		solidrectangle(x1, y1, x2, y2);
	}
}
node snakemove(node* snake, int lenth, int direction)
{
	int i;
	node end = snake[lenth - 1];
	for (i = lenth - 1; i > 0; i--)
	{
		snake[i] = snake[i - 1];
	}
	if (direction == R)
		snake[0].x++;
	if (direction == L)
		snake[0].x--;
	if (direction == U)
		snake[0].y--;
	if (direction == D)
		snake[0].y++;
	return end;
}
void directionchange(enum direction *direct)
{
	if (_kbhit() != 0)
	{
		char sign = _getch();
		if (sign == 'a' && *direct!=R)
			*direct = L;
		if (sign == 'd' && *direct != L)
			*direct = R;
		if (sign == 'w' && *direct != D)
			*direct = U;
		if (sign == 's' && *direct != U)
			*direct = D;
	}
}
node foodcreat(node *snake,int lenth)
{
	srand(time(NULL));
	int j = 1;
	node food;
	
	while(1)
	{
		food.x = rand() % 21;
		food.y = rand() % 16;
		int i = 0;
		for (; i < lenth; i++)
		{
			if (food.x == snake[i].x && food.y == snake[i].y)
				break;
		}
		if (i < lenth)
			continue;
		else break;

	}
	return food;
}
void paintfood(node food)
{
	setfillcolor(RGB(244, 154, 193));
	int x1, x2, y1, y2;
	x1 = food.x * deta;
	x2 = (food.x + 1) * deta;
	y1 = food.y * deta;
	y2 = (food.y + 1) * deta;
	solidrectangle(x1, y1, x2, y2);
}
int Gameover(node* snake,int lenth)
{
	if (snake[0].x > 20 || snake[0].x < 0)
		return 0;
	if (snake[0].y > 15 || snake[0].y < 0)
		return 0;
	int i;
	for ( i=1; i < lenth; i++)
	{
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y)
			return 0;
		else return 1;
	}
}
void rebuild(node* snake,int* lenth)
{
	*lenth = 3;
	snake[0] = node{ 4,3 };
	snake[1] = node{ 3,3 };
	snake[2] = node{ 2,3 };
}
void main()
{
	int lenth = 3;
	enum direction direct = R;
	node snake[100] = { {4,3},{3,3},{2,3} };
	initgraph(800, 600);
	setbkcolor(RGB(50, 102, 80));
	cleardevice();
	node food=foodcreat(snake, lenth);
	while (1)
	{

		cleardevice();
		paintline();						//画背景网格
		paintfood(food);
		snakepaint(snake, lenth);

		Sleep(300);
		directionchange(&direct);

		node end=snakemove(snake, lenth, direct);
		if (lenth<100 && snake[0].x == food.x && snake[0].y == food.y)
		{
			snake[lenth] = end;
			lenth++;
			food = foodcreat(snake, lenth);
		}
		int j = Gameover(snake, lenth);
		if (j == 0)
		{
			rebuild(snake, &lenth);
			food = foodcreat(snake, lenth); 
		}
	}
	getchar();
	closegraph();
}