#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"
int main(int argc, char** argv){
	std::cout << "start;\n";

	if(SDL_Init(SDL_INIT_VIDEO) > 0){
		std::cerr << "SDL_Init failed. Error:" << std::endl << SDL_GetError() << std::endl;
	}
	if(!IMG_Init(IMG_INIT_PNG)){
		std::cerr << "IMG_Init failed. Error:" << std::endl << SDL_GetError() << std::endl;
	}
	RenderWindow window = RenderWindow("GAME v1.0", 1280, 720, 4);
	std::cout << window.getRefreshRate() << "fps screen" << std::endl;
	SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");
	std::vector<Entity> entities = {
		Entity(Vector2f(0, 0), grassTexture),
		Entity(Vector2f(30, 0), grassTexture),
		Entity(Vector2f(30, 30), grassTexture)
	};
	bool gameRunning = true;
	SDL_Event event;
	const float timeStep = 0.01f;
	float accumolator = 0.0f;
	float currentTime = utils::hireTimeInSeconds();
	while(gameRunning){
		int startTicks = SDL_GetTicks();
		float newTime = utils::hireTimeInSeconds();
		float frameTime = newTime - currentTime;
		currentTime = newTime;
		accumolator += frameTime;
		while(accumolator >= timeStep){
			while(SDL_PollEvent(&event)){
				if(event.type == SDL_QUIT){
					gameRunning = false;
				}
			}
			accumolator -= timeStep;
		}
		const float alpha = accumolator/timeStep;

		window.clear();
		for(Entity& e : entities){
			window.render(e);
		}
		window.display();
		int frameTicks = SDL_GetTicks() - startTicks;
		if(frameTicks < (1000 / window.getRefreshRate())){
			SDL_Delay((1000 / window.getRefreshRate()) - frameTicks);
		}
	}
	window.cleanUp();
	SDL_Quit();

	std::cout << "exit;\n";
	return 0;
}