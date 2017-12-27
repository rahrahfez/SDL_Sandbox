#include "TextureManager.h"

TextureManager::TextureManager() {}

bool TextureManager::load(std::string fileName, std::string id, SDL_Renderer* m_renderer) {
	SDL_Surface* tmpSurface = IMG_Load(fileName.c_str());
	if (tmpSurface == NULL) {
		return false;
	}
	else {
		m_texture = SDL_CreateTextureFromSurface(m_renderer, tmpSurface);
		SDL_FreeSurface(tmpSurface);
		if (m_texture != 0) {
			m_textureMap[id] = m_texture;
			return true;
		}
	}
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int width, int height, SDL_Renderer* m_renderer) {
	SDL_Rect srcRect;
	SDL_Rect dstRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = dstRect.w = width;
	srcRect.h = dstRect.h = height;
	dstRect.x = x;
	dstRect.y = y;

	SDL_RenderCopy(m_renderer, m_textureMap[id], &srcRect, &dstRect);
}

void TextureManager::drawFrame(std::string id, int x, int y, int width, int height, int frame, SDL_Renderer* m_renderer) {

}

void TextureManager::close(std::string id) {
	SDL_DestroyTexture(m_textureMap[id]);
}