#include <SFML/Graphics.hpp>
#include "constants.h"
#include "element.h"
#include "simulation.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(GRID_SIZE * PIXEL_SIZE, GRID_SIZE * PIXEL_SIZE), "Pixel-Sim");
  // window.setFramerateLimit(30);
  // window.setVerticalSyncEnabled(true);
  // sf::CircleShape shape(100.f);
  // shape.setFillColor(sf::Color::Green);

  Simulation simulation;
  sf::Clock clock; // Starts clock

  int update_time = 0;
  sf::Font font;
  if (!font.loadFromFile("src/JetBrains Mono Regular Nerd Font Complete.ttf"))
  {
    printf("font error\n");
  }
  sf::Text text;
  char string[9];
  int avg_fps = 0;
  float avg_time = 0;
  int fps_array[50];
  int fps_ctr = 0;

  int mouse_radius = 2;
  int remove_radius = 4;

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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
      printf("Goodbye\n");
      window.close();
    }
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
      int x = mouse_pos.x / PIXEL_SIZE;
      int y = mouse_pos.y / PIXEL_SIZE;

      for (int i = mouse_radius * -1; i <= mouse_radius; i++) {
        for (int j = mouse_radius * -1; j <= mouse_radius; j++) {
          if (x + i >= 0 && y + j >= 0 && x + i < GRID_SIZE && y + j < GRID_SIZE)
          {
            simulation.grid[x + i][y + j].id = 1;
            int random = (rand() % 30) - 15; 
            simulation.grid[x + i][y + j].pixel.setFillColor(sf::Color(222, 199 + random, 82));
            // grid[x][y].pixel.setOutlineColor(sf::Color::Green);
          }
        }
      }
    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
      sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
      int x = mouse_pos.x / PIXEL_SIZE;
      int y = mouse_pos.y / PIXEL_SIZE;

      for (int i = remove_radius * -1; i <= remove_radius; i++) {
        for (int j = remove_radius * -1; j <= remove_radius; j++) {
          if (x + i >= 0 && y + j >= 0 && x + i < GRID_SIZE && y + j < GRID_SIZE)
          {
            simulation.grid[x + i][y + j].id = 0;
            simulation.grid[x + i][y + j].pixel.setFillColor(sf::Color(165, 191, 209));
            // grid[x][y].pixel.setOutlineColor(sf::Color::Green);
          }
        }
      } 
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
      sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
      int x = mouse_pos.x / PIXEL_SIZE;
      int y = mouse_pos.y / PIXEL_SIZE;

      for (int i = mouse_radius * -1; i <= mouse_radius; i++) {
        for (int j = mouse_radius * -1; j <= mouse_radius; j++) {
          if (x + i >= 0 && y + j >= 0 && x + i < GRID_SIZE && y + j < GRID_SIZE)
          {
            simulation.grid[x + i][y + j].id = 2;
            int random = (rand() % 4) - 2; 
            simulation.grid[x + i][y + j].pixel.setFillColor(sf::Color(57, 168 + random, 196));
            // grid[x][y].pixel.setOutlineColor(sf::Color::Green);
          }
        }
      }

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
      sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
      int x = mouse_pos.x / PIXEL_SIZE;
      int y = mouse_pos.y / PIXEL_SIZE;

      for (int i = mouse_radius * -1; i <= mouse_radius; i++) {
        for (int j = mouse_radius * -1; j <= mouse_radius; j++) {
          if (x + i >= 0 && y + j >= 0 && x + i < GRID_SIZE && y + j < GRID_SIZE)
          {
            simulation.grid[x + i][y + j].id = 3;
            int random = (rand() % 30) - 15;
            simulation.grid[x + i][y + j].pixel.setFillColor(sf::Color(140 + random, 101, 65));
            // grid[x][y].pixel.setOutlineColor(sf::Color::Green);
          }
        }
      }

    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
      for (int x = 0; x < GRID_SIZE; x++) {
        for (int y = 0; y < GRID_SIZE; y++) {
          simulation.grid[x][y].id = 0;
          simulation.grid[x][y].pixel.setFillColor(sf::Color(165, 191, 209));
        }
      }


    }



    if (update_time > UPDATE_INTERVAL)
    {
      update_time = 0;
      simulation.update();

    }


    window.clear(sf::Color::Black);

    for (int x = 0; x < GRID_SIZE; x++) {
      for (int y = 0; y < GRID_SIZE; y++) {
        simulation.grid[x][y].pixel.setPosition(x * PIXEL_SIZE, y * PIXEL_SIZE);
        window.draw(simulation.grid[x][y].pixel);
      }
    }

    window.draw(text);
    window.display();
  }

  return 0;
}



