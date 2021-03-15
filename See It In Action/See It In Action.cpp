/*
Name: Andrew Kim
Date: March 15, 2021
Program: See It In Action

I hereby certify that this program represents my
work and that the design and logic was completed
without outside assistance.

Signature: Andrew Kim
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Blob.h"

using namespace std;


int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "See It In Action");
    
    // Create background shapes
    sf::RectangleShape interior(sf::Vector2f(500, 500));
    sf::RectangleShape frameLeft(sf::Vector2f(10, 520));
    sf::RectangleShape frameTop(sf::Vector2f(520, 10));
    sf::RectangleShape frameRight(sf::Vector2f(10, 520));
    sf::RectangleShape frameBottom(sf::Vector2f(520, 10));
    
    // Fill background colors
    interior.setFillColor(sf::Color(46, 134, 224)); // Blue-grotto color
    frameLeft.setFillColor(sf::Color::Blue);
    frameTop.setFillColor(sf::Color::Blue);
    frameRight.setFillColor(sf::Color::Blue);
    frameBottom.setFillColor(sf::Color::Blue);
    
    // Set positions of background shapes
    interior.setPosition(50, 50); // Interior set to center
    frameLeft.setPosition(40, 40); // Frames are 10 pixels wide around center
    frameTop.setPosition(40, 40);
    frameRight.setPosition(550, 40);
    frameBottom.setPosition(40, 550);

    while (window.isOpen())
    {
        sf::Event event;

        // Close window
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        // Draw background
        window.draw(interior);
        window.draw(frameLeft);
        window.draw(frameTop);
        window.draw(frameRight);
        window.draw(frameBottom);
        
        window.display();
    }

    return 0;
}
