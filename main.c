/**************************************************************************
 * File: main.c										  		  			  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * Date Created:03/10/2021                            				      *
 * Date Modified: 17/10/2021                              				  *               
 * Purpose: Implement a simple maze game				  				  *
 **************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include "setmap.h"
#include "printmap.h"
#include "input.h"
#include "linkedlist.h"
#include "freeLinkedList.h"

int main( int argc, char* argv[] )
{
	int i, mapRow, mapCol;
	char** array = NULL;
	int rowOfPlayer, colOfPlayer; /* Current row and column of player */ 
	int rowOfGoal, colOfGoal; /* Current row and column of Goal */ 
	char playerCh = '^';
	int rowOfEnemy, colOfEnemy; /* Current row and column of Enemy */ 
	FILE* ptrR;
	LinkedList* list;
	
	
	if( argc != 2 )
	{
		printf( "\n Error!! Please input one command line parameter" 
		        " ------> %s <map_file_name> \n\n", argv[0] );
	}
	else
	{
		/* Open the File to read Metadata */
		
		ptrR = fopen(argv[1], "r");
		
		if( ptrR == NULL )
		{
			perror("\n Error!! opening the File ");
		}
		else
		{
			list = createLinkedList(); /* Create a Generic Linked list */
			
			setTheMap(  &mapRow, &mapCol, &array, &rowOfPlayer, &colOfPlayer,
						&rowOfGoal, &colOfGoal, &rowOfEnemy, &colOfEnemy, ptrR  );
			
			/* clear the terminal */
			
			system("clear"); 
			
			printTheMap(  mapRow, mapCol, array );
			
			/* get input from user until player reach the Goal */
			
			do
			{
				getInput(  &rowOfPlayer, &colOfPlayer, &playerCh, rowOfGoal,
					       colOfGoal, &rowOfEnemy, &colOfEnemy, array, &list  );
				system("clear"); 
				printTheMap(  mapRow, mapCol, array );
				
				/* When player reach the Goal position 
				   print a celebratory message */
				
				if( (rowOfPlayer == rowOfGoal) && (colOfPlayer == colOfGoal) )
				{
					printf("\n You Win! \n\n");
				}
				else
				{
					if( (rowOfPlayer == rowOfEnemy) && (colOfPlayer == colOfEnemy) )
					{
						printf("\n You lose, try again. \n\n");
					}
				}
				
				
			}while( !( ( (rowOfPlayer == rowOfGoal) && (colOfPlayer == colOfGoal) ) 
				|| ( (rowOfPlayer == rowOfEnemy) && (colOfPlayer == colOfEnemy) ) ) );
			
			
			/* free malloc 2d Array from heap memory */
	
			for( i = 0 ; i < mapRow ; i++)
			{
				free( array[i] );
			}
			
			free( array );
			
			/* Assign the pointer to NULL */
			
			array = NULL; 
			
			/* Free the data(Struct) and LinkedList by passing Function pointer */
			
			freeLinkedList(list, &freeGameStruct);
		}
	}
	
	return 0;
}
