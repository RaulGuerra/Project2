//=========================================================================================
// Name:  Raul Guerra Umana
//        Sammy Alsadek
//        Kamaile Fitzgerald
//        Moina Veron
// File:  meals.c
// Date:  September 30, 2021 11:42PM
//
// Description: File responsible for asking user for the price of the meals he had.
//              getBreakfastCost(), float getLunchCost(), float getDinnerCost() are to be called by main.
//=========================================================================================

// INCLUDED FILES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "meals.h"

// GLOBAL VARIABLES
static float mealsExcessCost = 0;
static float mealsSavedCost = 0;
const float BREAKFAST_ALLOWED_COST = 9.00;
const float LUNCH_ALLOWED_COST = 12.00;
const float DINNER_ALLOWED_COST = 16.00;

float getBreakfastCost() // asks for and returns the amount spent on a single breakfast meal
{
    float input = getCost("breakfast");

    if (input > BREAKFAST_ALLOWED_COST)
    {
        mealsExcessCost += input - BREAKFAST_ALLOWED_COST;
    }
    else
    {
        mealsSavedCost += BREAKFAST_ALLOWED_COST - input;
    }

    return input;
}
float getLunchCost() // asks for and returns the amount spent on a single lunch meal
{
    float input = getCost("lunch");

    if (input > LUNCH_ALLOWED_COST)
    {
        mealsExcessCost += input - LUNCH_ALLOWED_COST;
    }
    else
    {
        mealsSavedCost += LUNCH_ALLOWED_COST - input;
    }

    return input;
}
float getDinnerCost() // asks for and returns the amount spent on a single dinner meal
{
    float input = getCost("dinner");

    if (input > DINNER_ALLOWED_COST)
    {
        mealsExcessCost += input - DINNER_ALLOWED_COST;
    }
    else
    {
        mealsSavedCost += DINNER_ALLOWED_COST - input;
    }

    return input;
}

float getCost(char meal[]) //asks for and returns for cost in general.
{
    float input;
    _Bool isValid = 0; //flag

    do
    {
        printf("\tHow much did you spend for %s this day? $", meal);
        scanf("%f", &input);
        fflush(stdin);
        isValid = 1;

        if (input < 0)
        {
            printf("\n");
            printf("\tERROR: Invalid input. Cost must be >= $0.00\n");
            printf("\n");
            isValid = 0;
        }
    } while (!isValid);

    return input;
}