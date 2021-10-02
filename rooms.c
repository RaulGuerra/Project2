//=========================================================================================
// Name:  Raul Guerra Umana
//        Sammy Alsadek
//        Kamaile Fitzgerald
//        Moina Veron
// File:  rooms.c
// Date:  September 30, 2021 11:42PM
//
// Description: File responsible for asking user for the price of the conferences and hotels
//              getConferenceFee() and getHotelCost() are to be called by main.
//=========================================================================================

// INCLUDED FILES
#include <stdio.h>
#include "rooms.h"

// GLOBAL VARIABLES
static float roomExcessCost = 0;
static float roomSavedCost = 0;
const float ROOM_ALLOWED_COST = 90.00;

// asks for and returns amount spent on conference and seminar fees
float getConferenceFee()
{
    float input;
    _Bool isValid = 0;
    do
    {
        printf("How much was spent on conference and seminar fees? $");
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

// asks for and return amount spend on a hotel for a single night
float getHotelCost()
{
    float input;
    _Bool isValid = 0;

    do
    {
        printf("\tHow much was spent on a hotel room this night? $");
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

    if (input > ROOM_ALLOWED_COST) 
    {
        roomExcessCost += input - ROOM_ALLOWED_COST;
    }
    else
    {
        roomSavedCost += ROOM_ALLOWED_COST - input; 
    }

    return input;
}