#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void displayFareMatrix(void){

        char str[14];
        int nlines = 1;
        char line[100] = "";

        FILE *fp = fopen("./data/fare.txt","r");
        FILE *fp2 = fopen("./data/routes.txt","r");

	//Counts the rows or column lines from the Fare Matrix
        while( fgets(line, 100 , fp) != NULL)
        {
                nlines++;
        }

	
        int matrix[nlines][nlines];

        rewind(fp);
	
	//Reading Fare Matrix from fare.txt
        for(int i = 0 ; i < nlines - 1 ; i++)
        {
                for(int j = 0 ; j < nlines ; j++)
                {
                        fscanf(fp,"%d",&matrix[i][j]);
                }
        }

        printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\t\t\t\t\t\t\tFARE MATRIX ");
        printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------\n\n");
        printf("\n\n\tMAJESTIC\tMADIWALA\tBOMMASANDRA\tHOSUR\t\tKOCHI\t\tETTUMANOOR\tKOTTAYAM\tCHINGAVANAM\n");

        for(int i = 0 ; i < nlines - 1 ; i++)
        {
                if(fgets(str,20,fp2) != NULL)				//Displaying Routes 
                        printf("%s\t",str);		


                for(int j = 0 ; j < nlines ; j++)
                        if(matrix[i][j]==0){

                                printf("NA\t\t");			//Displaying NA if Fare is 0 
                        }
                        else{

                                printf("Rs.%d\t\t",matrix[i][j]);	//Displaying Fares 
                        }

                printf("\n");
        }

        printf("\n\n-----------------------------------------------------------------------------------------------------------------------------------\n\n");

}