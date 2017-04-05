/*
 Author: JoseGuilhermeCR
 Copyright 2017
*/

#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <random>
#include <chrono>

class Random
{
public:
	static int getRandomInt(int min, int max);
private:
	static std::mt19937 random;
};

#endif
