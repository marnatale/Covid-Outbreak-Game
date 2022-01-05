#include "DoctorsOffice.h"

//Default Constructor
DoctorsOffice::DoctorsOffice():Building('D'){
  display_code = 'D';
  vaccine_capacity = 100;
  num_vaccine_remaining = vaccine_capacity;
  dollar_cost_per_vaccine = 5;
  state = VACCINE_AVAILABLE;
  cout << "DoctorsOffice default constructed" << endl;
}

//Parameterized Constructor
DoctorsOffice::DoctorsOffice(int in_id, double vaccine_cost, unsigned int vaccine_cap, Point2D in_loc):Building('D', in_id, in_loc){
  id_num = in_id;
  location = in_loc;
  display_code = 'D';
  dollar_cost_per_vaccine = vaccine_cost;
  vaccine_capacity = vaccine_cap;
  num_vaccine_remaining = vaccine_capacity;
  state = VACCINE_AVAILABLE;
  cout << "DoctorsOffice constructed" << endl;
}


bool DoctorsOffice::HasVaccine(){
  //Returns true if this Doctors Office contains at least one vaccine.
  if (num_vaccine_remaining >= 1){
    return true;
  }
  else{
    return false;
  }
}
unsigned int DoctorsOffice::GetNumVaccineRemaining(){
  //Returns the number of vaccines remaining in this DoctorsOffice.
  return num_vaccine_remaining;
}
bool DoctorsOffice::CanAffordVaccine(unsigned int vaccine, double budget){
  //Returns true if this Student can afford to purchase vaccine with the given budget.
  if (dollar_cost_per_vaccine <= budget){
    return true;
  }
  else{
    return false;
  }
}
double DoctorsOffice::GetDollarCost(unsigned int vaccine){
  //Returns the dollar cost for the specified number of vaccines
  return dollar_cost_per_vaccine * vaccine;
}
unsigned int DoctorsOffice::DistributeVaccine(unsigned int vaccine_needed){
  if (num_vaccine_remaining >= vaccine_needed){
    //If num_vaccine_remaining in the DoctorsOffice is >= to vaccine_needed
    num_vaccine_remaining -= vaccine_needed; //it subtracts vaccine_needed from DoctorsOffice amount
    return vaccine_needed; // returns vaccine_needed
  }
  else{
    //If the amount of vaccine in the DoctorsOffice is less,
    return GetNumVaccineRemaining();   //it returns the DoctorsOffince current amount
    num_vaccine_remaining = 0;    //the DoctorsOffice vaccine amount is set to 0
  }
}
bool DoctorsOffice::Update(){
//If the DoctorsOffice has no vaccine remaining and the state hasn't changed (just ran out)
  if (num_vaccine_remaining < 1)
  {
    state = NO_VACCINE_AVAILABLE;
    display_code = 'd';
    cout << "DoctorsOffice (" << id_num << ") has ran out of vaccine." << endl;
    return true;
  }
  else
  {
    state = VACCINE_AVAILABLE;
    display_code = 'D';
    return false;
    AddOneStudent();
  }
}

void DoctorsOffice::ShowStatus(){
  //Prints out the status of the object:
    cout << "DoctorsOffice Status: " << endl;
    Building::ShowStatus();
    GetNumVaccineRemaining();
    cout << "\tDollars per vaccine: " << dollar_cost_per_vaccine << endl;
    cout << "\t" << display_code << GetId() << ": has " << GetNumVaccineRemaining() << " vaccine(s) remaining" << endl;
    return;
}
