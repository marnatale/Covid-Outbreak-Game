#ifndef POINT2D //if these functions aren’t defined
#define POINT2D //define these functions
#include "Vector2D.h"
#include <iostream>
#include <math.h>
#include <cmath>
#include <cstdlib>
using namespace std;

class Point2D{
  public:
    double x; // x value of the point
    double y; // y value of the point

    //Constructors
    Point2D();
    Point2D(double, double);

};

//Non-member Functions
double GetDistanceBetween(Point2D p1, Point2D p2);

//Non-member Overloaded Operators
bool operator == (Point2D, Point2D);
ostream& operator << (ostream& out, Point2D p1);
Point2D operator + (Point2D p1, Vector2D v1);
Vector2D operator - (Point2D p1, Point2D p2);

#endif
