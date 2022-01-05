#include "Vector2D.h"

//Default Constructor
Vector2D::Vector2D(){
  //Initializes x and y to 0.0
  x = 0.0;
  y = 0.0;
}

//Parameterized Constructor
Vector2D::Vector2D(double in_x, double in_y){
  //Sets x and y to in_x and in_y, respectively.
  x = in_x;
  y = in_y;
}

//Non-member Overloaded Operators

  //Stream output operator (<<):
  ostream& operator << (ostream& out, Vector2D v1){
    //produce output formatted as <x, y>
    out << "<" << v1.x << ", " << v1.y << ">" << endl;
    return out;
  }

  //Multiplication operator (*):
   Vector2D operator * ( Vector2D v1, double d){
    //v1 * d returns a Vector2D object with x = v1.x *d and y = v1.y * d
    Vector2D* val = new Vector2D(v1.x * d, v1.y * d);
    return *val;
  }

  //Division operator (/):
   Vector2D operator / (Vector2D v1, double d){
    // v1 / d returns a Vector2D object with x = v1.x / d and y = v1.y / d
    Vector2D* val = new Vector2D(v1.x / d, v1.y / d);
    return *val;
  }
