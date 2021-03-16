#include "Blob.h"
#include <iostream>
#include <math.h>


// Default constructor
Blob::Blob()
{
	// Randomly generates a radius in the range [10 - 20]
	radius = rand() % 11 + 10;

	// Randomly generate an angle between [0-359 degrees] to initially move
	angle = (float)(rand() % 360);

	setVelocity();
	setRadius(radius);
	setFillColor(sf::Color(255, 189, 32)); // Amber color
	
	// Sets random position within coordinates [50 - (500 - diameter)]
	xPos = (float)(rand() % (500 - (2 * radius))) + 50;
	yPos = (float)(rand() % (500 - (2 * radius))) + 50;
	setPosition(xPos, yPos);
	
}


// Default destructor
Blob::~Blob()
{
}


// Determine next step of blob
bool Blob::operator>(int) // change to void?
{
	setVelocity();

	// Find coordinates of next position
	xPos += (float)cos(angle * 3.1415926 / 180.0) * velocity;
	yPos += (float)sin(angle * 3.1415926 / 180.0) * velocity;

	setPosition(xPos, yPos); // Set position
	std::cout << xPos << ' ' << yPos << std::endl;
	return true;
}


/*
void Blob::operator+(const Blob&)
{
}
*/

// Sets the velocity of the blob based upon its size
void Blob::setVelocity()
{
	velocity = 45.0 / (float)radius; // Larger blob -> slower velocity
}

/*
void test()
{
	
}*/