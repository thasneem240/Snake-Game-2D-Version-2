/**************************************************************************
 * File: input.c										  		  		  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * Date Created:04/09/2021                            				      *
 * Date Modified: 17/10/2021                              				  *               
 * Purpose: Get input from user without pressing "enter key" everytime.	  *
 **************************************************************************/
 #include <stdio.h>
 #include <stdlib.h>
 #include "input.h"
 #include "terminal.h"
 #include "setSnake.h"
 
void getInput( int* rowOfPlayer, int* colOfPlayer, char* playerCh, int rowOfGoal, 
		int colOfGoal, int* rowOfEnemy, int* colOfEnemy, char** array, LinkedList** list )
{
	/* variable Declarations */
	
	char ch;
	char enemyCh = '~';
	char space = ' ';
	game* coordinate; /* Struct pointer */
	void* data;
	
	
	do
	{
		/* disable the terminal buffer temporarily */
		
		disableBuffer(); 
		
		/* get the input from user */
		
		scanf(" %c", &ch); 
		
		/* enable the terminal buffer */
		
		enableBuffer(); 
		
		
		/* Save the location of snake and player When player moves */
		
		if( ch == 'w' || ch == 's' || ch == 'a' || ch == 'd' )
		{
			/* Create a New game struct */
			
			coordinate = (game*)malloc( sizeof(game) ); 
			
			/* Save Current information to coordinate struct */
			
			coordinate->rowOfPlayer = *rowOfPlayer;
			coordinate->colOfPlayer = *colOfPlayer;
			coordinate->rowOfEnemy = *rowOfEnemy;
			coordinate->colOfEnemy = *colOfEnemy;
			coordinate->playerCh = *playerCh;
			
			data = (void*)coordinate; /* Typecast coordinate into void pointer */
			
			insertStart(*list, data); /* Add the details into linkedList */
			
		}
		
		
		
		if( ch == 'w')
		{
			*playerCh = '^';
			
			/* moves the player one block above, 
			   ONLY if there is an empty space or Goal */
			
			if(  ( array[*(rowOfPlayer)-1][*colOfPlayer] == space )
				|| ( array[*(rowOfPlayer)-1][*colOfPlayer] == 'x' )
				|| ( array[*(rowOfPlayer)-1][*colOfPlayer] == '~' ) )
			{
				/* Assign space to current position of the player */
				
				array[*rowOfPlayer][*colOfPlayer] = space; 
				
				/* change the player row */
				
				*rowOfPlayer = *(rowOfPlayer)-1; 
			}
			
		}
		else
		{
			if( ch == 's')
			{
				*playerCh = 'v';
				
				/* moves the player one block below, 
				   ONLY if there is an empty space or Goal */
				
				if(  ( array[*(rowOfPlayer)+1][*colOfPlayer] == space )
					|| ( array[*(rowOfPlayer)+1][*colOfPlayer] == 'x' )
					|| ( array[*(rowOfPlayer)+1][*colOfPlayer] == '~' ) )
				{
					array[*rowOfPlayer][*colOfPlayer] = space; 
					*rowOfPlayer = *(rowOfPlayer)+1; 
				}
				
			}
			else
			{
				if( ch == 'a')
				{
					*playerCh = '<';
					
					/* moves the player one block left,
					   ONLY if there is an empty space or Goal */
					
					if(  ( array[*rowOfPlayer][*(colOfPlayer)-1] == space )
						|| ( array[*rowOfPlayer][*(colOfPlayer)-1] == 'x' )
						|| ( array[*rowOfPlayer][*(colOfPlayer)-1] == '~' ) )
					{
						array[*rowOfPlayer][*colOfPlayer] = space; 
						
						/* change the player column */
						
						*colOfPlayer = *(colOfPlayer)-1;
					}
					
				}
				else
				{
					if( ch == 'd')
					{
						*playerCh = '>';
						
						/* moves the player one block right,
						   ONLY if there is an empty space or Goal */
						
						if(  ( array[*rowOfPlayer][*(colOfPlayer)+1] == space ) 
						  || ( array[*rowOfPlayer][*(colOfPlayer)+1] == 'x' )
						  || ( array[*rowOfPlayer][*(colOfPlayer)+1] == '~' ) )
						{
							array[*rowOfPlayer][*colOfPlayer] = space; 
							*colOfPlayer = *(colOfPlayer)+1;
						}
						
					}
					else
					{
						if( ch == 'u')
						{
							/* When linked list is not empty Do the Undo Operation */
							
							if( (*list)->count != 0 )
							{
								array[*rowOfPlayer][*colOfPlayer] = space;
								array[*rowOfEnemy][*colOfEnemy] = space;
								
								/* Remove the first node in the LinkedList and get the data */
								
								data = removeStart(*list); 
								
								/* typecast void pointer to proper type */
								
								coordinate = (game*)data; 
								
								/* Update the Map using this details */
								
								*rowOfPlayer = coordinate->rowOfPlayer;
								*colOfPlayer = coordinate->colOfPlayer;
								*rowOfEnemy = coordinate->rowOfEnemy;
								*colOfEnemy = coordinate->colOfEnemy;
								*playerCh = coordinate->playerCh;
								
								/* free the malloc coordinate Struct from heap memory */
								
								free(coordinate); 
									
							}
							
						}
						else
						{
							/* Output the warning message */
						
							printf("\n Please input w,s,a,d or u to"
						       " control this game!!\n" );
						}
						
					}
					
				}
				
			}
			
		}
		
		
	
	/* Chase the player when player moves */
	
	if( ch == 'w' || ch == 's' || ch == 'a' || ch == 'd' )
	{
		/* Calling setSnakeLocation Method */
		
		setSnakeLocation( rowOfPlayer, colOfPlayer, playerCh, 
							rowOfEnemy, colOfEnemy, array);
	}	
		
		
	/* Assign playerCh to current position of the player */
		
	array[*rowOfPlayer][*colOfPlayer] = *playerCh;
	
	/* Assign enemy position */
		
	array[*rowOfEnemy][*colOfEnemy] = enemyCh; 
		
		
		
	/* loop until get the correct input */
	
	}while( !(ch == 'w' || ch == 's' || ch == 'a' || ch == 'd' || ch == 'u') ); 
	
	
}