#include<stdio.h>
#include<stdlib.h>

void displayRoute()
{
        char str[20]; 
        int i = 1;

        FILE *fp = fopen("./data/routes.txt","r");

        printf("\n\n----------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t\t  ROUTE DETAILS");
        printf("\n\n----------------------------------------------------------------------------------------------------------------------\n\n");
	
	//Displaying Routes from the file fp

        while(fgets(str,20,fp)!=NULL){
                printf("\t\t\t\t\t\tSTOP %d  : ",i);
                puts(str);
                i++;
        }


}