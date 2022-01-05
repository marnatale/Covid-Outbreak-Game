#include "Building.h"

//Default Constructor
Building::Building(char in_code) : GameObject('B'){
  //The default constructor that initializes the member variables to their initial values
  student_count = 0; //The number of Students currently within this Building, inital 0
  display_code = 'B'; //display_code should be ‘B’
  cout << "Building default constructed" << endl; //prints out the message
}
//Parameterized Constructor
Building::Building(char in_code, int in_id, Point2D in_loc) : GameObject(in_loc, in_id, 'B'){
  /*Initializes the id number to in_id, and the location to in_loc, display_code to
  in_code, and remainder of the member variables to their default initial values. */
  display_code = in_code;
  id_num = in_id;
  location = in_loc;
  student_count = 0; //The number of Students currently within this Building, inital 0
  cout << "Building constructed" << endl; //Prints out the message “Building constructed”.
}

//Public Member Functions
void Building::AddOneStudent(){
  student_count += 1; //Increments student_count by one.
  return;
}

void Building::RemoveOneStudent(){
  student_count -= 1; //Decrements student_count by one.
  return;
}
void Building::ShowStatus(){
  cout << display_code << " " << GetId() << " located at " << location << endl;
  if (student_count == 1){
      cout << "\t" << student_count << " student is in this building" << endl;
  }
  else{
    cout << "\t" << student_count << " students are in this building" << endl;
  }
  //Note:Instead of is/are try to conditionally select which of the verbs to use when printing
  return;
}

bool Building::ShouldBeVisible(){
  //Returns true because buildings are always visible
  return true;
}
