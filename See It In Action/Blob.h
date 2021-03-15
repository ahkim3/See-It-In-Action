#pragma once
#include <SFML/Graphics.hpp>


class Blob: public sf::CircleShape
{
public:
	Blob();

	~Blob();

private:
	int size;
};

