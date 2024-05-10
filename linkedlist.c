/**************************************************************************
 * File: linkedlist.c										  		  	  *
 * Author: Mr.A.S.M. Thasneem                          				      *
 * Date Created:03/10/2021                            				      *
 * Date Modified: 17/10/2021                              				  *               
 * Purpose: Implement a Generic Linked List				  				  *
 **************************************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


/* Create an Empty Linked List */

LinkedList* createLinkedList()
{
	LinkedList* list;
	
	list = (LinkedList*) malloc( sizeof(LinkedList) );
	(*list).head = NULL;
	(*list).tail = NULL;
	(*list).count = 0;
	
	return list;
}


/* Insert an element at the start */

void insertStart(LinkedList* list, void* entry)
{
	Node* newNode;
	
	newNode = (Node*)malloc( sizeof(Node) );
	(*newNode).data = entry;
	
	/* When the list is empty (*newNode).next will be NULL */
	
	(*newNode).next = (*list).head; 
	(*list).head = newNode;
	
	if( (*list).count == 0 )
	{
		/* When the list is empty head and tail are the first node */
		
		(*list).tail = newNode; 
	}
	
	/* Increase the count */
	
	(*list).count = (*list).count + 1; 
}


void insertLast(LinkedList* list, void* entry)
{
	Node* newNode;
	
	newNode = (Node*)malloc( sizeof(Node) );
	(*newNode).data = entry;
	(*newNode).next = NULL;
	
	if( (*list).count == 0 )
	{
		/* When the list is empty head and tail are the first node */
		
		(*list).head = newNode; 
		(*list).tail = newNode;
	}
	else
	{
		list->tail->next = newNode;
		(*list).tail = newNode;
	}
	
	/* Increase the count */
	
	(*list).count = (*list).count + 1;
	
}


void* removeStart(LinkedList* list)
{
	Node* temp;
	void* value;
	
	/* Return null if the list is empty */
	
	if( (*list).count == 0 )
	{
		value = NULL;
	}
	else
	{
		temp = (*list).head;
		value = (*temp).data;
		
		/* If next node is not exist it is NULL */
		
		(*list).head = list->head->next; 

		free(temp); /* free the first node */
		
		if( (*list).head == NULL)
		{
			/* special case ( one item list since it is both the first and last node ) */
			
			(*list).tail = NULL;
		}
		
		/* Decrease the count */
		
		(*list).count = (*list).count - 1; 
	}
	
	return value;
	
}


void* removeLast(LinkedList* list)
{
	Node* current;
	Node* previous;
	void* value;
	
	/* Return null if the list is empty */
	
	if( (*list).count == 0 )
	{
		value = NULL;
	}
	else
	{
		current = (*list).head;
		previous = NULL;
		
		while( (*current).next != NULL )
		{
			previous = current;
			current = (*current).next;
		}
		
		value = list->tail->data;
		
		/* If the linked list have only one node */
		
		if( previous == NULL ) 
		{
			(*list).head = NULL;
			(*list).tail = NULL;
		}
		else
		{
			(*previous).next = NULL;
			(*list).tail = previous; 
		}
		
		free(current); /* free the first node */
		
		/* Decrease the count */
		
		(*list).count = (*list).count - 1;	
	}
	
	return value;
}


void printLinkedList(LinkedList* list, listFunc funcPtr)
{
	Node* current;
	void* data;
	
	current = (*list).head;
	
	/* Traverse the linked list from first node to last node */
	
	while(current != NULL )
	{
		data = (*current).data;
		
		/* dereference and pass the void pointer */
		
		(*funcPtr)(data); 
		current = (*current).next;
	}
}


void freeLinkedList(LinkedList* list, listFunc funcPtr)
{
	Node* current;
	Node* nextNode;
	void* data;
	
	current = (*list).head;
	
	/* Traverse the linked list from first node to last node */
	
	while(current != NULL )
	{
		nextNode = (*current).next;
		data = (*current).data;
		
		/* free the data via function pointer */
		
		(*funcPtr)(data); 
		
		/* free the current node */
		
		free(current);
		
		current = nextNode;
	}
	
	/* free the LinkedList */
	
	free(list);
}