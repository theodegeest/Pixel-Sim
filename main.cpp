#include <SFML/Graphics.hpp>
#include "test.h"

struct box {
  float x;
  float y;
};

class ClassTest {
  public:
    int a;
    int b;
    ClassTest(int x, int y, int z);
    void displayTest(int a);
  private:
    int c;
};

ClassTest::ClassTest(int x, int y, int z) {
  a = x;
  b = y;
  c = z;
  printf("done\n");
}

void ClassTest::displayTest(int a) {
  printf("%d\n", a);
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
  // window.setFramerateLimit(30);
  // window.setVerticalSyncEnabled(true);
  // sf::CircleShape shape(100.f);
  // shape.setFillColor(sf::Color::Green);

  sf::Clock clock; // Starts clock
  sf::Font font;
  if (!font.loadFromFile("JetBrains Mono Regular Nerd Font Complete.ttf"))
  {
    printf("font error\n");
  }
  sf::Text text;
  char string[9];
  int avg_fps = 0;
  float avg_time = 0;
  int fps_array[50];
  int fps_ctr = 0;

  struct box box1;
  box1.x = 20;
  box1.y = 20;

  sf::RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
  rectangle.setFillColor(sf::Color::Red);

  sf::CircleShape mouse(20.f);
  mouse.setFillColor(sf::Color::Green);

  // select the font
  text.setFont(font); // font is a sf::Font
  
  ClassTest myObj(1, 2, 3);
  printf("%d, %d\n", myObj.a, myObj.b);
  myObj.displayTest(5);

  while (window.isOpen())
  {
    sf::Time delta_time = clock.restart(); //delta_time

    fps_array[fps_ctr] = delta_time.asMilliseconds();
    if (fps_ctr < 49)
    {
      fps_ctr++;
    } else
    {
      fps_ctr = 0;
      avg_time = 0;
      for (int i = 0; i < 50; i++) {
        avg_time+= fps_array[i];
      }
      avg_time/= 50;
    }

    if (avg_time > 0)
    {
      avg_fps = 1000 / avg_time;
    }

    sprintf(string, "%d", avg_fps);
    text.setString(string);


    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed) {
        printf("Goodbye\n");
        window.close();
      }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
      box1.x-= 1 * delta_time.asMilliseconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
      box1.x+= 1 * delta_time.asMilliseconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
      box1.y-= 1 * delta_time.asMilliseconds();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
      box1.y+= 1 * delta_time.asMilliseconds();
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      mouse.setScale(2, 2);
    } else
    {
      mouse.setScale(1, 1);
    }

    rectangle.setPosition(box1.x, box1.y);
    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    mouse.setPosition(mouse_pos.x - 17, mouse_pos.y - 17);

    // test_function();

    window.clear(sf::Color::Black);
    // window.draw(shape);
    window.draw(rectangle);
    window.draw(mouse);
    window.draw(text);
    window.display();
  }

  return 0;
}



