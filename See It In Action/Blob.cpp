#include "Blob.h"
#include <iostream>
#include <math.h>


// Default constructor
Blob::Blob()
{
	// Randomly generates a radius in the range [10 - 20]
	int radius = rand() % 11 + 10;

	// Boosts count the # of times collisions between same-sized blobs occur
	boosts = 0;

	// Randomly generate an angle between [0-359 degrees] to initially move
	angle = (float)(rand() % 360);

	// Generate random position within coordinates [50 - (500 - diameter)]
	xPos = (float)(rand() % (500 - (2 * radius))) + 50;
	yPos = (float)(rand() % (500 - (2 * radius))) + 50;

	setVelocity();
	setRadius((float)radius);
	setFillColor(sf::Color(255, 189, 32)); // Amber color
	setPosition(xPos, yPos);
}


// Default destructor
Blob::~Blob()
{
}


// Determines next step of blob
Blob& Blob::operator++() // change to void?
{
	setVelocity();

	// Find coordinates of next position
	yPos += (float)cos(angle * 3.1415926 / 180.0) * velocity;
	xPos += (float)sin(angle * 3.1415926 / 180.0) * velocity;

	// Check for collision with wall
	if ((yPos >= 550 - 2 * getRadius()) || (yPos <= 50))
		angle = 180 - angle;
	else if ((xPos >= 550 - 2 * getRadius()) || (xPos <= 50))
		angle = 360 - angle;

	// Keep angle within bounds
	if (angle < 0)
		angle += 360;
	else if (angle >= 360)
		angle -= 360;

	setPosition(xPos, yPos);
	
	return *this;
}


// Combines two blobs
void Blob::operator+(Blob& other)
{
	// Blobs of the same size bounce off each other and gain 20% velocity boost
	if (*this == other)
	{
		boosts++;
		velocity *= -1;
		other.velocity *= -1;
	}
	
	setRadius(sqrt(pow(getRadius(), 2) + pow(other.getRadius(), 2)));

	// Corrects blobs that might go over border after increasing in size
	if ((xPos > 550 - 2 * getRadius()))
		xPos = 549 - 2 * getRadius();
	else if (xPos < 50)
		xPos = 51; 
	else if ((yPos > 550 - 2 * getRadius()))
		yPos = 549 - 2 * getRadius();
	else if (yPos < 50)
		yPos = 51;

	setVelocity();
}


// Determines if two blobs have collided and that the other blob is smaller or
// the same size (collision occurs if half of two blobs overlap)
bool Blob::operator&&(const Blob& other)
{
	if (((other.xPos >= xPos - (getRadius())) 
		&& (other.xPos <= xPos + (getRadius())))
		&& ((other.yPos >= yPos - (getRadius())) 
		&& (other.yPos <= yPos + (getRadius())))
		&& other.getRadius() <= getRadius())
		return true;
	return false;
}


// Determine if two blobs are the same size
bool Blob::operator==(const Blob& other)
{
	if (other.getRadius() == getRadius())
		return true;
	return false;
}


// Sets the velocity of the blob based upon its size
void Blob::setVelocity()
{
	// Larger blob results in a slower velocity. Additionally, each boost from
	// a collision by two blobs of the same size increases total speed by 20%.
	velocity = (float)((0.4 / getRadius()) * (pow(1.2, boosts)));
}
