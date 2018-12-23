#include "window.h"
#include <iostream>

SDL_Renderer *Window::renderer = nullptr;

Window::Window(const string &title, int width, int height) :
	_title(title), _width(width), _height(height)
{
	_isClosed = !init();
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
}

bool Window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		cerr << "Init Failed. \n";
		return false;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);

	if (_window == nullptr)
	{
		cerr << "Failed creating the window. \n";
		return false;
	}

	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == nullptr)
	{
		cerr << "Failed creating the renderer. \n";
		return false;
	}

	return true;
}

void Window::pollEvents(SDL_Event &event)
{
	switch (event.type)
	{
	case SDL_QUIT:
		_isClosed = true;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			_isClosed = true;
		}

	default:
		break;
	}
}

void Window::clear()
{
	SDL_RenderPresent(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
	SDL_RenderClear(renderer);
}