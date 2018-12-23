#pragma once

#include "window.h"
#include <iostream>

class Player
{
public:
	Player(int w, int h, int x, int y, int r, int g, int b, int a);
	Player(int w, int h, int x, int y, const std::string &image_path);
	~Player();

	void draw() const;
	void pollEvents(SDL_Event &event);
private:
	int _w, _h, _x, _y;
	int _r, _g, _b, _a;
	SDL_Texture *_imageTexture = nullptr;
};