#pragma once
#include <SFML/Graphics.hpp>


class Blob: public sf::CircleShape
{
public:
	Blob();

	~Blob();

	bool operator>(int);
	//void operator+(const Blob&);
	//bool operator>(const Blob&);
	//bool operator<(const Blob&);
	//void operator==(const Blob&);

	//void test();

private:
	int radius;
	float xPos, yPos, velocity, angle;

	void setVelocity();
};

