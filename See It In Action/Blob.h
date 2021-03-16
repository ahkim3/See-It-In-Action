#pragma once
#include <SFML/Graphics.hpp>


class Blob: public sf::CircleShape
{
public:
	Blob();

	~Blob();

	Blob& operator++();
	void operator+(Blob&);
	bool operator&&(const Blob&);
	bool operator==(const Blob&);

private:
	int boosts;
	float xPos, yPos, velocity, angle;

	void setVelocity();
};
