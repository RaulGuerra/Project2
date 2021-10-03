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

// GLOBAL VARIABLES
static float travelExcessCost = 0;
static float travelSavedCost = 0;
const float PARKING_ALLOWED_COST = 6.00;
const float TAXI_ALLOWED_COST = 10.00;

float getTicketCost() // asks for and return cost of round trip ticket
{
    float input;
    _Bool isValid = 0;

    do
    {
        printf("How much was the round trip ticket? $");
        scanf("%f", &input);
        fflush(stdin);
        isValid = 1;

        if (input < 0)
        {
            printf("\n");
            printf("ERROR: Invalid input. Cost must be >= $0.00");
            printf("\n");
            isValid = 0;
        }
    } while (!isValid);

    return input;
}

float getCarRentalCost() // asks for and return the cost spent on a car rental
{
    //declare & initialize variable
    float cost = 0;
    _Bool isValid = 0;

    do
    {
        //ask for user input
        printf("How much was spent on car rentals? $");
        scanf("%f", &cost);
        fflush(stdin);
        isValid = 1;

        if (cost < 0)
        {
            printf("\n");
            printf("ERROR: Invalid input. Cost must be >= $0.00");
            printf("\n");
            isValid = 0;
        }
    } while (!isValid);

    return cost;
}

float getMilesDriven() // asks for and return the number of miles driven in a private vehicle
{
    //declare & initialize variable
    float miles = 0;
    _Bool isValid = 0;

    do
    {
        //ask for user input
        printf("How many miles did you drive? ");
        scanf("%f", &miles);
        fflush(stdin);
        isValid = 1;

        if (miles < 0)
        {
            printf("\n");
            printf("ERROR: Invalid input. Miles input must be >= 0");
            printf("\n");
            isValid = 0;
        }
    }while (!isValid);
    
    return miles;
}

float getParkingFee() // asks for and returns the amout spent on parking fees for a single day
{
    float input;
    _Bool isValid = 0;

    do
    {
        printf("\tHow much was spent on a parking this day? $");
        scanf("%f", &input);
        fflush(stdin);
        isValid = 1;

        if (input < 0)
        {
            printf("\n");
            printf("\tERROR: Invalid input. Cost must be >= $0.00");
            printf("\n");
            isValid = 0;
        }
    } while (!isValid);

    if (input > PARKING_ALLOWED_COST) 
    {
        travelExcessCost += input - PARKING_ALLOWED_COST;
    }
    else
    {
        travelSavedCost += PARKING_ALLOWED_COST - input; 
    }

    return input; 
}

float getTaxiFee() // asks for and returns the amount spent on taxis for a single day
{
    float input;
    _Bool isValid = 0;

    do
    {
        printf("\tHow much was spent on a taxis this day? $");
        scanf("%f", &input);
        fflush(stdin);
        isValid = 1;

        if (input < 0)
        {
            printf("\n");
            printf("\tERROR: Invalid input. Cost must be >= $0.00");
            printf("\n");
            isValid = 0;
        }
    } while (!isValid);

    if (input > TAXI_ALLOWED_COST) 
    {
        travelExcessCost += input - TAXI_ALLOWED_COST;
    }
    else
    {
        travelSavedCost += TAXI_ALLOWED_COST - input; 
    }

    return input; 
}
