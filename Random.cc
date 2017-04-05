/*
 Author: JoseGuilhermeCR
 Copyright 2017
*/

#include "Random.h"

std::mt19937 Random::random(std::chrono::system_clock::now().time_since_epoch().count());

int Random::getRandomInt(int min, int max)
{
	// Creates a distribution with min = min, max = max
	std::uniform_int_distribution<int> dist(min, max);
	// Returns a number from this distribution
	return dist(random);
}
