#include<stdio.h>
#include"../include/ticket.h"


void displayTickets(void)
{

        FILE *fp2 = fopen("./data/ticket.txt","r");
	if(fp2 == NULL)
	{
		printf("No records\n");
		return;
	}
	printf("\n-------------------------------------------------------\n");
	printf("\n\t\tTICKET RECORDS\n");
	printf("\n-------------------------------------------------------\n");
        while(fread(&T1,sizeof(struct ticket),1,fp2))
        {

                printf(" Ticket No : BK%ld\n Name : %s %s\n Phone No : %ld\n Seat No : S%d\n Fare : Rs.%d\n Boarding Point : %s \n Drop off Point : %s \n Total Distance : %.2f KM \n",T1.ticketNo,T1.fname, T1.lname,T1.phoneNo,T1.seatNo,T1.fare,T1.boarding , T1.dropping,T1.distance);
                printf("\n-------------------------------------------------------\n");
        }
        fclose(fp2);

}