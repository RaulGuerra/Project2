//=========================================================================================
// Name:  Raul Guerra Umana
//        Sammy Alsadek
//        Kamaile Fitzgerald
//        Moina Veron
// File:  main.c
// Date:  September 30, 2021 8:11PM
//
// Description:
//        Program that calculates and displays the total
//        travel expenses of a businessperson on a trip
//=========================================================================================

// INCLUDED FILES
#include <stdio.h>
#include "times.h"
#include "travel.h"
#include "rooms.h"
#include "meals.h"

// EXTERNAL VARIABLES
extern float mealsExcessCost;
extern float mealsSavedCost;
extern float roomExcessCost;
extern float roomSavedCost;
extern float travelExcessCost;
extern float travelSavedCost;
extern const float BREAKFAST_ALLOWED_COST;
extern const float LUNCH_ALLOWED_COST;
extern const float DINNER_ALLOWED_COST;
extern const float ROOM_ALLOWED_COST;
extern const float PARKING_ALLOWED_COST;
extern const float TAXI_ALLOWED_COST;

int main(void)
{
  // Declare variables
  int numOfDays;               // number of days on trip
  int departureTime;           // time of departure
  int arrivalTime;             // time of arrival
  float ticketCost;            // cost of round trip ticket
  float carRentalCost;         // cost of rental car used
  float milesDrivenCost;       // number of miles driven in private vehicle
  float parkingFees = 0;       // parking fees spent on trip
  float taxiFees = 0;          // taxi fees spent on trip
  float confFees;              // conference and seminar fees spent on trip
  float hotelCost = 0;         // money spent on hotel rooms
  float breakfastCost = 0;     // money spent on breakfast
  float lunchCost = 0;         // money spent on lunch
  float dinnerCost = 0;        // money spent on dinner
  float totalExpense;          // total expenses spent on trip
  float totalAllowableExpense; // total expenses allows for the trip
  float excessSpent;           // excess amount spent on trip
  float moneySaved;            // moeny that was saved on trip

  // Print title
  printf("==========================================================================\n");
  printf("=                       BUSINESS EXPENSE CALCULATOR                      =\n");
  printf("==========================================================================\n");

  // Get days spent and departure and arrival times from user
  numOfDays = getDays();
  departureTime = getDeparture();
  arrivalTime = getArrival();

  // Get costs of items that are not on a per day basis
  ticketCost = getTicketCost();
  carRentalCost = getCarRentalCost();
  milesDrivenCost = getMilesDriven() * 0.27;
  confFees = getConferenceFee();

  // Get costs of items that are on a per day basis
  for (int i = 0; i < numOfDays; i++)
  {
    printf("\n");
    printf("Day %d -\n", i + 1); // Print the day the information is being input for

    // Accumulate the expenses for the days spent on the trip
    parkingFees += getParkingFee();
    taxiFees += getTaxiFee();
    hotelCost += getHotelCost();

    // If its the first day then check cases for meals
    if (i == 0)
    {
      // If departure is before 7AM all meals are included
      if (departureTime < 7)
      {
        breakfastCost += getBreakfastCost();
        lunchCost += getLunchCost();
        dinnerCost += getDinnerCost();
      }
      // If departure is before 12PM but after 7AM only lunch and dinner are included
      else if (departureTime < 12)
      {
        lunchCost += getLunchCost();
        dinnerCost += getDinnerCost();
      }
      // If departure is before 6PM but after 12PM only dinner is included
      else if (departureTime < 18)
      {
        dinnerCost += getDinnerCost();
      }
    }
    // If its the last day then check cases for meals
    else if (i == numOfDays - 1)
    {
      // If arrival is after 7PM all meals are included
      if (arrivalTime >= 19)
      {
        breakfastCost += getBreakfastCost();
        lunchCost += getLunchCost();
        dinnerCost += getDinnerCost();
      }
      // If arrival is after 1PM but before 7PM only breakfast and lunch are included
      else if (arrivalTime >= 13)
      {
        breakfastCost += getBreakfastCost();
        lunchCost += getLunchCost();
      }
      // If arrival is after 8AM but before 1PM only breakfast is included
      else if (arrivalTime >= 8)
      {
        breakfastCost += getBreakfastCost();
      }
    }
    // If its neither the first or the last day then the are no conditions
    else
    {
      breakfastCost += getBreakfastCost();
      lunchCost += getLunchCost();
      dinnerCost += getDinnerCost();
    }
  }

  // Calculate total spent, allowable expenses, excess spent, and money saved
  totalExpense = ticketCost + carRentalCost + milesDrivenCost + parkingFees + taxiFees + confFees + hotelCost + breakfastCost + lunchCost + dinnerCost;
  totalAllowableExpense = ticketCost + carRentalCost + milesDrivenCost + confFees + (numOfDays * (PARKING_ALLOWED_COST + TAXI_ALLOWED_COST + ROOM_ALLOWED_COST + BREAKFAST_ALLOWED_COST + LUNCH_ALLOWED_COST + DINNER_ALLOWED_COST));
  excessSpent = roomExcessCost + mealsExcessCost + travelExcessCost;
  moneySaved = roomSavedCost + mealsSavedCost + travelSavedCost;

  // Print results
  printf("\n");
  printf("==========================================================================\n");
  printf("Total Expenses Incurred:     $%.2f\n", totalExpense);
  printf("Total Allowable Expenses:    $%.2f\n", totalAllowableExpense);
  printf("Excess Expenses Accumulated: $%.2f\n", excessSpent);
  printf("Saved Expenses Accumulated:  $%.2f\n", moneySaved);
  printf("==========================================================================\n");

  return 0;
}
