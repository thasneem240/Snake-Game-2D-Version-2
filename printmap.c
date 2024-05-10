/**************************************************************************
 * File: printmap.c										  		  		  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * Date Created:04/09/2021                            				      *
 * Date Modified: 17/10/2021                              				  *               
 * Purpose: print the 2d char map array				  					  *
 **************************************************************************/
 
 #include <stdio.h>
 #include "printmap.h"
 
void printTheMap( int mapRow, int mapCol, char** array )			    
{
	int i, j;
	
	for( i = 0; i < mapRow; i++ )
	{
		for( j = 0; j < mapCol; j++)
		{
			printf("%c ", array[i][j]);
		}
		printf("\n");
	}
	
}