/* 
*  File: displaySeatMatrix.c
*
*  Description: Takes input from the user and checks the desired seat availability
*
*  Author: Manisha L, Sian Gijo.
*
*/
#include<stdio.h>
#include<stdlib.h>
#include"../include/header.h"

int seatMatrix[ROW][COLUMN]={0};

int displaySeatMatrix(void)
{
        char ch;
        char source[10];
        char destination[10];
        char seatNo[10];
	int sourceVal;
	int destinationVal;
	int seatNoVal;

        printf("\n\n--------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t0 - SEAT VACANT\t\t1 - SEAT OCCUPIED");
        printf("\n\n--------------------------------------------------------------------------------------------------------------------------------\n\n");
       	printf("\tMAJESTIC --> MADIWALA ---> BOMMASANDRA -----> HOSUR -------> KOCHI -----> ETTUMANOOR ----> KOTTAYAM -----> CHINGAVANAM\n");

	
	//Displaying Seat Avalability
        for(int i = 0 ; i < ROW ; i++)
        {
                printf("S%d\t",i+1);
                for(int j = 0 ; j < COLUMN ; j++)
                {
                        printf("%d\t\t",seatMatrix[i][j]);        
                }
                printf("\n");
        }
	
	//Read boarding and drop off point from the user
        printf("\n\nTo Select your boarding and Drop off Point\n\n");
        printf("\t\tPress\n");

        printf("\n\t1->MAJESTIC\n\t2->MADIWALA\n\t3->BOMMASANDRA\n\t4->HOSUR\n\t5->KOCHI\n\t6->ETTUMANOOR\n\t7->KOTTAYAM\n\t8->CHINGAVANAM\n\n");
        
	printf("\nBoarding point : ");
        scanf("%s",source);
	
	
	sourceVal = atoi(source);

	if(sourceVal > COLUMN || sourceVal < 1)
	{
		printf("\n\nInvalid source or destination ! Please re-check the codes\n");
                return 0;
        }

        printf("\n\nDrop off point : ");
        scanf("%s",destination);
	
	destinationVal = atoi(destination);
	

        if(sourceVal >= destinationVal || destinationVal > COLUMN || destinationVal < 1)
        {
                printf("\n\nInvalid source or destination ! Please re-check the codes\n");
                return 0;
        }

        printf("\n\nEnter your seat number: ");
        scanf("%s",seatNo);

	seatNoVal = atoi(seatNo);

	if(seatNoVal > ROW || seatNoVal < 1){

		printf("\nPlease enter a valid seat number from 1 - 10\n");
		return 0;
	}
	
	//Decrementing to use the values as indices in the matrix
        sourceVal--;
        destinationVal--;
        seatNoVal--;

	//Checks for vacancy of the seats 
        for(int j = sourceVal  ; j < destinationVal ; j++){

                if(seatMatrix[seatNoVal][j] != 0){

                        printf("\n\nSorry the selected seat is already booked\n\n");
                        return 0;
                }
        }


        printf("\n\nHurray your seats are available!!!. \n");
	printf("\nPress 'y' to continue booking your seats or press any key to exit : ");

        scanf(" %c",&ch);
	
	//Navigates to bookTicket function if user wants to continue booking.
	if(ch == 'y' || ch == 'Y')
        {
                for(int j = sourceVal ; j < destinationVal ; j++)

                        seatMatrix[seatNoVal][j] = 1;
		

                bookTicket(sourceVal + 1, destinationVal + 1, seatNoVal);
        }
	else{
		
		return 0;
	}
	
	
}

	
        
		
	

