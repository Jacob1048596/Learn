#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000
typedef  int ElementType;
typedef struct LNode *List;
struct LNode
{
  ElementType Data[MAXSIZE];
  int Last;
};
struct LNode L;
List PtrL;
List MakeEmpty()
{
  List PtrL;
  PtrL=(List)malloc(sizeof(struct LNode));
  PtrL->Last=-1;
  return PtrL;
}
int Find(ElementType X,List PtrL)
{
  int i=0;
  while (i<PtrL->Last&&PtrL->Data[i]!=X) {
    i++;
  }
  if (i>PtrL->Last) {
    return -1;
  }else return i;
}
void Insert(ElementType X,int i,List PtrL)
{
  int j;
  if (PtrL->Last==MAXSIZE-1) {
    printf("表满\n");
    return;
  }
  if (i<1||i>PtrL->Last+2) {
    printf("插入位置不合法\n");
    return;
  }
  for (j=PtrL->Last;j>=i-1;j--) {
    PtrL->Data[j+1]=PtrL->Data[j];
  }
  PtrL->Data[i-1]=X;
  PtrL->Last++;
  return;
}
void Delete(int i,List PtrL)
{
  int j;
  if (i<1||i>PtrL->Last+1) {
    printf("不存在第%d个元素\n",i);
    return;
  }
  for  (j=i;j<=PtrL->Last;j++) {
    PtrL->Data[j-1]=PtrL->Data[j];
  }
  PtrL->Last--;
  return;
}
