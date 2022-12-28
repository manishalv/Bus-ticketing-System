/* 
*  File: 
*	ticket.h
*
*  Description:
*        Contains Ticket Structure declaration 
*
*  Authors:
*	Arveti Chandana Gayatri, Kappa Latha
*/

struct ticket{
        long ticketNo;
        char fname[30];
        char lname[30];
        long phoneNo;
        int age;
        char boarding[50];
        char dropping[50];
	int fare;
	float distance;
	int seatNo;
};