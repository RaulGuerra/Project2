//=========================================================================================
// Name:  Raul Guerra Umana
//        Sammy Alsadek
//        Kamaile Fitzgerald
//        Moina Veron
// File:  meals.h
// Date:  October 1, 2021 12:05AM
//=========================================================================================


#ifndef MEALS_H
#define MEALS_H
float getBreakfastCost(); // asks for and returns the amount spent on a single breakfast meal
float getLunchCost();     // asks for and returns the amount spent on a single lunch meal
float getDinnerCost();    // asks for and returns the amount spent on a single dinner meal
float getCost(char meal[]); //asks for and returns for cost in general.
int validatePrice(char str[]); //validates price typed by user.

#endif