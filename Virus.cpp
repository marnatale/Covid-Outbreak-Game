#include "Virus.h"

Virus::Virus(string name, int id, Point2D in_loc):GameObject('V'){
  this->name = name;
  virulence = 5; //Initial value is 5
  resistance = 2; //Initial value is 2
  variant = false; //Initial value is false
  energy = 10; //Initial value is 10
  is_in_student = false;
  current_student = NULL;
  cout << "Virus default constructed" << endl;
}

Virus::Virus(string name, double virulence, double resistance, double energy,
bool variant, int id, Point2D in_loc):GameObject(in_loc, id_num, 'V'){
  this->virulence = 5; //Initial value is 5
  this->resistance = 2; //Initial value is 2
  this->variant = false; //Initial value is false
  this->energy = 10; //Initial value is 10
  is_in_student = false; //Default is false
  this->name = name;
  id_num = id;
  location = in_loc;
  current_student = NULL; //Holds the current student it is infecting
  cout << "Virus constructed" << endl;
}

void Virus::infect(Student* s){
  //Modify your program so that if a virus and student are on the same location, the virus infects the student.
  Student* current_student = s;
  Point2D locS = (*current_student).GetLocation();
  Point2D locV = location;
  double dist = GetDistanceBetween(locS, locV);
  if (dist == 0){
      cout << "S" << (*current_student).GetId() << " is infected." << endl;
      this -> state = IN_STUDENT;
  }
  //This requires that you set the Student in the Virus object
  //You modify student as needed to say they have a Virus – you will likely have to add material to the Student class
  //When the Student moves it also moves the Virus with it – when a Student moves check if they have a Virus and if so, move it as well.
  //When the student does anything its antibodies are affected differently if they have a Virus
}

Virus::~Virus()
{
    cout << "Virus destructed. " << endl;
}

bool Virus::get_variant(){
  return variant;
}

double Virus::get_virulence(){
  return virulence;
}

double Virus::get_resistance(){
  return resistance;
}

double Virus::get_energy(){
  return energy;
}

bool Virus::get_in_student(){
  return is_in_student;
}

bool Virus::Update(){
  switch(state){
    //state ‘IN_ENVIRONMENT: This is the default state when we create a Virus and it returns false;
    case IN_ENVIRONMENT:
      return false;
      break;
    case DEAD:
      if(energy <= 0){
        return true;
      }
      break;
    case IN_STUDENT:
      is_in_student = true;
      return true;
      break;
  }
  //state ‘IN_ENVIRONMENT: This is the default state when we create a Virus and it returns false;
  //state ‘DEAD: When the Virus’ energy is 0 or below
  //state ‘IN_STUDENT’: when the Virus is in a student
}

void Virus::ShowStatus(){
  //It outputs something like "Virus status:",
  //then functions similar to Student::show_status() where it calls Game_Object::show_status
  //that outputs state specific information, for example if the Virus is alive or not alive.
  cout << name << " status: ";
  GameObject::ShowStatus();
  switch (state)
	{
	case IN_ENVIRONMENT:
		cout << "\tStopped." << endl;
		break;
	case DEAD:
	    cout << "\tVirus Dead." << endl;
		break;
	case IN_STUDENT:
      cout << "S" << (*current_student).GetId() << " is infected." << endl;
      break;
  }
}

bool Virus::ShouldBeVisible()
{
  return IsAlive();
}

bool Virus::IsAlive(){
  //Check the energy of a virus and return True if it is alive
  if (state == DEAD || energy == 0){
    return false;
  }
  else{
    return true;
  }
}
