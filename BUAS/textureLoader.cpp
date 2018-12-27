#include "textureLoader.h"

SDL_Texture* TextureLoader::LoadTexture(const char* texturePath, SDL_Renderer* ren)
{
	SDL_Surface* surface = IMG_Load(texturePath);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(ren, surface);
	if (!surface || !texture)
	SDL_FreeSurface(surface);

	return texture;
}