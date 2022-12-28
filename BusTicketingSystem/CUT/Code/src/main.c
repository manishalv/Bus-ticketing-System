/*
* File: main.c
*
* Description: Menu driven program with multiple options
*
* Authors: Kappa Latha, Arveti Chandana Gayathri.
*
*/

#include<stdio.h>
#include<stdlib.h>
#include"../include/header.h"


int main(void){

        
        char choice[10];
	
        printf("\n\n----------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tWELCOME TO THE BUS TICKETING SYSTEM");
        printf("\n\n----------------------------------------------------------------------------------------------------------------------\n");

        while(1)
        {
                printf( "\n\n\t\t\t\t\t1 : View bus route details\n\n\t\t\t\t\t2 : View Seat Availability and Book your ticket\n\n\t\t\t\t\t3 : Display the Ticket Records\n\n\t\t\t\t\t4 : Quit\n\n");
                printf("\n\nEnter your choice: ");

                scanf("%s",choice);
		
		//Converting the string to integer
		int choiceNum = atoi(choice);

		//Displaying options to the user
                switch(choiceNum)
                {
                        case DISPLAYROUTE: displayRoute();
                                	   displayFareMatrix();
                                	   break;

                        case DISPLAYSEATMATRIX: displaySeatMatrix();
                                		break;
				
			case DISPLAYTICKETS: displayTickets();
					     break;

                        case EXIT: exit(0);

                        default: printf("\n\nInvalid choice! Please re-check if you've entered the integer from the given range \n");
                }
        }
	return 0;
}
