#ifndef DOCTORSOFFICE //if these functions aren’t defined
#define DOCTORSOFFICE //define these functions
#include "GameObject.h"
#include "Building.h"
#include <iostream>
#include <math.h>
using namespace std;

//State Machine Enums:
enum DoctorsOfficeStates{
  VACCINE_AVAILABLE    = 0,
  NO_VACCINE_AVAILABLE = 1
};

class DoctorsOffice : public Building{
  private:
    unsigned int vaccine_capacity;
    //The maximum number of vaccines this DoctorOffice can hold.
    unsigned int num_vaccine_remaining;
    //The amount of vaccine currently in this DoctorsOffice
    double dollar_cost_per_vaccine;
    //The per vaccine cost in DoctorsOffice

  public:
    //Constructors
      DoctorsOffice();
      DoctorsOffice(int, double, unsigned int, Point2D);
    //Public Member Functions
      bool HasVaccine();
      unsigned int GetNumVaccineRemaining();
      bool CanAffordVaccine(unsigned int, double);
      double GetDollarCost(unsigned int);
      unsigned int DistributeVaccine(unsigned int);
      bool Update();
      void ShowStatus();
};

#endif
