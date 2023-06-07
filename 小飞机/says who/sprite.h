#pragma once
struct sprite {
	void (*draw)(sprite*);
	void (*update)(sprite*);

	int x, y;
	int width, height;
};