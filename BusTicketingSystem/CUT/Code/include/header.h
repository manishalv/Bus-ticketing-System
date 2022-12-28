/* 
*  File: 
*	header.h
*
*  Description:
*        Contains function declarations and macro definitions to be shared between several source files.
*
*  Authors:
*	Karishma Shaik, Anusha Nallam
*/


//defining macros for better visibility of options in switch case
#define DISPLAYROUTE 1
#define DISPLAYSEATMATRIX 2
#define DISPLAYTICKETS 3
#define EXIT 4
#define ROW 10
#define COLUMN 8



// function declarations

//function to display the routes
int displayRoute(void);

//function to display the FareMatrix
void displayFareMatrix(void);

//function to display SeatMatrix and checks the availability of seats
int displaySeatMatrix(void);

//gets the details from users 
void bookTicket(int source,int destination,int seatNo);

//fuction to diplay the tickets
int displayTickets(void);

