#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity
{
public:
	Entity(Vector2 p_pos,SDL_Texture* p_tex);
	Vector2 getPos();
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
private:
	Vector2 position;
	SDL_Texture* texture;
	SDL_Rect currentFrame;
};