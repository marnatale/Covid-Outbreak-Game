#include <iostream>
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "ClassRoom.h"
#include "DoctorsOffice.h"
#include "Student.h"
#include "Model.h"
#include "GameCommand.h"
#include "Point2D.h"
#include "View.h"

using namespace std;

int main(){
  cout << "EC327: Introduction to Software Engineering" << endl;
  cout << "Fall 2021" << endl;
  cout<< "Programming Assignment 3" << endl;

  Model *model = new Model();
  View *view = new View();
  model->ShowStatus();
  view->Clear();

  int count = 0;
  char command;
  int student_id;
  Point2D p1;
  int x, y;
  int office_id;
  int class_id;
  unsigned int assignments;
  unsigned int vaccine_needs;

  while (command != 'q'){
    if ((count != 0) && (command == 'g' || command == 'r'))
    {
      DoListCommand(*model);
    }
    model -> Display(*view);
    cout << "Enter command: ";
    cin >> command;

    switch (command){
        case 'm':
        {
            cin >> student_id >> x >> y;
            p1.x = x;
            p1.y = y;
            DoMoveCommand(*model, student_id, p1);
            break;
        }
        case 'd':
        {
            cin >> student_id >> office_id;
            DoMoveToDoctorCommand(*model, student_id, office_id);
            break;
        }
        case 'c':
        {
            cin >> student_id >> class_id;
            DoMoveToClassCommand(*model, student_id, class_id);
            break;
        }
        case 's':
        {
            cin >> student_id;
            DoStopCommand(*model, student_id);
            break;
        }
        case 'a':
        {
            cin >> student_id >> assignments;
            DoLearningCommand(*model, student_id, assignments);
            break;
        }
        case 'v':
        {
            cin >> student_id >> vaccine_needs;
            DoRecoverInOfficeCommand(*model, student_id, vaccine_needs);
            break;
        }
        case 'g':
        {
            DoGoCommand(*model, *view);
        }
        case 'r':
        {
            DoRunCommand(*model, *view);
            break;
        }
    }
    count++;
}// repeat main loop
cout << "Terminating Program" << endl;
model -> Display(*view);
view->~View();
model->~Model();

return 0;
}
