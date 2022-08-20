#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Script{
public:
	virtual void start(){}
	virtual void update(){}
	virtual void fixedUpdate(){}
};

class Entity
{
public:
	Entity(Vector2 p_pos,SDL_Texture* p_tex);
	Entity():position(Vector2(0,0)){};
	Vector2 getPos();
	SDL_Texture* getTex();
	SDL_Rect getCurrentFrame();
private:
	SDL_Texture* texture;
	Vector2 position;
	SDL_Rect currentFrame;
};
class Player:public Entity{
public:
	void start(){
		std::cout<<"It's just start"<<std::endl;
	}
	void update(){
		std::cout<<"update the player"<<std::endl;
	}
	Player(){start();}
};