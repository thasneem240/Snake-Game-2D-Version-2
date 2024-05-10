/**************************************************************************
 * File: freeLinkedList.c										  		  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * Date Created:01/10/2021                            				      *
 * Date Modified: 17/10/2021                              				  *               
 * Purpose: Free the memory of Game Struct from Linked List	  			  *
 **************************************************************************/
#include <stdlib.h>
#include "input.h"

void freeGameStruct( void* data )
{
	game* coordinate;
	
	coordinate = (game*)data;
	free(coordinate);
}