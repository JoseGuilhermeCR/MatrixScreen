/*
 Author: JoseGuilhermeCR
 Copyright 2017
*/

#include "Window.h"
#include <iostream>
#include <sstream>

/* The concept
	We will have one window divided into several columns,
	each column will have a stream, and each stream will have
	a random numbers of symbols... Instead of creating one sf::Text
	object for each symbol, each stream will have one, and we will
	change it's value/position and draw it to the screen, we could
	do it with only one sf::Text object but I don't think it's necessary,
	one object for each column will be enough.
	The symbols, will have their values randomly changed, and they
	will go down in the screen.. When their y position is greater than the
	height, we reset the y position.
*/

int main(int argc, char** argv)
{
	std::cout << "Width: " << argv[1] << std::endl;
	std::cout << "Height: " << argv[2] << std::endl;
	std::cout << "SymbolSize: " << argv[3] << std::endl;

	std::istringstream sw(argv[1]);
	std::istringstream sh(argv[2]);
	std::istringstream ss(argv[3]);

	// argv[1] = WIDTH, argv[2] = HEIGHT, argv[3] = symbolSize
	unsigned int width = 960, height = 720, symbolSize = 24;
	sw >> width;
	sh >> height;
	ss >> symbolSize;
	Window window(width, height, symbolSize);
}
