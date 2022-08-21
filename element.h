#ifndef ELEMENT_H
#define ELEMENT_H

#include <SFML/Graphics.hpp>

class Element {
  public:
    int id;
    sf::Vector2i vel;
    sf::Color color;
    sf::RectangleShape pixel;

    Element(int id, int vx, int vy, sf::Color c);
    Element();
};

#endif
