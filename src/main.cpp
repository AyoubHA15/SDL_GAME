#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Math.hpp"
#include "Utils.hpp"

void INIT();

int main (int argc, char *argv[])
{
  void INIT();
  RenderWindow window("Game",800,600);
  bool quit = false;

  SDL_Texture* Circle = window.loadTexture("res/gfx/Circle.png");

  Player player();
  //GameLoop
  while( !quit ){
      //quit event
      SDL_Event event;
      while( SDL_PollEvent( &event ) ){   
          switch( event.type ){
              /* Keyboard event */
              /* Pass the event data onto PrintKeyInfo() */
              case SDL_KEYDOWN:
              case SDL_KEYUP:
                  break;

              /* SDL_QUIT event (window close) */
              case SDL_QUIT:
                  quit = 1;
                  break;

              default:
                  break;
          }
      }

      //author stuffs 
      
      window.clear();
      //window.render(player);
      window.display();
  }
  window.cleanUp();
  SDL_Quit();
  return 0;
}



void INIT(){
    if(SDL_Init(SDL_INIT_VIDEO) > 0)
    std::cout<<"THE SDL INIT IS FALED Error:"<<SDL_GetError()<<std::endl;

    if(!(IMG_Init(IMG_INIT_PNG)))
    std::cout<<"THE IMG_Init IS FALED Error:"<<SDL_GetError()<<std::endl;
}