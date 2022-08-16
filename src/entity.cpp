#include <iostream>
#include <SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include "Math.hpp"

Entity::Entity(Vector2 p_pos,SDL_Texture* p_tex)
	:position(p_pos),texture(p_tex)
{
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.h = 256;
	currentFrame.w = 256;
}
Vector2 Entity::getPos(){
	return position;
}
SDL_Texture* Entity::getTex(){
	return texture;
}
SDL_Rect Entity::getCurrentFrame(){
	return currentFrame;
}
