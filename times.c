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
#include <string.h>
#include <stdlib.h>
#include "times.h"

//Global variables

int validatePosiInt(char str[]) //method only accepts positive integer as valid.
{
    int strLength = strlen(str);
    

    for (int i = 0; i < strLength; i++)
    {
        char c = str[i];

        switch (c) //check for every valid char
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
        default:
            return 0; //if character doesn't match any case, input is invalid. Return false.
            break;
        }
    }

    return 1; //if str only contains valid chars, valid input. return true.

}

int getHours(char string1[]) //method asks user for input on hours of arrival or departure, depending on the parameter
{
    int input; //to return valid input
    int invalidTime = 1; //flag to end loops. 0 = false, 1 = true
    int isValid; //flag to check user input. 0 = false, 1 = true

    printf("Please type %s time.\n", string1);

    do //asking for arrival hour in military time.
    {
        printf("Input %s hour in military time (i.e. 0 - 23): ", string1);

        char str[100]; //to store input

        scanf("%s", str); //asking for input

        isValid = validatePosiInt(str); //validating input, Function ensures positive integer.

        if (isValid)
        {
            //checking if input is between 0 and 23
            input = atoi(str); //converting string to int

            if (input > 23) //case in which input is invalid
            {
                printf("\nIncorrect input. Please type a number between 0 and 23.\n");
                invalidTime = 1; //resetting flag.
            }
            else //case in which input is valid
               return input;
       
        }
        else
        {
            printf("\nIncorrect input. Please type a number between 0 and 23.\n");
            invalidTime = 1; //resetting flag.
        }
        
        
    } while (invalidTime);

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
    int input; //days according to user. To be returned.
    int flag = 1; //flag for input validation, stops loop

    printf("How many days was your trip? ");

    do
    {
        char str[100]; //to store input

        scanf("%s", str); //asking for input

        int isValid = validatePosiInt(str);
        
        if (isValid)
        {
            input = atoi(str); //converting string to int

            if (input < 1) //
            {
                printf("\nInvalid input. Trips must be 1 day or longer. Try again: ");
            }
            else
                flag = 0;
            
            
        }
        else
            printf("\nInvalid input. Try again: ");


    } while (flag);
    
    return input;

}
