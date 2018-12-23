#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

class Window
{
public:
	Window(const string &title, int width, int height);
	~Window();

	inline bool isClosed() const { return _isClosed; }
	void clear();
	void pollEvents(SDL_Event &event);

	static SDL_Renderer *renderer;

private:
	string _title;
	int _width;
	int _height;
	bool _isClosed = false;
	SDL_Window *_window = nullptr;

	bool init();
};