#ifndef GAMEOBJECT //if these functions aren’t defined
#define GAMEOBJECT //define these functions
#include "Point2D.h"
#include <iostream>
#include <math.h>
using namespace std;

class GameObject{
  protected:
    Point2D location; //The location of the object
    int id_num; //This object’s ID
    char display_code; //How the object is represented in the View.
    char state; //State of the object; more information provided in each derived class.

  public:
    GameObject(char in_code);
    GameObject(Point2D in_loc, int in_id, char in_code);
    virtual ~GameObject();
    Point2D GetLocation();
    int GetId();
    char GetState();
    virtual void ShowStatus();
    virtual bool Update()=0;
    virtual bool ShouldBeVisible()=0;
    void DrawSelf(char * ptr);
};
#endif
