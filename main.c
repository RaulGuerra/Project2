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
  getTimes(); //times will be stored in two static arrays: aTime[] and dTime[].

  int daysTest = getDays(); //days will also be stored in static int totalDays after the function call.
  printf("\nint daysTest = %d. int static totalDays = %d", daysTest, totalDays); //testing output

  return 0;
  
}
