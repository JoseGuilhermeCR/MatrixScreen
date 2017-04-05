/*
 Author: JoseGuilhermeCR
 Copyright 2017
*/

#include "Window.h"
#include <iostream>
#include <cmath>
#include "Random.h"

unsigned int Window::WIDTH = 0, Window::HEIGHT = 0;

Window::Window(unsigned int width, unsigned int height, unsigned int symbolSize)
	: m_clock(),
	  m_streams()
{
	WIDTH = width;
	HEIGHT = height;

	m_renderWindow.create({WIDTH, HEIGHT}, "Matrix Screen", sf::Style::Close);

	if (!m_font.loadFromFile("katakana.ttf"))
		return;

	unsigned int streamNumber = round(WIDTH / symbolSize);

	for (unsigned int i = 0; i < streamNumber; ++i)
		m_streams.push_back(Stream(i * symbolSize, Random::getRandomInt(-300, 0), Random::getRandomInt(150, 325), symbolSize, m_font));

	while (m_renderWindow.isOpen())
	{
		update();
		render();
	}
}

void Window::update()
{
	float dt = m_clock.restart().asSeconds();
	sf::Event event;
	while (m_renderWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
			m_renderWindow.close();
	}

	for (unsigned int i = 0; i < m_streams.size(); ++i)
		m_streams.at(i).update(dt);
}

void Window::render()
{
	m_renderWindow.clear(sf::Color::Black);

	for (unsigned int i = 0; i < m_streams.size(); ++i)
		m_streams.at(i).render(m_renderWindow);

	m_renderWindow.display();
}
