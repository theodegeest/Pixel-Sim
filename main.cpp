#include <SFML/Graphics.hpp>
#include "element.h"

#define GRID_SIZE 100
#define PIXEL_SIZE 10
#define UPDATE_INTERVAL 10


Element grid[GRID_SIZE][GRID_SIZE];

Element temp;

int main()
{
  sf::RenderWindow window(sf::VideoMode(1000, 1000), "Pixel-Sim");
  // window.setFramerateLimit(30);
  // window.setVerticalSyncEnabled(true);
  // sf::CircleShape shape(100.f);
  // shape.setFillColor(sf::Color::Green);

  sf::Clock clock; // Starts clock

  int update_time = 0;
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

  // sf::CircleShape mouse(20.f);
  // mouse.setFillColor(sf::Color::Green);

  // select the font
  text.setFont(font); // font is a sf::Font

  while (window.isOpen())
  {
    sf::Time delta_time = clock.restart(); //delta_time
    update_time+= delta_time.asMilliseconds();

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

    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    // {
    //   box1.x-= 1 * delta_time.asMilliseconds();
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    // {
    //   box1.x+= 1 * delta_time.asMilliseconds();
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    // {
    //   box1.y-= 1 * delta_time.asMilliseconds();
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    // {
    //   box1.y+= 1 * delta_time.asMilliseconds();
    // }
    //

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);

      if (mouse_pos.x >= 0 && mouse_pos.y >= 0 && mouse_pos.x < GRID_SIZE * PIXEL_SIZE && mouse_pos.y < GRID_SIZE * PIXEL_SIZE)
      {
        int x = mouse_pos.x / PIXEL_SIZE;
        int y = mouse_pos.y / PIXEL_SIZE;
        grid[x][y].id = 1;
        grid[x][y].pixel.setFillColor(sf::Color::Yellow);
        // grid[x][y].pixel.setOutlineColor(sf::Color::Green);
      }
    }

    if (update_time > UPDATE_INTERVAL)
    {
      update_time = 0;

      for (int x = GRID_SIZE - 1; x >= 0; x--) {
        for (int y = GRID_SIZE - 1; y >= 0; y--) {
          int id = grid[x][y].id;
          if (grid[x][y].id)
          {
            if (y + 1 < GRID_SIZE && grid[x][y + 1].id == 0)
            {
              temp = grid[x][y + 1];
              grid[x][y + 1] = grid[x][y];
              grid[x][y] = temp;
            }
          }
        }
      }
    }


    // rectangle.setPosition(box1.x, box1.y);
    // sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
    // mouse.setPosition(mouse_pos.x - 17, mouse_pos.y - 17);

    window.clear(sf::Color::Black);
    // window.draw(shape);
    // window.draw(rectangle);
    // window.draw(mouse);

    for (int x = 0; x < GRID_SIZE; x++) {
      for (int y = 0; y < GRID_SIZE; y++) {
        grid[x][y].pixel.setPosition(x * PIXEL_SIZE, y * PIXEL_SIZE);
        window.draw(grid[x][y].pixel);
      }
    }

    window.draw(text);
    window.display();
  }

  return 0;
}



