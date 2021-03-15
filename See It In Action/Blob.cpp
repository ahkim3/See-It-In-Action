#include "Blob.h"
#include <iostream>


// Default constructor
Blob::Blob()
{
	// Randomly generates a radius in the range [10 - 20]
	radius = rand() % 11 + 10;
	std::cout << radius << std::endl;

	setVelocity();
	setRadius((float)radius);
	setFillColor(sf::Color(255, 189, 32)); // Amber color
	
	// Sets random position within coordinates [50 - (500 - diameter)]
	setPosition((rand() % (500 - (2 * radius))) + 50, 
		(rand() % (500 - (2 * radius))) + 50);
	
}


// Default destructor
Blob::~Blob()
{
}


/*
void Blob::operator+(const Blob&)
{
}
*/

// Sets the velocity of the blob based upon its size
void Blob::setVelocity()
{
	velocity = 45.0 / (double)radius; // Larger blob -> slower velocity
}

/*
void test()
{
	
}*/