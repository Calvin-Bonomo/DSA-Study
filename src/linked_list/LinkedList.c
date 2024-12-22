#include "LinkedList.h"

/*
  Initializes a linked list with `value`.
*/
void Init(linkedList_t* list, float value) 
{
  list->begin = malloc(sizeof(llnode_t));
  list->begin->data = value;
  list->begin->next = 0;
  list->end = list->begin;
  list->size = 1;
}

/*
  Frees the linked list from memory. Does not free the `list` pointer!
*/
void Free(linkedList_t* list) 
{
  llnode_t *current = list->begin;
  llnode_t *temp;
  while (current != 0)
  {
    temp = current->next;
    free(current);
    current = temp;
  };
  list->begin = 0;
  list->end = 0;
  list->size = 0;
}

/*
  Gets the value at `index` from `list`.
*/
float Get(linkedList_t* list, unsigned int index) 
{
  assert(index < list->size);

  llnode_t* current = list->begin;
  while (index != 0) 
  {
    current = current->next;
    index--;
  }
  return current->data;
}

/*
  Sets the node in `list` at `index` to `value`.
*/
void Set(linkedList_t* list, float value, unsigned int index) 
{
  assert(index < list->size);

  llnode_t* current = list->begin;
  while (index != 0) 
  {
    current = current->next;
    index--;
  }
  current->data = value;
}

/*
  Appends `value` to the end of `list`.
*/
void Append(linkedList_t* list, float value) 
{
  llnode_t* newNode = malloc(sizeof(llnode_t));
  newNode->next = 0;
  newNode->data = value;
  list->end->next = newNode;
  list->end = newNode;
  list->size++;
}

/*
  Inserts `value` at `index` by creating a new node.
*/
void Insert(linkedList_t* list, float value, unsigned int index) 
{
  assert(index < list->size);

  llnode_t* newNode = malloc(sizeof(llnode_t));
  newNode->data = value;

  llnode_t* current = list->begin, * last = 0;
  while (index > 0) 
  {
    last = current;
    current = current->next;
  }

  // Insert node into list
  newNode->next = current;
  list->size++;

  if (last == 0)
    list->begin = newNode;
  else
    last->next = newNode;
}

/*
  Deletes the first occurrence of `value` in the linked list. Returns 0 if 
  unable to find `value`.
*/
int Delete(linkedList_t* list, float value) 
{
  llnode_t* current = list->begin, * last = 0;

  while (current != 0) 
  {
    if (current->data == value)
      break;
    last = current;
    current = current->next;
  }

  if (current == 0)
    return 0;
  
  llnode_t* next = current->next;

  if (current == list->begin) // If deleting the head of the list
    list->begin = next;
  else if (current == list->end) // If deleting the tail of the list
    list->end = last;
  else // Deleting some middle element
    last->next = next;
  
  list->size--;
  free(current);

  return 1;
}

float Pop(linkedList_t* list) 
{
  
}

void Sort(linkedList_t* list) 
{

}
