/* 
*  File: bookTickets.c
*
*  Description: Reading and validating user information and ticket generation
*
*  Authors: Manisha L, Sian Gijo
*
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include"../include/ticket.h"


void bookTicket(int source, int destination,int seatNo)
{
	
	struct ticket T1;
	
	//Generates random numbers for ticket number
	srand(time(0));

	//Opening routes.txt, ticket.txt and fare.txt
        FILE *fp = fopen("./data/routes.txt","r");
        FILE *fp2 = fopen("./data/ticket.txt","ab+");
        FILE *fp3=fopen("./data/fare.txt","r");

        
        float srcDistance;
        float destDistance;
	
	
	T1.ticketNo = rand() % 2000 + 1000;
	int flag = 0;

	//Taking User information
        printf("\n\nEnter passenger first name: ");
        scanf("%s",T1.fname);

        printf("\n\nEnter passenger last name: ");
        scanf("%s",T1.lname);

	while(flag != 1){

		printf("\n\nEnter your phone number: ");
		char phoneNum[50];
		scanf("%s",phoneNum);
		T1.phoneNo = atol(phoneNum);
		
		//Checks for validity of phone number 
		if(T1.phoneNo>6000000000 && T1.phoneNo<9999999999)
		{
			flag = 1;
		}
		else{
			printf("\nInvalid phone number. Please Enter a valid phone number\n");

		}
	}

        
        printf("\n\nEnter your age: ");
        scanf("%d",&T1.age);

        T1.seatNo = seatNo + 1;

        int fareRow = source -1 ;
        int fareCol = destination  ;

        char str[70]="";
        int fare;

	//Accessing the fare from the fare.txt
        while(fareRow > 0)
        {
                fgets(str,70,fp3);
                fareRow--;
        }

        while(fareCol > 0)
        {
                fscanf(fp3,"%d",&fare);
                fareCol--;
        }

	T1.fare = fare;

        fclose(fp3);

	//Opening distance.txt file
        fp3 = fopen("./data/distance.txt","r");
	
	//Accessing the distance of source from the 1st stop
        while(fareRow < source-1)
        {
                fscanf(fp3,"%f",&srcDistance);
                fareRow++;
        }
	
	//Accessing the distance of destination from the 1st stop
        while(fareCol < destination-1)
        {
                fscanf(fp3,"%f",&destDistance);
                fareCol++;
        }
	
	
        destination -= source;

	fclose(fp3);
	
	//Accessing the source from routes.txt
        while(source > 0)
        {
                fgets(str,20,fp);
                source--;
        }

        strcpy(T1.boarding,str);

	//Accessing the destination from routes.txt
        while(destination > 0)
        {
                fgets(str,20,fp);
                destination--;
        }

        strcpy(T1.dropping,str);

	
	fclose(fp);

	//Calculating distance from boarding point to drop off point 
	T1.distance = destDistance - srcDistance;

	//Writing ticket structure into the bianry file
        fwrite(&T1,sizeof(struct ticket),1,fp2);
        fflush(fp2);
	fclose(fp2);
	
	
	// Displaying Ticket
        printf("\n*************************************************************************************************\n\n");
        printf("\t\t\t\t\tTICKET\n");
        printf("\n*************************************************************************************************\n\n");
        printf("\t\t\t\tTICKET NUMBER:\tBK%ld\n\n",T1.ticketNo);
        printf("\t\t\t\tPASSENGER NAME:\t%s %s\n\n",T1.fname,T1.lname);
        printf("\t\t\t\tCONTACT NUMBER:\t%ld\n\n",T1.phoneNo);
        printf("\t\t\t\tAGE:\t%d\n\n",T1.age);
        printf("\t\t\t\tBOARDING POINT:\t%s\n\n",T1.boarding);
        printf("\t\t\t\tDROP OFF POINT:\t%s\n\n",T1.dropping);
        printf("\t\t\t\tTOTAL DISTANCE:\t%.2f KM\n\n",T1.distance);
        printf("\t\t\t\tSEAT NO:%d\n\n",T1.seatNo);
        printf("\t\t\t\tTOTAL FARE:  Rs.%d\n\n",T1.fare);
        printf("\n*************************************************************************************************\n");

	


}
