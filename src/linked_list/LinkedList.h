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

<<<<<<< HEAD
float Get(linkedList_t* list, unsigned int index);
void Set(linkedList_t* list, float value, unsigned int index);
=======
float Get(linkedList_t* list, int index);
void Set(linkedList_t* list, int index, float value);
>>>>>>> b706390 (Added prototype for Set function)

void Append(linkedList_t* list, float value);
void Insert(linkedList_t* list, float value, unsigned int index);

int Delete(linkedList_t* list, float value);
float Pop(linkedList_t* list);

void Sort(linkedList_t* list);

#endif
