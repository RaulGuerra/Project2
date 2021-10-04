//=========================================================================================
// Name:  Raul Guerra Umana
//        Sammy Alsadek
//        Kamaile Fitzgerald
//        Moina Veron
// File:  times.c
// Date:  September 30, 2021 11:30PM
//
// Description: File with methods to capture data from user. The main public methods are
//              getArrival(), getDeparture(), getDays().
//=========================================================================================

// INCLUDED FILES
#include <stdio.h>
#include "times.h"

int getHours(char string1[]) //method asks user for input on hours of arrival or departure, depending on the parameter
{
    int input;       //to return valid input
    int isValid = 0; //flag to check user input. 0 = false, 1 = true

    do //asking for arrival hour in military time.
    {
        printf("Input %s hour in military time (i.e. 0 - 23): ", string1);
        scanf("%d", &input);
        fflush(stdin);
        isValid = 1;

        if (input < 0 || input > 23) // output error message if invalid input
        {
            printf("\n");
            printf("ERROR: Invalid input. Please type a number between 0 and 23.\n");
            printf("\n");
            isValid = 0;
        }
    } while (!isValid);

    return input;
};

int getArrival() // method returns arrival time.
{
    return getHours("arrival");
}

int getDeparture() //method returns departure time.
{
    return getHours("departure");
}

int getDays() //function asks how many days the trip was, stores in static int totalDays, and also returns the number of days.
{
    int input;         //days according to user. To be returned.
    _Bool isValid = 0; //flag for input validation, stops loop

    do
    {
        printf("How many days was your trip? ");
        scanf("%d", &input);
        fflush(stdin);
        isValid = 1;

        if (input < 1) // output error message if invalid input
        {
            printf("\n");
            printf("ERROR: Invalid input. Trips must be 1 day or longer.\n");
            printf("\n");
            isValid = 0;
        }
    } while (!isValid);

    return input;
}
