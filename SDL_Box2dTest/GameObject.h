#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
#include "Box2D.h"

class GameObject {
	int m_x;
	int m_y;
	int m_width;
	int m_height;
public:
	GameObject() : m_x(0), m_y(0), m_width(0), m_height(0) {

	}
	bool load();
	void render();
	void update();
	void close();
};
#endif