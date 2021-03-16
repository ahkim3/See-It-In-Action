#pragma once
#include <SFML/Graphics.hpp>


class Blob: public sf::CircleShape
{
public:
	Blob();

	~Blob();

	Blob& operator++();
	//void operator+(const Blob&);
	//bool operator>(const Blob&);
	//bool operator<(const Blob&);
	bool operator==(const Blob&);

private:
	int radius;
	float xPos, yPos, velocity, angle;

	void setVelocity();
};

