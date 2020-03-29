#include<stdio.h>

typedef int Type;
typedef struct Node
{
  struct Node* Next;
  Type Data;
}Node;
typedef struct SingleList
{
  Node* Head;
}SingleList;
void SingleListInit(SingleList* s1);
void SingleListPushBack(SingleList*s1,Type data);
void SingleListPopBack(SingleList* s1);
void SingleListPushFront(SingleList*s1,Type data);
void SingleListPopFront(SingleList* s1);
void SingleListInsertAfter(Node* pos,Type data);
void SingleListPopFront(Node* pos);
Node* Find(Type data);
void SingleListPrint(SingleList* s1);
void SingleListDestory(SingleList* s1);
