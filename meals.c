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

float getBreakfastCost() // asks for and returns the amount spent on a single breakfast meal
{
    return getCost("breakfast");
}
float getLunchCost()     // asks for and returns the amount spent on a single lunch meal
{
    return getCost("lunch");
}
float getDinnerCost()    // asks for and returns the amount spent on a single dinner meal
{
    return getCost("dinner");
}

float getCost(char meal[]) //asks for and returns for cost in general.
{

    float input;
    char buff[100]; //to hold input
    int invalid; //flag

    printf("How much did you spend for %s? ",meal);

    do
    {

        fflush(stdout);
        scanf("%s", buff);
        

        invalid = validatePrice(buff); //validating buff

        if (invalid == 1)
            printf("\nOnly digits 0-9 are allowed, and only 1 dot. Try again: ");

    } while (invalid == 1);


    input = atof(buff); //saving price

   return input;

}


int validatePrice(char str[]) //validates price typed by user.
{
    int strLength = strlen(str);
    int dotCount = 0;


    for (int i = 0; i < strLength; i++)
    {

        switch (str[i]) //check for every valid char
        {
        case '0':
            break;
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        case '9':
            break;
        case '.':
            dotCount++;
            break;
        default:
            return 1; //if character doesn't match any case, input is invalid. Return true.
            break;
        }

         if (dotCount > 1)
            return 1; //if there are more than 1 dots, invalid input. return true.

    }

    return 0; //if str only contains valid chars and only has 1 dot at most, valid input. return false.

}

