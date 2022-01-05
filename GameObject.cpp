#include "GameObject.h"

//Default Constructor
GameObject::GameObject(char in_code){
  /*Initializes the display_code to in_code, id_num to 1, and state to 0.
  It outputs the message: “GameObject constructed”. */
  display_code = in_code;
  id_num = 1;
  state = 0;
  location = Point2D();
  cout << "GameObject constructed" << endl;
}

//Parameterized Constructor
GameObject::GameObject(Point2D in_loc, int in_id, char in_code){
  /*Initializes the display_ code, id_num, and location. The state should be 0.
  It outputs the message: “GameObject constructed”. */
  display_code = in_code;
  id_num = in_id;
  location.x = in_loc.x;
  location.y = in_loc.y;
  state = 0;
  cout << "GameObject constructed" << endl;
}


//Public Member Functions
Point2D GameObject::GetLocation(){
  //Returns the location for this object.
  return location;
}

int GameObject::GetId(){
  //Returns the id for this object
  return id_num;
}

char GameObject::GetState(){
  //Returns the state for this object.
  return state;
}

void GameObject::ShowStatus(){
  /* Outputs the information contained in this class: display_code, id_num, location.
  i.e. “(display_code)(id_num) at (location)”. See sample output for exact formatting. */
  cout << "\t" << display_code << id_num << ": at " << location << endl;
  return;
}

void GameObject::DrawSelf(char * ptr){
    if (*ptr == '.')
    {
      *ptr = this -> display_code;
      *(ptr + 1) = this -> GetId() + 48;
    }
    else
    {
      *ptr = '*';
      *(ptr + 1) = ' ';
    }
}

bool GameObject::Update()
{
  return false; // virtual function, so other functions should be called instead of this one
}

GameObject::~GameObject(){
  cout << "GameObject destructed." << endl;
}
