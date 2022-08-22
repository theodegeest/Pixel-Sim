#ifndef SIMULATION_H
#define SIMULATION_H

#include <SFML/Graphics.hpp>
#include "element.h"
#include "constants.h"

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
