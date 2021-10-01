#include "header.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Global variables
static int dTime[2]; //stores arrival time. aTime[0] = hour, aTime[1] = minutes
static int aTime[2]; //stores departure time. dTime[0] = hour, dTime[1] = minutes
static int totalDays; //stores total days of the trip

int validatePosiInt(char str[]) //Function only accepts positive integer as valid.
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


void getHours(char string1[])
{
    
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
            int input = atoi(str); //converting string to int

            if (input > 23) //case in which input is invalid
            {
                printf("\nIncorrect input. Please type a number between 0 and 23.\n");
                invalidTime = 1; //resetting flag.
            }
            else //case in which input is valid
            {
                if (strcmp(string1, "arrival") == 0)
                {
                    aTime[0] = input; //storing hour in aTime.
                    invalidTime = 0; //Valid input. Setting flag. Ending loop.
                }
                else
                {
                    dTime[0] = input; //storing hour in dTime.
                    invalidTime = 0; //Valid input. Setting flag. Ending loop.
                }
                
                
            }           
        }
        else
        {
            printf("\nIncorrect input. Please type a number between 0 and 23.\n");
            invalidTime = 1; //resetting flag.
        }
        
        
    } while (invalidTime);


    invalidTime = 1; //resetting flag for next loop




    do //asking for arrival minutes
    {
        printf("Input %s minutes (i.e. 0 - 59): ", string1);

        char str[100]; //to store input

        scanf("%s", str); //asking for input

        isValid = validatePosiInt(str); //validating input, Function ensures positive integer.

        if (isValid)
        {
            //checking if input is between 0 and 59
            int input = atoi(str); //converting string to int

            if (input > 59) //case in which input is invalid
            {
                printf("\nIncorrect input. Please type a number between 0 and 59.\n");
                invalidTime = 1; //resetting flag.
            }
            else //case in which input is valid
            {
                 if (strcmp(string1, "arrival") == 0)
                {
                    aTime[1] = input; //storing hour in aTime.
                    invalidTime = 0; //Valid input. Setting flag. Ending loop.
                }
                else
                {
                    dTime[1] = input; //storing hour in dTime.
                    invalidTime = 0; //Valid input. Setting flag. Ending loop.
                }
            }           
        }
        else
        {
            printf("\nIncorrect input. Please type a number between 0 and 59.\n");
            invalidTime = 1; //resetting flag.
        }
        
        
    } while (invalidTime);


};


void getTimes()
{
    getHours("departure");
    getHours("arrival");


    //----------PRINTING DEPARTURE AND ARRIVAL
    printf("Departure time is ");

    if(dTime[0] < 10) //print hour
    {
        printf("0%d:", dTime[0]);

        if (dTime[1]<10) //print minute
        {
            printf("0%d", dTime[1]);
        }
        
    }
    else
    {

        printf("%d:", dTime[0]);

        if (dTime[1]<10) //print minute
            printf("0%d", dTime[1]);
        else
            printf("%d", dTime[1]);

    }

    printf("\nArrival time is ");

    if(aTime[0] < 10) //print hour
    {
        printf("0%d:", aTime[0]);

        if (aTime[1]<10) //print minute
            printf("0%d", aTime[1]);
        else
            printf("%d", aTime[1]);
    }
    else
    {

        printf("%d:", aTime[0]);

        if (aTime[1]<10) //print minute
            printf("0%d", aTime[1]);
        else
            printf("%d", aTime[1]);

    }

    printf("\n\n");

    //---------END PRINTING DEPARTURE AND ARRIVAL
    


};


int getDays() //function asks how many days the trip was, stores in static int totalDays, and also returns the number of days.
{

    int flag = 1; //flag for input validation, stops loop

    printf("How many days was your trip? ");

    do
    {
        char str[100]; //to store input

        scanf("%s", str); //asking for input

        int isValid = validatePosiInt(str);
        
        if (isValid)
        {
            int input = atoi(str); //converting string to int
            
                //no limit
                totalDays = input; //save total days
                flag = 0; //exit loop

                
            
            //with limiti  
          /*if (input <= 7)
            {
                totalDays = input; //save total days
                flag = 0; //exit loop
            }
            else
                printf("\nInvalid input (no more than 7 days per trip). Try again: ");*/
            
        }
        else
            printf("\nInvalid input. Try again: ");


    } while (flag);
    
    return totalDays;

}
