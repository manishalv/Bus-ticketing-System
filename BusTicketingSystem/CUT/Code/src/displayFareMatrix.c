/* 
* File: displayFareMatrix.c
*
* Description: Display Fare as a matrix
*
* Author: Sian Gijo, Manisha L.
*
*/

#include<stdio.h>
#include<stdlib.h>



void displayFareMatrix(void){

        char str[50];

	//To count the number of lines in the file
        int nlines = 1;

        char line[100] = "";
	
	//Opening the files fare.txt and routes.txt
        FILE *fp = fopen("./data/fare.txt","r");
        FILE *fp2 = fopen("./data/routes.txt","r");

	//Counts the lines from the Fare Matrix
        while( fgets(line, 100 , fp) != NULL)
        {
                nlines++;
        }
	
	//Dynamic Allocation of fare matrix 
	int** fareMatrix = (int**)malloc(nlines * sizeof(int*));
   	for (int i = 0; i < nlines; i++)
        	fareMatrix[i] = (int*)malloc(nlines * sizeof(int));
        

	//To bring file pointer to the beginning of the file.
        rewind(fp);
	
	//Reading Fare Matrix from fare.txt
        for(int i = 0 ; i < nlines - 1 ; i++)
        {
                for(int j = 0 ; j < nlines ; j++)
                {
                        fscanf(fp,"%d",&fareMatrix[i][j]);
                }
        }

        printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t\t\tFARE MATRIX ");
        printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\n\n\tMAJESTIC\tMADIWALA\tBOMMASANDRA\tHOSUR\t\tKOCHI\t\tETTUMANOOR\tKOTTAYAM\tCHINGAVANAM\n");

	
	
        for(int i = 0 ; i < nlines - 1 ; i++)
        {
		//Displaying Routes
 
                if(fgets(str,20,fp2) != NULL)
                        printf("%s\t",str);		


                for(int j = 0 ; j < nlines ; j++)
				
			//Displaying NA- Not Applicable if Fare is 0

                        if(fareMatrix[i][j] == 0){
                                
				printf("NA\t\t");
			 
                        }
                        else{
				//Displaying Fares
 
                                printf("Rs.%d\t\t",fareMatrix[i][j]);	
                        }

                printf("\n");
        }

	free(fareMatrix);

        printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------\n\n");

}
