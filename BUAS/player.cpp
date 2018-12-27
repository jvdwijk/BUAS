#include "player.h"
#include "textureLoader.h"

Player::Player(int w, int h, int x, int y, int r, int g, int b, int a) :
	_w(w), _h(h), _x(x), _y(y), _r(r), _g(g), _b(b), _a(a)
{}
Player::Player(int w, int h, int x, int y, const std::string &image_path) :
	_w(w), _h(h), _x(x), _y(y)
{
	_imageTexture = TextureLoader::LoadTexture(image_path.c_str(), Window::renderer);
}

Player::~Player()
{
	SDL_DestroyTexture(_imageTexture);
}

void Player::draw() const
{
	SDL_Rect player = { _x, _y, _w, _h };
	if (_imageTexture)
	{
		SDL_RenderCopy(Window::renderer, _imageTexture, nullptr, &player);
	}
	else
	{
		SDL_SetRenderDrawColor(Window::renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(Window::renderer, &player);
	}
}

void Player::pollEvents(SDL_Event &event)
{
	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_a:
		case SDLK_LEFT:
			
			_x -= 10;
			break;
		case SDLK_d: 
		case SDLK_RIGHT:
			_x += 10;
			break;
		case SDLK_w:
		case SDLK_UP:
			_y -= 10;
			break;
		case SDLK_s:
		case SDLK_DOWN:
			_y += 10;
			break;
		}
	}
}