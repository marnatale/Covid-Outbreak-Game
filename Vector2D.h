#ifndef VECTOR2D //if these functions aren’t defined
#define VECTOR2D //define these functions
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

class Vector2D{
  public:
    double x; // x value of the point
    double y; // y value of the point

    //Constructors
    Vector2D();
    Vector2D(double x, double y);
};

Vector2D operator * (Vector2D v1, double d);
Vector2D operator / (Vector2D v1, double d);
ostream& operator << (ostream& out, Vector2D v1);

#endif
