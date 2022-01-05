#ifndef VIEW //if these functions aren’t defined
#define VIEW //define these functions
#include "Point2D.h"
#include "GameObject.h"
#include <iostream>
using namespace std;

const int view_maxsize = 20; //the maximum size of the grid array

class View
{
  private:
    int size; //the current size of the grid to be displayed; not all of the grid array will be displayed in this project.
    double scale; //the distance represented by each cell of the grid
    Point2D origin; //the coordinates of the lower left-hand corner of the grid
    char grid[view_maxsize][view_maxsize][2]; //an array to hold the characters that make up the display grid.
    bool GetSubscripts(int &out_x, int &out_y, Point2D location);

  public:
    View();
    void Clear();
    void Plot(GameObject * ptr);
    void Draw();
};

#endif
