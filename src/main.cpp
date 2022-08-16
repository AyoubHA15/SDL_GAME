#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Math.hpp"
#include <Utils.hpp>

int main (int argc, char *argv[])
{
  if(SDL_Init(SDL_INIT_VIDEO) > 0)
    std::cout<<"THE SDL INIT IS FALED Error:"<<SDL_GetError()<<std::endl;

  if(!(IMG_Init(IMG_INIT_PNG)))
    std::cout<<"THE IMG_Init IS FALED Error:"<<SDL_GetError()<<std::endl;

  RenderWindow window("Game",1280,720);
  bool GameRunnig = true;
  SDL_Event event;
  SDL_Texture* Circle = window.loadTexture("res/gfx/Circle.png");
  Entity grassEntitys[3] = {Entity(Vector2(0,0),Circle),
                            Entity(Vector2(3,0),Circle),
                            Entity(Vector2(12,0),Circle)};
  //GameLoop
  while(GameRunnig){

    while(event.type == SDL_QUIT)
      GameRunnig = false;

    window.clear();
    for (int i = 0; i < 3; ++i)
    {
      window.render(grassEntitys[i]);
    }
    std::cout<<utils::HireTimeInSecond()<<std::endl;
    window.display();
  }

  window.cleanUp();
  SDL_Quit();
  return 0;
}