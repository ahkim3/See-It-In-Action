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
	setRadius((float)radius);
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


// Determine next step of blob; overloaded prefix increment operator
Blob& Blob::operator++() // change to void?
{
	setVelocity();

	// Find coordinates of next position
	yPos += (float)cos(angle * 3.1415926 / 180.0) * velocity;
	xPos += (float)sin(angle * 3.1415926 / 180.0) * velocity;

	//std::cout << angle << " " << (float)cos(angle * 3.1415926 / 180.0) << " " << (float)sin(angle * 3.1415926 / 180.0) << std::endl;
	// Check for collision with wall
	if ((yPos >= 550 - 2 * radius) || (yPos <= 50)) // Right/left wall hit
		angle = 180 - angle;
	else if ((xPos >= 550 - 2 * radius) || (xPos <= 50)) // Top/bottom wall hit
		angle = 360 - angle;

	// Keep angle within bounds
	if (angle < 0)
		angle += 360;
	else if (angle >= 360)
		angle -= 360;

	setPosition(xPos, yPos); // Set position
	
	return *this;
}

bool Blob::operator==(const Blob&)
{
	//if ()
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
	velocity = (float)(0.5 / radius); // Larger blob -> slower velocity
}
