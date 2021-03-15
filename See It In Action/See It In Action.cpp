/*
Name: Andrew Kim
Date: March 15, 2021
Program: Rational

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
    sf::RectangleShape interior(sf::Vector2f(500, 500));
    interior.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(interior);
        window.display();
    }

    return 0;
}
