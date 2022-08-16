#pragma once
#include <SDL.h>
namespace utils{
	inline float HireTimeInSecond(){
		float time = SDL_GetTicks();
		time *= 0.001f;
		return time;
	}

}