#ifndef LINKED_LIST
#define LINKED_LIST

#include "assert.h"

typedef struct LinkedList 
{
  llnode_t* begin;
  llnode_t* end;
  unsigned int size;
} linkedList_t;

typedef struct LinkedListNode
{
  float data;
  llnode_t* next;
} llnode_t;

void Init(linkedList_t* list, float value);

void Free(linkedList_t* list);
llnode_t llFreeHelper(llnode_t* root);

float Get(linkedList_t* list, unsigned int index);
void Set(linkedList_t* list, float value, unsigned int index);

void Append(linkedList_t* list, float value);
void Insert(linkedList_t* list, float value, unsigned int index);

int Delete(linkedList_t* list, float value);
float Pop(linkedList_t* list);

void Sort(linkedList_t* list);


#endif
