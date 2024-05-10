/**************************************************************************
 * File: setmap.c										  		  		  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * Date Created:04/09/2021                            				      *
 * Date Modified: 09/09/2021                              				  *               
 * Purpose: Retreive the metadata from file and set the map				  *
 **************************************************************************/
 
 #include <stdio.h>
 #include <stdlib.h>
 #include "setmap.h"
 
void setTheMap(int* mapRow, int* mapCol, char*** pArray, int* rowOfPlayer, 
			int* colOfPlayer, int* rowOfGoal, int* colOfGoal, int* rowOfEnemy, 
			int* colOfEnemy, FILE* ptrR   )
{
	/* variables and  pointers Declarations*/
	
	int i, j, nRead;
	char objCode;
	char space = ' ';
	int metadataAmount;
	char** array = NULL;
	int row, column, object;
	
	/* Get the metadataAmount, mapRow and column from file */
	
	nRead = fscanf(ptrR, "%d %d %d\n", &metadataAmount, mapRow, mapCol);
	
	/* Check the number of items successfully read */
	
	if( nRead == 3)
	{
		/* generate a 2d char map Array */
		
		array = (char**)malloc(sizeof(char*) * *mapRow);
		
		for( i = 0; i < *mapRow; i++)
		{
			array[i] = (char*)malloc(sizeof(char) * *mapCol );
		}
		
		
		/* set the borders around the map */
	
		for( i = 0; i < *mapRow; i++ )
		{
			for( j = 0; j < *mapCol; j++)
			{
				if( i == 0 || i == *(mapRow)-1)
				{
					if( j == 0 || j == *(mapCol)-1)
					{
						array[i][j] = '#';
					}
					else
					{
						array[i][j] = '-';
					}
				}
				else
				{
					if( j == 0 || j == *(mapCol)-1 )
					{
						array[i][j] ='|';
					}
					else
					{
						array[i][j] = space;
					}
				}
				
				
			}
			
		}
		
		
		/* Set the Player, Enemy, Goal and Wall into the map */
		
		for( i = 0; i < metadataAmount; i++ )
		{
			/* Read the coordinates of the map */
			
			fscanf(ptrR, "%d %d %d\n", &row, &column, &object);
			
			/* Get the row and column of the Player */
			
			if( object == 0)
			{
				objCode = '^';
				*rowOfPlayer = row;
				*colOfPlayer = column;
			}
			else
			{
				/* Get the row and column of the Enemy */
				
				if( object == 1)
				{
					objCode = '~';
					*rowOfEnemy = row;
					*colOfEnemy = column;
				}
				else
				{
					/* Get the row and column of the Goal */
					
					if( object == 2)
					{
						objCode = 'x';
						*rowOfGoal = row;
						*colOfGoal = column;
					} 
					else
					{ 
						objCode = 'o';
					}
				}
			}
			
			
			array[row][column] = objCode;
		}
		
		/* Error checking */
		
		if( ferror(ptrR) )
		{
			perror(" \n Error!! reading from file ");
		}
		
		
		/* Close the file and Assign the File pointer to NULL */
		
		fclose(ptrR);
		ptrR = NULL;
		
		
		/* pass the address of malloc 2d array to *pArray in the main function */
		
		*pArray = array; 
			
	}
	else
	{
		printf("\n An error or end of file occured \n\n");
	}
	
	
}