#include "Model.h"

Model::Model(){
  time = 0;
/*
  //Student 1
  student_ptrs[0] = new Student("Homer", 1, 'S', 2.0, Point2D(5, 1));
  object_ptrs[0] = student_ptrs[0];
  //Student 2
  student_ptrs[1] = new Student("Marge", 2, 'S', 1.0, Point2D(10, 1));
  object_ptrs[1] = student_ptrs[1];
  //DoctorsOffice 1
  office_ptrs[0] = new DoctorsOffice(1, 1, 100, Point2D(1, 20));
  object_ptrs[2] = office_ptrs[0];
  //DoctorsOffice 2
  office_ptrs[1] = new DoctorsOffice(2, 2, 200,  Point2D(10, 20));
  object_ptrs[3] = office_ptrs[1];
  //ClassRoom
  class_ptrs[0] = new ClassRoom(10, 1.0, 2.0, 3, 1, Point2D(0, 0));
  object_ptrs[4] = class_ptrs[0];
  class_ptrs[1] = new ClassRoom(20, 5, 7.5, 8, 2, Point2D(5, 5));
  object_ptrs[5] = class_ptrs[1];
*/

  Student* ptrS1 = new Student("Homer", 1, 'S', 2.0, Point2D(5, 1));
  Student* ptrS2 = new Student("Marge", 2, 'S', 1.0, Point2D(10, 1));

  DoctorsOffice* ptrD1 = new DoctorsOffice(1, 1, 100, Point2D(1, 20));
  DoctorsOffice* ptrD2 = new DoctorsOffice(2, 2, 200,  Point2D(10, 20));

  ClassRoom* ptrC1 = new ClassRoom(10, 1.0, 2.0, 3, 1, Point2D(0, 0));
  ClassRoom* ptrC2 = new ClassRoom(20, 5, 7.5, 8, 2, Point2D(5, 5));

  /*Virus1, (10, 12), object_ptrs[6], virus _ptrs[0]
  Virus2, (15, 5), object_ptrs[7], virus _ptrs[1]
  */
  Virus* ptrV1 = new Virus("COVID-19", 1, Point2D(10, 12));
  Virus* ptrV2 = new Virus("FLU", 2, Point2D(15, 5));

/*  //num_objects = 6;
  num_objects = 8;
  num_students = 2;
  num_offices = 2;
  num_classes = 2;
  num_virus = 2;
*/

  object_ptrs.push_back(ptrS1);
  object_ptrs.push_back(ptrS2);
  object_ptrs.push_back(ptrD1);
  object_ptrs.push_back(ptrD2);
  object_ptrs.push_back(ptrC1);
  object_ptrs.push_back(ptrC2);
  object_ptrs.push_back(ptrV1);
  object_ptrs.push_back(ptrV2);

  active_ptrs.assign(object_ptrs.begin(), object_ptrs.end());

  student_ptrs.push_back(ptrS1);
  student_ptrs.push_back(ptrS2);

  office_ptrs.push_back(ptrD1);
  office_ptrs.push_back(ptrD2);

  class_ptrs.push_back(ptrC1);
  class_ptrs.push_back(ptrC2);

  virus_ptrs.push_back(ptrV1);
  virus_ptrs.push_back(ptrV2);


  cout << "Model default constructed" << endl;
}

Model::~Model(){
    for (i = object_ptrs.begin(); i != object_ptrs.end(); i++){
      delete *i;
    }
    cout << "Model destructed." << endl;
}

Student *Model::GetStudentPtr(int id) {
    for (j = student_ptrs.begin(); j != student_ptrs.end(); j++){
        if (id == (*j)->GetId()) {
            return (*j);
        }
    }
    return 0;
}

DoctorsOffice *Model::GetDoctorsOfficePtr(int id) {
    for (k = office_ptrs.begin(); k != office_ptrs.end(); k++){
        if (id == (*k)->GetId()) {
            return (*k);
        }
    }
    return 0;
}

ClassRoom *Model::GetClassRoomPtr(int id) {
    for (c = class_ptrs.begin(); c != class_ptrs.end(); c++){
        if (id == (*c)->GetId()) {
            return (*c);
        }
    }
    return 0;
}

bool Model::Update() {
    time++;
    int classes_passed = 0;
    int students_infected = 0;
    //Calculating number of classes passed
    if (classes_passed != class_ptrs.size()) {
        for (c = class_ptrs.begin(); c != class_ptrs.end(); c++){
            if ((*c)->GetState() == PASSED){
                classes_passed++;
            }
        }
    }
    // Calculating number of students that are infrected
    if (students_infected != student_ptrs.size()) {
        for (j = student_ptrs.begin(); j != student_ptrs.end(); j++){
              if ((*j)->IsInfected()) {
                students_infected++;
              }
        }
    }
    //scan the list looking for dead objects;
    //if found, the dead object is removed from the active_ptrs list so that it is no longer updated.
    //For debugging and demonstration purposes, output a message like “Dead object removed”.
    /*  for (i = object_ptrs.begin(); i != object_ptrs.end(); i++){
          if ((*i)->IsAlive() == false){
              delete (*i);
          }
      }
    */
    bool event = false;
    // continue to update all
    if (classes_passed == class_ptrs.size()){
        cout << "GAME OVER: You win! All assigments done!" << endl;
        exit(EXIT_SUCCESS);
    }
    if (students_infected == student_ptrs.size()){
        cout << "GAME OVER: You lose! All of your Students are infected!" << endl;
        exit(EXIT_SUCCESS);
    }
    // update if winning condition is not met
    for (i = object_ptrs.begin(); i != object_ptrs.end(); i++){
        bool temp = (*i)->Update();
        if (temp) {
            event = temp;
        }
    }
    return event;
}

void Model::Display(View &view){
    view.Clear();
    for (i = object_ptrs.begin(); i != object_ptrs.end(); i++){
        if ((*i)->ShouldBeVisible()) {
            view.Plot(*i);
        }
    }
    view.Draw();
}

void Model::ShowStatus() {
    cout << "Time: " << time << endl;
    for (i = object_ptrs.begin(); i != object_ptrs.end(); i++){
        (*i)->ShowStatus();
    }
}
