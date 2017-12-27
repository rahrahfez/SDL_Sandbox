#include "Game.h"
#include <SDL_image.h>
#include <iostream>
using namespace std;

bool Game::init() {
	m_isRunning = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init Failed!" << endl;
	}
	m_window = SDL_CreateWindow("Box2D", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	int imgFlags = IMG_INIT_PNG;
	IMG_Init(imgFlags);
	
	return m_isRunning;
}

void Game::render() {
	SDL_RenderClear(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0, 0, 0, 0);

	SDL_RenderPresent(m_renderer);
}

void Game::update() {
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			close();
		}
	}
}

void Game::close() {
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);

	m_window = NULL;
	m_renderer = NULL;

	SDL_QUIT;
}
