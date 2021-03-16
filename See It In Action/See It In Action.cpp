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
#include <time.h>
#include "Blob.h"

using namespace std;


int main()
{
    vector<Blob*> blobs;

    srand((unsigned)time(NULL));

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

    // Create 40 blobs
    for (int i = 0; i < 40; i++)
        blobs.push_back(new Blob());

    while (window.isOpen())
    {
        sf::Event event;

        // Close window
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Draw background
        window.clear();
        window.draw(interior);
        window.draw(frameLeft);
        window.draw(frameTop);
        window.draw(frameRight);
        window.draw(frameBottom);

        // Draw 40 blobs
        for (int i = 0; i < 40; i++)
            window.draw(*blobs.at(i));

        // Determine next step
        // First, loop through each blob
        for (int i = 0; i < 40; i++)
        {
            // Compare blob with every other blob to check for collision
            for (int j = 0; j < 40; j++)
            {
                //if ()
            }

            // Compare blob with wall to check for collision
            //if ()


            // Step to next position normally
            ++*blobs.at(i);
        }
        window.display();
    }

    // Delete blobs
    for (int i = 0; i < 40; i++)
        delete blobs.at(i);

    return 0;
}
