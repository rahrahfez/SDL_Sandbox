#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H
#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <string>

class TextureManager {
	SDL_Texture* m_texture;
	std::map<std::string, SDL_Texture*> m_textureMap;
public:
	TextureManager();
	bool load(std::string fileName, std::string id, SDL_Renderer* m_renderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* m_renderer);
	void drawFrame(std::string id, int x, int y, int width, int height, int frame, SDL_Renderer* m_renderer);
	void close(std::string id);
};
#endif