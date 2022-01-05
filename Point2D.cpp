#include "Point2D.h"

//Default Constructor
Point2D::Point2D(){
  //Initializes x and y to 0.0
  x = 0.0;
  y = 0.0;
}

//Parameterized Constructor
Point2D::Point2D(double in_x, double in_y){
  //Sets x and y to in_x and in_y, respectively.
  x = in_x;
  y = in_y;
}


//Non-member Function
double GetDistanceBetween(Point2D p1, Point2D p2){
  //Returns the Cartesian (ordinary) distance between p1 and p2.
  double temp = sqrt(pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2));
  return temp;
}

//Non-member Overloaded Operators

  //Boolean == operator
  bool operator == (Point2D p1, Point2D p2){
    return (p2.x == p1.x && p2.y == p1.y);
  }

  //Stream output operator (<<)
  ostream& operator << (ostream& out, Point2D p1){
    //produces output formatted as (x, y)
    out << "(" << p1.x << "," << p1.y << ")";
    return out;
  }

  //Addition operator (+)
   Point2D operator + (Point2D p1,  Vector2D v1){
    //p1 + v1 returns a Point2D object with x = p1.x + v1.x and y = p1.y + v1.y
    Point2D* val = new Point2D(p1.x + v1.x, p1.y + v1.y);
    return *val;
  }

  //Subtraction operator (-)
   Vector2D operator - (Point2D p1,  Point2D p2){
    //p1 - p2 returns a Vector2D object with x = p1.x - p2.x and y = p1.x - p2.x
    Vector2D* val = new Vector2D(p1.x - p2.x, p1.y - p2.y);
    return *val;
  }
