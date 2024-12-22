#ifndef LINKED_LIST
#define LINKED_LIST

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


linkedList_t InitLinkedList(float value);
void CleanupLinkedList(linkedList_t* list);

float Get(linkedList_t* list, int index);

void Append(linkedList_t* list, float value);
void Insert(linkedList_t* list, int index, float value);

int Delete(linkedList_t* list, float value);
float Pop(linkedList_t* list);

void Sort(linkedList_t* list);

#endif
