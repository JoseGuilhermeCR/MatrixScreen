/*
 Author: JoseGuilhermeCR
 Copyright 2017
*/

#include "Stream.h"
#include "Random.h"

Stream::Stream(float x, float y, float speed, float symbolSize, sf::Font &font) : m_text(), m_symbols(), m_defaultColor(0, 255, 70), m_firstColor(156, 255, 156)
{
	// Create the text object for the stream
	m_text.setCharacterSize(symbolSize);
	m_text.setFont(font);
	m_text.setString("");
	m_text.setColor(sf::Color::White);

	// symbolNumber = 3 < x < 22
	unsigned int symbolNumber = Random::getRandomInt(3, 22);

	// A variable to hold the starting Y position of the stream
	float symbolY = y;
	// Populate the vector with the correct number of Symbols
	for (unsigned int i = 0; i < symbolNumber; ++i)
	{
		m_symbols.push_back(Symbol(x, symbolY, speed, symbolSize, (symbolY == y && Random::getRandomInt(0, 5) == 1) ? true : false));
		// Reduce symbol y by symbolSize, so the next symbol will be above this one
		symbolY -= symbolSize;
	}
}

void Stream::update(float dt)
{
	// Iterate through the vector and update all the symbols
	for (unsigned int i = 0; i < m_symbols.size(); ++i)
	{
		m_symbols.at(i).update(dt);
	}
}

void Stream::render(sf::RenderWindow &renderWindow)
{
	// Draw each symbol of this stream using it's values inside of m_text
	for (unsigned int i = 0; i < m_symbols.size(); ++i)
	{
		m_text.setPosition(m_symbols.at(i).getX(), m_symbols.at(i).getY());
		m_text.setString(m_symbols.at(i).getValue());
		if (m_symbols.at(i).getFirst())
			m_text.setColor(m_firstColor);
		else
			m_text.setColor(m_defaultColor);
		renderWindow.draw(m_text);
	}
}
