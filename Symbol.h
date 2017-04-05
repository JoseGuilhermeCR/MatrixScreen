/*
 Author: JoseGuilhermeCR
 Copyright 2017
*/

#ifndef __SYMBOL_H__
#define __SYMBOL_H__

class Symbol
{
public:
	Symbol(float x, float y, float speed, float symbolSize, bool first);
	void update(float dt);
	void setRandomValue();

	float getX();
	float getY();
	bool getFirst();
	char getValue();
private:
	// The x is always the same
	float m_x;
	float m_y;
	float m_speed;
	char m_value;
	float m_symbolSize;
	bool m_first;

	int m_possibleValues[77] = {65,66,67,68,69,70,71,72,73,74,75,76,
			      77,78,79,80,81,82,83,84,85,86,87,88,
			      89,97,98,99,100,101,102,103,104,105,
			      106,107,108,48,49,50,51,52,53,54,55,
			      56,57,36,43,45,42,47,61,37,34,39,35,
			      64,38,95,40,41,44,46,59,58,63,33,92,
			      60,91,93,96,94};
};

#endif
