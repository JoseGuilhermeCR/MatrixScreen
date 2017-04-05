/*
 Author: JoseGuilhermeCR
 Copyright 2017
*/

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <vector>
#include <SFML/Graphics.hpp>
#include "Stream.h"

class Window {
public:
	Window(unsigned int width, unsigned int height, unsigned int symbolSize);
	void update();
	void render();
	static unsigned int WIDTH, HEIGHT;
private:
	sf::RenderWindow m_renderWindow;
	sf::Clock m_clock;
	sf::Font m_font;
	std::vector<Stream> m_streams;
};


#endif
