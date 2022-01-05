#ifndef BUILDING //if these functions aren’t defined
#define BUILDING //define these functions
#include <iostream>
#include "GameObject.h"
#include <math.h>
using namespace std;

class Building : public GameObject {
  public:
    //Constructors
      Building(char);
      Building(char, int, Point2D);

    //Public Member Functions
      void AddOneStudent();
      void RemoveOneStudent();
      void ShowStatus();
      bool ShouldBeVisible();
  private:
    //Private Members
      unsigned int student_count;
};

#endif
