#ifndef VIRUS //if these functions aren’t defined
#define VIRUS //define these functions
#include <iostream>
#include "GameObject.h"
#include "Student.h"
using namespace std;

enum VirusStates{
  IN_ENVIRONMENT = 0,
  DEAD = 1,
  IN_STUDENT = 2,
};

class Virus: public GameObject {
  protected:
  	double virulence;
  	double resistance;
  	bool variant;
    double energy;
    bool is_in_student;
    string name;
  	Student* current_student;

  public:
    Virus(string, int, Point2D);
    Virus(string, double, double, double, bool, int, Point2D);
    void infect(Student* s);
    bool get_variant();
    double get_virulence();
    double get_resistance();
    double get_energy();
    bool get_in_student();
    bool Update();
    void ShowStatus();
    bool IsAlive();
    bool ShouldBeVisible();
    virtual ~Virus();
};


#endif
