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

int main(void)
{
  // Declare variables
  int numOfDays;
  int departureTime;
  int arrivalTime;
  float ticketCost;
  float carRentalCost;
  float milesDriven;
  float parkingFees;
  float taxiFees;
  float confFees;
  float hotelCost;
  float breakfastCost;
  float lunchCost;
  float dinnerCost;

  // Get days spent and departure and arrival times from user
  numOfDays = getDays();
  departureTime = getDeparture();
  arrivalTime = getArrival();

  // Get costs of items that are not on a per day basis
  ticketCost = getTicketCost();
  carRentalCost = getCarRentalCost();
  milesDriven = getMilesDriven();
  confFees = getConferenceFee();

  // Get costs of items that are on a per day basis
  for (int i = 0; i < numOfDays; i++)
  {
    printf("Day %d -\n", i); // Print the day the information is being input for

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
      else if (departureTime < 16)
      {
        dinnerCost += getDinnerCost();
      }
    }
    // If its the last day then check cases for meals
    else if (i == numOfDays - 1)
    {
      // If arrival is after 7PM all meals are included
      if (arrivalTime >= 7)
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

  return 0;
}
