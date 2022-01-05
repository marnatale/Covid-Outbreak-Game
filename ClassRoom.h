#ifndef CLASSROOM //if these functions aren’t defined
#define CLASSROOM //define these functions
#include <iostream>
#include "DoctorsOffice.h"
#include "GameObject.h"
using namespace std;

enum ClassRoomStates{
  NOT_PASSED = 0,
  PASSED     = 1
};

class ClassRoom : public Building{
  public:
    //Constructors
      ClassRoom();
      ClassRoom(unsigned int, unsigned int, double, unsigned int, int, Point2D);

    //Public Member Functions
      double GetDollarCost(unsigned int);
      unsigned int GetAntibodyCost(unsigned int);
      unsigned int GetNumAssignmentsRemaining();
      bool IsAbleToLearn(unsigned int, double, unsigned int);
      unsigned int TrainStudents(unsigned int);
      bool Update();
      bool passed();
      void ShowStatus();

  private:
    unsigned int num_assignments_remaining;
    //The amount of assignments remaining in the ClassRoom
    unsigned int max_number_of_assignments;
    //Assignment capacity for this ClassRoom
    unsigned int antibody_cost_per_assignment;
    //Antibody cost for a single assignment (it tires you out when you work)
    double dollar_cost_per_assignment;
    //Dollar cost for single assignment
    unsigned int credits_per_assignment;
    //Amount of credits gained for each assignment
};
#endif
