#include "simulation.h"
#include <SFML/Graphics.hpp>


Simulation::Simulation() {
  printf("Simulation Started\n");

  simulation_flip_flop = 1;
}


void Simulation::update() {

  if (simulation_flip_flop)
  {
    for (int y = GRID_SIZE - 1; y >= 0; y--) {
      for (int x = 0; x < GRID_SIZE; x++) {
        update_actions(x, y);
      }
    }

    simulation_flip_flop = 0;
  } else
  {
    for (int y = GRID_SIZE - 1; y >= 0; y--) {
      for (int x = GRID_SIZE - 1; x >= 0; x--) {
        update_actions(x, y);
      }
    }

    simulation_flip_flop = 1;
  }

}

void Simulation::update_actions(int x, int y) {
  int id = grid[x][y].id;

  if (simulation_flip_flop)
  {
    if (grid[x][y].id == 1 && y + 1 < GRID_SIZE)
    {
      if (grid[x][y + 1].id == 0 || grid[x][y + 1].id == 2)
      {
        temp = grid[x][y + 1];
        grid[x][y + 1] = grid[x][y];
        grid[x][y] = temp;
      } else if (x > 0 && grid[x - 1][y + 1].id == 0 || x > 0 && grid[x - 1][y + 1].id == 2)
      {
        temp = grid[x - 1][y + 1];
        grid[x - 1][y + 1] = grid[x][y];
        grid[x][y] = temp;
      } else if (x + 1 < GRID_SIZE && grid[x + 1][y + 1].id == 0 || x + 1 < GRID_SIZE && grid[x + 1][y + 1].id == 2)
      {
        temp = grid[x + 1][y + 1];
        grid[x + 1][y + 1] = grid[x][y];
        grid[x][y] = temp;
      }
    } else if (grid[x][y].id == 2)
    {

      if (y + 1 < GRID_SIZE && grid[x][y + 1].id == 0)
      {
        temp = grid[x][y + 1];
        grid[x][y + 1] = grid[x][y];
        grid[x][y] = temp;
      }  else if (x + 1 < GRID_SIZE && y + 1 < GRID_SIZE && grid[x + 1][y + 1].id == 0)
      {
        temp = grid[x + 1][y + 1];
        grid[x + 1][y + 1] = grid[x][y];
        grid[x][y] = temp;
      } else if (x > 0 && y + 1 < GRID_SIZE && grid[x - 1][y + 1].id == 0)
      {
        temp = grid[x - 1][y + 1];
        grid[x - 1][y + 1] = grid[x][y];
        grid[x][y] = temp;
      } else if (x > 0 && grid[x - 1][y].id == 0)
      {
        temp = grid[x - 1][y];
        grid[x - 1][y] = grid[x][y];
        grid[x][y] = temp;
      } else if (x + 1 < GRID_SIZE && grid[x + 1][y].id == 0)
      {
        temp = grid[x + 1][y];
        grid[x + 1][y] = grid[x][y];
        grid[x][y] = temp;
      }


    }

  } else
  {

    if (grid[x][y].id == 1 && y + 1 < GRID_SIZE)
    {
      if (grid[x][y + 1].id == 0 || grid[x][y + 1].id == 2)
      {
        temp = grid[x][y + 1];
        grid[x][y + 1] = grid[x][y];
        grid[x][y] = temp;
      } else if (x + 1 < GRID_SIZE && grid[x + 1][y + 1].id == 0 || x + 1 < GRID_SIZE && grid[x + 1][y + 1].id == 2)
      {
        temp = grid[x + 1][y + 1];
        grid[x + 1][y + 1] = grid[x][y];
        grid[x][y] = temp;
      } else if (x > 0 && grid[x - 1][y + 1].id == 0 || x > 0 && grid[x - 1][y + 1].id == 2)
      {
        temp = grid[x - 1][y + 1];
        grid[x - 1][y + 1] = grid[x][y];
        grid[x][y] = temp;
      } 
    } else if (grid[x][y].id == 2)
    {

      if (y + 1 < GRID_SIZE && grid[x][y + 1].id == 0)
      {
        temp = grid[x][y + 1];
        grid[x][y + 1] = grid[x][y];
        grid[x][y] = temp;
      }  else if (x > 0 && y + 1 < GRID_SIZE && grid[x - 1][y + 1].id == 0)
      {
        temp = grid[x - 1][y + 1];
        grid[x - 1][y + 1] = grid[x][y];
        grid[x][y] = temp;
      } else if (x + 1 < GRID_SIZE && y + 1 < GRID_SIZE && grid[x + 1][y + 1].id == 0)
      {
        temp = grid[x + 1][y + 1];
        grid[x + 1][y + 1] = grid[x][y];
        grid[x][y] = temp;
      }  else if (x + 1 < GRID_SIZE && grid[x + 1][y].id == 0)
      {
        temp = grid[x + 1][y];
        grid[x + 1][y] = grid[x][y];
        grid[x][y] = temp;
      } else if (x > 0 && grid[x - 1][y].id == 0)
      {
        temp = grid[x - 1][y];
        grid[x - 1][y] = grid[x][y];
        grid[x][y] = temp;
      } 


    }
  }

}
