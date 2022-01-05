#include "GameCommand.h"

void DoMoveCommand(Model & model, int student_id, Point2D p1){
  //If the command arguments are valid
  if (student_id == 1 || student_id == 2){
    model.GetStudentPtr(student_id) -> StartMoving(p1);
    cout << "Moving S" << student_id << " to " << p1 << endl;
  }
  else{
   cout << "Error: Please enter a valid command!" << endl;
 }
  return;
}

void DoMoveToDoctorCommand(Model & model, int student_id, int office_id){
  //If the command arguments are valid
  if (student_id == 1 || student_id == 2){
    model.GetStudentPtr(student_id) -> StartMovingToDoctor(model.GetDoctorsOfficePtr(office_id));
    cout << "Moving S" << student_id << " to doctors office " << office_id << endl;
  }
   else{
     cout << "Error: Please enter a valid command!" << endl;
   }
   return;
}

void DoMoveToClassCommand(Model & model, int student_id, int class_id){
  if (student_id == 1 || student_id == 2){
    model.GetStudentPtr(student_id) -> StartMovingToClass(model.GetClassRoomPtr(class_id));
    cout << "Moving S" << student_id << " to class " << class_id << endl;
  }
  else{
     cout << "Error: Please enter a valid command!" << endl;
  }
  return;
}

void DoStopCommand(Model & model, int student_id){
  if (student_id == 1 || student_id == 2){
    model.GetStudentPtr(student_id) -> Stop();
    cout << "Stopping S" << student_id << endl;
  }
  else{
     cout << "Error: Please enter a valid command!" << endl;
  }
  return;
}

void DoLearningCommand(Model & model, int student_id, unsigned int assignments){
  if (student_id == 1 || student_id == 2){
    model.GetStudentPtr(student_id) -> StartLearning(assignments);
    cout << "Teaching S" << student_id << endl;
  }
  else{
     cout << "Error: Please enter a valid command!" << endl;
  }
  return;
}

void DoRecoverInOfficeCommand(Model& model, int student_id, unsigned int vaccine_needs){
  if (student_id == 1 || student_id == 2){
    model.GetStudentPtr(student_id) -> StartRecoveringAntibodies(vaccine_needs);
    cout << "Recovering S" << student_id << "’s antibodies" << endl;
  }
  else{
     cout << "Error: Please enter a valid command!" << endl;
  }
  return;
}

void DoGoCommand(Model& model, View& view){
    cout << "Advancing one tick." << endl;
    model.Update();
  return;
}

void DoRunCommand(Model& model, View& view){
  bool var = model.Update(); // calls update at least once
  int counter = 0;
  while (!var && counter < 4) // allows this loop to run 4 times because 5th time is outside of loop
  {
    var = model.Update();
    counter++;
  }
  cout << "Advancing to next event." << endl;
  return;
}

void DoListCommand(Model& model)
{
  model.ShowStatus();
}
