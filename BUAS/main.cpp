#include "window.h"
#include "player.h"

using namespace std;

void pollEvents(Window &window, Player &player)
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		window.pollEvents(event);
		player.pollEvents(event);
	}
}

void update()
{

}

int main(int argc, char **argv)
{
	const int _frameDelay = 1000 / 60;
	int _frameTime;
	Uint32 _frameStart;

	Window window("MAIN", 600, 600);
	Player player(60, 60, 100, 100, "Res/Head.png");
	
	while (!window.isClosed())
	{
		_frameStart = SDL_GetTicks();

		pollEvents(window, player);
		player.draw();
		window.clear();

		_frameTime = SDL_GetTicks() - _frameStart;

		if (_frameDelay > _frameTime)
		{
			SDL_Delay(_frameDelay - _frameTime);
		}
	}


	return 0;
}
