#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include <string>

class Game {
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	bool m_isRunning;
public:
	static const int SCREEN_WIDTH = 1280;
	static const int SCREEN_HEIGHT = 960;
	Game() {
		m_window = NULL;
		m_renderer = NULL;
		m_isRunning = false;
	}
	bool isRunning() { return m_isRunning; }
	bool init();
	void render();
	void update();
	void close();
};
#endif