#include "element.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

#define PIXEL_SIZE 7



Element::Element(int a, int vx, int vy, sf::Color c) {
  id = a;
  vel = sf::Vector2i(vx, vy);
  color = c;
}

Element::Element() {
  id = 0;
  vel.x = 0;
  vel.y = 0;
  pixel = sf::RectangleShape(sf::Vector2f(PIXEL_SIZE, PIXEL_SIZE));
  pixel.setFillColor(sf::Color::Black);
  // pixel.setOutlineColor(sf::Color::Red);
}
