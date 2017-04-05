/*
 Author: JoseGuilhermeCR
 Copyright 2017
*/

#ifndef __STREAM_H__
#define __STREAM_H__

#include "Symbol.h"
#include <vector>
#include <SFML/Graphics.hpp>

class Stream
{
public:
	Stream(float x, float y, float speed, float symbolSize, sf::Font &font);
	void update(float dt);
	void render(sf::RenderWindow &renderWindow);
private:
	sf::Text m_text;
	std::vector<Symbol> m_symbols;
	sf::Color m_defaultColor;
	sf::Color m_firstColor;
};

#endif
