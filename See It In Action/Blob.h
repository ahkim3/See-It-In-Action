#pragma once
#include <SFML/Graphics.hpp>


class Blob: public sf::CircleShape
{
public:
	Blob();

	~Blob();

	//void operator+(const Blob&);
	//bool operator>(const Blob&);
	//bool operator<(const Blob&);
	//void operator==(const Blob&);

	//void test();

private:
	int radius;
	double velocity;
	std::vector<float> position;

	void setVelocity();
};

