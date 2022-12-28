/*
/* 
* File: displayRoutes.c
*
* Description: Displaying route details from file.
*
* Author: Arveti Chandana Gayatri, Kappa Latha.
*
*/

#include<stdio.h>
#include<stdlib.h>

int displayRoute()
{
        char str[20]; 
        int stopNumber = 1;
	
	//Opening the routes.txt file.
        FILE *fp = fopen("./data/routes.txt","r");

        printf("\n\n----------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t\t  ROUTE DETAILS");
        printf("\n\n----------------------------------------------------------------------------------------------------------------------\n\n");
	
	//Displaying Routes from the file routes.txt

        while(fgets(str,20,fp)!=NULL){
                printf("\t\t\t\t\t\tSTOP %d  : ",stopNumber);
                puts(str);
                stopNumber++;
        }

	return 0;
}
