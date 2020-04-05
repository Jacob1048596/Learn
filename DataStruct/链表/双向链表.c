#include <stdio.h>
#include <stdlib.h>
typedef int Type;
typedef struct Node
{
  Type Data;
  struct Node* Next;
  struct Node* Prev;
}Node;
typedef struct ListNode{
  Node* head;
}ListNode;
void PrintList(ListNode* list)
{
  Node* cur=list->head->Next;
  while(cur!=list->head)
  {
    printf("%d ",cur->Data);
    cur=cur->Next;
  }
}
Node* creatNode(Type data)
{
  Node* node=(Node*)malloc(sizeof(Node));
  node->Prev=node->Next=NULL;
  node->Data=data;
  return node;
}
void ListInit(ListNode* list)
{
  list->head=creatNode(0);
  list->head->Next=list->head;
  list->head=list->head;
}
void ListPushBack(ListNode* list,Type data)
{
  Node* node=creatNode(data);
  Node* last=list->head->Prev;
    last->Next=node;
    node->Prev=last;
  node->Next=list->head;
  list->head->Prev=node;
}
void ListPopBack(ListNode* list)
{
  if(list->head->Next==list->head)
  return;
  Node* last=list->head->Prev;
  Node* prev=last->Prev;
  prev->Next=list->head;
  list->head->Prev=prev;
  free(last);
}
void ListPushFornt(ListNode* list,Type data)
{
  Node* front=list->head->Next;
  Node* node=creatNode(data);
  node->Prev=list->head;
  list->head->Next=node;
  node->Next=front;
  front->Prev=node;
}
void ListPopFront(ListNode* list)
{
  Node* front,*next;
  if(list->head->Next==list->head)
  return;
  front=list->head->Next;
  next=front->Next;
  free(front);
  list->head->Next=next;
  next->Prev=list->head;
}
void ListInsert(Node* pos,Type data)
{
  Node* prev=pos->Prev;
  Node* node=creatNode(data);
  prev->Next=node;
  node->Prev=prev;
  node->Next=pos;
  pos->Prev=node;
}
void listErase(Node* pos)
{
  Node* prev,*next;
  if(pos->Prev==pos)
  return;
  prev=pos->Prev;
  next=pos->Next;
  free(pos);
  prev->Next=next;
  next->Prev=prev;
}
void ListDestory(ListNode* list)
{
  Node* cur=list->head->Next;
  while(cur!=list->head)
  {
    Node* next =cur->Next;
    free(cur);
    cur=cur->Next;
  }
  free(list->head);
}
