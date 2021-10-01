//main file

#include <stdio.h>
#include "meals.c"


//Global variables. Track overall expenditures. Doesn't include allowance from job.
int static totalDays;
double static airfareCost; 
double static carRentalCost;
double static personalMiles; //tracks miles on personal carr only, not cost of these miles.
double static parkingCost;
double static taxiCost;
double static regCost; //registration costs.
double static hotelCost;



int main(void)
{
  int check;
  check = getTimes();

  return 0;
  
}
