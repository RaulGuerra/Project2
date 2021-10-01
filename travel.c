//=========================================================================================
// Name:  Raul Guerra Umana
//        Sammy Alsadek
//        Kamaile Fitzgerald
//        Moina Veron
// File:  travel.c
// Date:  September 30, 2021 11:42PM
//=========================================================================================

// INCLUDED FILES
#include <stdio.h>
#include "travel.h"

float getTicketCost() // asks for and return cost of round trip ticket
{
   //declare & initialize variable
   float cost = 0;

   //ask for user input
   printf("How much was the round trip ticket?\n");
   scanf("%f", cost);

   return cost;
}
float getCarRentalCost() // asks for and return the cost spent on a car rental
{
   //declare & initialize variable
   float cost = 0;

   //ask for user input
   printf("How much was the car rental?\n");
   scanf("%f", cost);

   return cost;
}

float getMilesDriven() // asks for and return the number of miles driven in a private vehicle
{
   //should program ask miles driven total or by day?
   //declare & initialize variable
   float miles = 0;
   char user_input;

   printf("Did you drive a personal vehicle?");
   scanf("%c", user_input);

   //validate input
   while (user_input != 'Y' || user_input != 'y' ||
          user_input != 'N' || user_input != 'n')
   {
      printf("Invalid input. Enter 'Y' or 'N':");
      scanf("%c", user_input);
   }

   //ask for miles
   if (user_input == 'y' || user_input == 'Y')
   {
      printf("How many miles did you drive?\n");
      scanf("%f", miles);
   }

   return miles;
}

float getParkingFee() // asks for and returns the amout spent on parking fees for a single day
{
   return 0; //temp
}

float getTaxiFee() // asks for and returns the amount spent on taxis for a single day
{
   return 0; //temp
}
