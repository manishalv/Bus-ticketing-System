/* 
*  File: displayTickets.c
*
*  Description: Displays the booked tickets from the binary file
*  
*  Authors: Sian Gijo, Manisha L.
*
*/

#include<stdio.h>
#include"../include/ticket.h"


int displayTickets(void)
{
	struct ticket T2;
	
	//Opening the ticket.txt file 
        FILE *fp2 = fopen("./data/ticket.txt","r");

	if(fp2 == NULL)
	{
		printf("No records\n");
		return 0;
	}

	printf("\n-------------------------------------------------------\n");
	printf("\n\t\tTICKET RECORDS\n");
	printf("\n-------------------------------------------------------\n");

	//Reading from binary file.
        while(fread(&T2,sizeof(struct ticket),1,fp2))
        {

                printf(" Ticket No : BK%ld\n Name : %s %s\n Phone No : %ld\n Seat No : S%d\n Fare : Rs.%d\n Boarding Point : %s \n Drop off Point : %s \n Total Distance : %.2f KM \n",T2.ticketNo,T2.fname, T2.lname,T2.phoneNo,T2.seatNo,T2.fare,T2.boarding , T2.dropping,T2.distance);
                printf("\n-------------------------------------------------------\n");
        }

        fclose(fp2);

}
