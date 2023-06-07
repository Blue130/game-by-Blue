#pragma once
#include"sprite.h"
#include<easyx.h>
enum herostatus {
	hero_normal0,
	hero_normal1,
	hero_down0,
	hero_down1,
	hero_down2,
	hero_down3,
	hero_destroy
};
struct hero {
	struct sprite super;
	IMAGE* hero[6];
	IMAGE* heromask[6];
	enum herostatus status;				//�����ɻ�Ŀǰ��״̬
	int life;							//����ֵ
	int heroupdatecnt;					//���¼�����
};
void heroinit(struct hero* );
void herodestroy(struct hero*);