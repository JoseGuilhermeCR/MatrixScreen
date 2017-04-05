/*
 Author: JoseGuilhermeCR
 Copyright 2017
*/

#include "Symbol.h"
#include "Window.h"
#include "Random.h"

Symbol::Symbol(float x, float y, float speed, float symbolSize, bool first) : m_x(x), m_y(y), m_speed(speed), m_symbolSize(symbolSize), m_first(first)
{
	setRandomValue();
}

void Symbol::update(float dt)
{
	m_y += m_speed * dt;
	
	if (m_y > Window::HEIGHT - m_symbolSize)
		m_y = 0;

	if (Random::getRandomInt(0, 100) == 1)
		setRandomValue();
}

void Symbol::setRandomValue()
{
	m_value = static_cast<char>(m_possibleValues[Random::getRandomInt(0, 77)]);
}

float Symbol::getX()
{
	return m_x;
}

float Symbol::getY()
{
	return m_y;
}

bool Symbol::getFirst()
{
	return m_first;
}

char Symbol::getValue()
{
	return m_value;
}
