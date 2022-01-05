#ifndef STUDENT //if these functions aren’t defined
#define STUDENT //define these functions
#include <iostream>
#include "GameObject.h"
#include "DoctorsOffice.h"
#include "ClassRoom.h"
#include <math.h>
using namespace std;

enum StudentStates{
  STOPPED = 0,
  MOVING = 1,
  INFECTED = 2,
  AT_DOCTORS = 3,
  IN_CLASS = 4,
  MOVING_TO_DOCTOR = 5,
  MOVING_TO_CLASS = 6,
  STUDYING_IN_CLASS = 7,
  RECOVERING_ANTIBODIES = 8
};

class Student : public GameObject {
//  friend class DoctorsOffice;

  public:
    Student();
    Student(char);
    Student(string, int, char, unsigned int, Point2D);
    virtual ~Student();
    void StartMoving(Point2D);
    void StartMovingToClass(ClassRoom*);
    void StartMovingToDoctor(DoctorsOffice*);
    void StartLearning(unsigned int);
    void StartRecoveringAntibodies(unsigned int);
    void Stop();
    bool IsInfected();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    //string GetName();

  protected:
    bool UpdateLocation();
    void SetupDestination(Point2D);

  private:
    double speed; //The speed this object travels, expressed as distance per update time unit.
    bool is_at_doctor; //Set to true of the Student is in a DoctorsOffice. Initial value should be false.
    bool is_in_class; //Set to true if this Student is in a ClassRoom. Initial value should be false.
    unsigned int antibodies; // Amount of antibodies a Student has. Initial value should be 20.
    unsigned int credits; //The amount of credits points this Student has. Initial value should be 0.
    double dollars; //The total amount of dollars this Student holds. Initial value should be 0.
    unsigned int assignments_to_buy; //Stores the number of assignments to buy when in a ClassRoom. Initial value should be 0.
    unsigned int vaccines_to_buy; //Stores the number of vaccines to buy when in a DoctorsOffice. Initial value should be 0.
    string name; //The name of this Student.
    DoctorsOffice* current_office; //A pointer to the current DoctorsOffice. Initial value should be 0 (NULL).
    ClassRoom* current_class; //A pointer to the current ClassRoom. Initial value should be 0 (NULL).
    Point2D destination; //This object’s current destinationc oordinates in the real plane. Point2D’s default constructor will initialize this to (0.0, 0.0).
    Vector2D delta; //Contains the x and y amounts that the object will move on each time unit. See “How Student Moves” for more information.
};

double GetRandomAmountOfDollars();

#endif
