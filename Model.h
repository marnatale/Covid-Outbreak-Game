#ifndef MODEL //if these functions aren’t defined
#define MODEL //define these functions
#include <iostream>
#include "GameObject.h"
#include "View.h"
#include "Virus.h"
#include "Student.h"
#include <list>
#include <iterator>

using namespace std;

class Model
{
  friend class GameObject;
  private:
  	int time; //the simulation time.
/*
    GameObject * object_ptrs[10];
    int num_objects;
    Student * student_ptrs[10];
    int num_students;
    DoctorsOffice * office_ptrs[10];
    int num_offices;
    ClassRoom * class_ptrs[10];
    int num_classes;
*/
  list <GameObject*> object_ptrs;
  list <GameObject*> :: iterator i;
  list <GameObject*> active_ptrs;
  list <Student*> student_ptrs;
  list <Student*> :: iterator j;
  list <Virus*> virus_ptrs;
  list <Virus*> :: iterator v;
  list <ClassRoom*> class_ptrs;
  list <ClassRoom*> :: iterator c;
  list <DoctorsOffice*> office_ptrs;
  list <DoctorsOffice*> :: iterator k;

  public:
     Model();
     ~Model();
     Student * GetStudentPtr(int id);
     DoctorsOffice * GetDoctorsOfficePtr(int id);
     ClassRoom * GetClassRoomPtr(int id);
     bool Update();
     void Display(View& view);
     void ShowStatus();
};
#endif
