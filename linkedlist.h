#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node
{
  void* data;
  struct Node* next;
  
}Node;


typedef struct 
{
  Node* head;
  Node* tail;
  int count;
  
}LinkedList;

typedef void (*listFunc)(void* data);

LinkedList* createLinkedList();
void insertStart(LinkedList* list, void* entry);
void insertLast(LinkedList* list, void* entry);
void* removeStart(LinkedList* list);
void* removeLast(LinkedList* list);
void printLinkedList(LinkedList* list, listFunc funcPtr);
void freeLinkedList(LinkedList* list, listFunc funcPtr);

#endif