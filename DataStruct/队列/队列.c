#include <stdio.h>
#include <stdlib.h>
typedef int Type;
typedef struct QNode
{
  Type Data;
  struct QNode* _next;
}Qnode;
typedef struct Queue{
  QNode* _front;
  QNode* _rear;
}Queue;
QNode* CreatNode(Type Data)
{
  QNode* node=(QNode*)malloc(sizeof(QNode));\
  node->Data=Data;
  node->_next=NULL;
  return node;
}
void QueuePush(Queue* q,Type Data)
{
  QNode* node=CreatNode(Data);
  if(q->_front==NULL)
  q->_front=q->_rear=node;
  else{
    q->_rear->_next=node;
    q->_rear=node;
  }
}
void QueuePop(Queue* q)
{
  if(q->_front==NULL) return ;
  QNode* next=q->_front->_next;
  free(q->_front);
  q->_front=next;
  //若删除后为空队则置空
  if(q->_rear==NULL)
    q->_front=NULL;
}
Type QueuFront(Queue* q)
{

}
Type QueuRear(Queue* q)
{

}
int QueueSize(Queue* q)
{
int num=0;
QNode* cur=q->_front;
while (cur) {
  /* code */
  ++num;
  cur=cur->_next;
}return num;
}
int QueueEMpty(Queue* q)
{
  if(q->_front==NULL)
   return 1;
  return 0;
}
int find(Queue* q,Type Data)
{

}
void QueueDestory(Queue* q)
{
  QNode* cur=q->_front;
  while (cur) {
    /* code */
    QNode* next=cur->_next;
    free(cur);
    cur=cur->_next;
  }
    q->_front=NULL;
    q->_rear=NULL;
}


int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
