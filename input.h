#ifndef INPUT_H
#define INPUT_H

#include "linkedlist.h"

void getInput( int* rowOfPlayer, int* colOfPlayer, char* playerCh, int rowOfGoal, 
		int colOfGoal, int* rowOfEnemy, int* colOfEnemy, char** array, LinkedList** list );
		
		
typedef struct
{
	int rowOfPlayer;
	int colOfPlayer;
	int rowOfEnemy;
	int colOfEnemy;
	char playerCh;
	
}game;
		
#endif