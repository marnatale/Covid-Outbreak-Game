#include "ClassRoom.h"

//Default Constructor
ClassRoom::ClassRoom():Building('C'){
  //the default constructor that initializes the member variables to their initial values:
  display_code = 'C';
  state = NOT_PASSED;
  max_number_of_assignments = 10;
  num_assignments_remaining = max_number_of_assignments;
  antibody_cost_per_assignment = 1;
  dollar_cost_per_assignment = 1.0;
  credits_per_assignment = 2;
  cout << "ClassRoom default constructed" << endl;
}

//Parameterized Constructor
ClassRoom::ClassRoom(unsigned int max_assign, unsigned int antibody_cost, double dollar_cost,
  unsigned int crd_per_assign, int in_id, Point2D in_loc):Building('C', in_id, in_loc){
    id_num = in_id;
    max_number_of_assignments = max_assign;
    display_code = 'C';
    num_assignments_remaining = max_number_of_assignments;
    antibody_cost_per_assignment = antibody_cost;
    credits_per_assignment = crd_per_assign;
    dollar_cost_per_assignment = dollar_cost;
    location = in_loc;
  //Initializes the rest of the member variables to default values
  state = NOT_PASSED;
  cout << "ClassRoom constructed" << endl;
}

//Public Member Functions

double ClassRoom::GetDollarCost(unsigned int unit_qty){
  //Returns the cost of purchasing “unit_qty” assignments
  return dollar_cost_per_assignment*unit_qty;
}
unsigned int ClassRoom::GetAntibodyCost(unsigned int unit_qty){
  //Returns the amount of antibody required for “unit_qty” assignment
  return antibody_cost_per_assignment*unit_qty;
}
unsigned int ClassRoom::GetNumAssignmentsRemaining(){
  //Returns the number of assignments remaining in this ClassRoom.
  return num_assignments_remaining;
}

bool ClassRoom::IsAbleToLearn(unsigned int unit_qty, double budget, unsigned int antibodies){
  //Returns true if ClassRoom with given budget and antibodies can request to take unit_qty assignment
  double num_assign = budget/dollar_cost_per_assignment;
  double num_assign2 = antibodies/antibody_cost_per_assignment;

  if (num_assign > num_assign2)
  {
    if (unit_qty > num_assign2)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    if (unit_qty > num_assign)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}

unsigned int ClassRoom::TrainStudents(unsigned int assignment_units){
  //Subtracts assignments from num_assigments_remaining if this ClassRoom has enough units.
  if (assignment_units <= num_assignments_remaining){
    num_assignments_remaining -= assignment_units;
    //Returns the number of credits gained by completing the assignments
    unsigned int* credits = new unsigned int (num_assignments_remaining*credits_per_assignment);
    return *credits;
  }
  //If the amount of units requested is greater than the amount available at this ClassRoom,
  //then num_assignments_remaining will be used instead of assignments when calculating credits.
  else{
    //Returns the number of credits gained by completing the assignments
    unsigned int* credits = new unsigned int (num_assignments_remaining*credits_per_assignment);
    return *credits;
  }
}

bool ClassRoom::Update(){
  //If the ClassRoom has zero assignments remaining and the ClassRoom hasn't been passed
    if (num_assignments_remaining == 0)
    {
      state = PASSED;
      display_code = 'c';
      cout << "(" << display_code << ")(" << id_num << ") has been passed." << endl;
      return state;
    }
    else
    {
      state = NOT_PASSED;
      return state;
    }
    return state;
  }

bool ClassRoom::passed(){
  //Returns true if assignments remaining is 0
  if (num_assignments_remaining == 0){
    return true;
  }
  else{
    return false;
  }
}

void ClassRoom::ShowStatus(){
  /* Prints out the status of the object by calling GameObject’s show status
  and then the values of its member variables: */
  cout << "ClassRoom Status: " << endl;
  Building::ShowStatus();
  cout << "\tMax number of assignments: " << max_number_of_assignments << endl;
  cout << "\tAntibody cost per assignment: " << antibody_cost_per_assignment << endl;
  cout << "\tDollar per assignment: " << dollar_cost_per_assignment << endl;
  cout << "\tCredits per assignment: " << credits_per_assignment << endl;
  cout << "\t" << num_assignments_remaining << " assignment(s) are remaining for this ClassRoom" << endl;
  return;
}
