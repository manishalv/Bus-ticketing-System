#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include"../include/header.h"

int main(void){

        int return_val;
        char choice[10];
	
        printf("\n\n----------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\tWELCOME TO THE BUS TICKETING SYSTEM");
        printf("\n\n----------------------------------------------------------------------------------------------------------------------\n");

        while(1)
        {
                printf( "\n\n\t\t\t\t\t1 : View bus route details\n\n\t\t\t\t\t2 : View Seat Availability and Book your ticket\n\n\t\t\t\t\t3 : Display the Ticket Records\n\n\t\t\t\t\t4 : Quit\n\n");
                printf("\n\nEnter your choice  ");

                scanf("%s",choice);

		int c=atoi(choice);

		//Displaying options to the user
                switch(c)
                {
                        case 1: displayRoute();
                                displayFareMatrix();
                                break;

                        case 2: return_val = displaySeatMatrix();
                                break;
				
			case 3: displayTickets();
				break;

                        case 4: exit(0);

                        default: printf("\n\nInvalid choice! Please re-check if you've entered the integer from the given range \n");
                }
        }
}