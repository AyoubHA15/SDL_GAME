#include <iostream>
#include <SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title,int p_width,int p_height)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,p_width,p_height,SDL_WINDOW_SHOWN);
	SDL_SetWindowResizable(window,SDL_TRUE);
	if(window == NULL){
		std::cout<<"Window failed to init Error:"<<SDL_GetError()<<std::endl;
	}
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath){
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer,p_filePath);
	if(texture == NULL)
		std::cout<<"Texture failed load Error:"<< SDL_GetError() <<std::endl;
	return texture;
}
int RenderWindow::getReafrachRate(){
	int displayIndex = SDL_GetWindowDisplayIndex(window);
	SDL_DisplayMode mode;
	SDL_GetDisplayMode(displayIndex,0,&mode);
	return mode.refresh_rate;
}
void RenderWindow::cleanUp(){
	SDL_DestroyWindow(window);
}

void RenderWindow::clear(){
	SDL_RenderClear(renderer);
}
void RenderWindow::render(Entity& entity){
	SDL_Rect src;
	src.x = entity.getCurrentFrame().x;
	src.y = entity.getCurrentFrame().y;
	src.h = entity.getCurrentFrame().h;
	src.w = entity.getCurrentFrame().w;

	SDL_Rect dst;
	dst.x = entity.getPos().x ;
	dst.y = entity.getPos().y ;
	dst.h = entity.getCurrentFrame().h;
	dst.w = entity.getCurrentFrame().w;


	SDL_RenderCopy(renderer,entity.getTex(), &src,&dst);
}
void RenderWindow::display(){
	SDL_RenderPresent(renderer);
}