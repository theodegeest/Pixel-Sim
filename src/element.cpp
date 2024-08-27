#include "element.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Color.hpp>

#include "constants.h"

Element::Element(int a, int vx, int vy) {
  id = a;
  vel = sf::Vector2i(vx, vy);
}

Element::Element() {
  id = 0;
  vel.x = 0;
  vel.y = 0;
  pixel = sf::RectangleShape(sf::Vector2f(PIXEL_SIZE, PIXEL_SIZE));
  pixel.setFillColor(sf::Color(165, 191, 209));
  // pixel.setOutlineColor(sf::Color::Red);
}
