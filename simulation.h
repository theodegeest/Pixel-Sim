#ifndef SIMULATION_H
#define SIMULATION_H

#define GRID_SIZE 150
#define PIXEL_SIZE 7

#include <SFML/Graphics.hpp>
#include "element.h"

class Simulation {
  public:

    Element grid[GRID_SIZE][GRID_SIZE];
    Element temp;

    void update();
    Simulation();
  private:

    int simulation_flip_flop;
    void update_actions(int x, int y);
};

#endif
