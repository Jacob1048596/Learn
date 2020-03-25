#include<stdio.h>
#include<stdlib.h>
typedef struct LNode *List;
typedef  int ElementType;
struct LNode
{
  ElementType Data;
  List Next;
};
struct LNode L;
List PtrL;
int Lenth(List PtrL)
{
  List p =PtrL;
  int j =0;
  while (p) {
    p=p->Next;
    j++;
  }
  return j;
}
List Find_id(int k,List PtrL)
{
  List p=PtrL;
  int i=1;
  while (p!=NULL&&i<k) {
    p=p->Next;
    i++;
  }
  if (i==k) {
    return p;
  }
  else return NULL;
}
List Find_data(ElementType X,List PtrL)
{
  List p = PtrL;
  while (p!=NULL&&p->Data!=X) {
    p=p->Next;
  }
  return p;
}
List Insert(ElementType X,int i,List PtrL)
{
  List p,s;
  if (i==1) {
    s=(List)malloc(sizeof(struct LNode));
    s->Data=X;
    s->Next=PtrL;
    return s;
  }
  p=Find_id(i-1,PtrL);
  if (p==NULL) {
    printf("参数i错误\n");
    return NULL;
  }else {
    s=(List)malloc(sizeof(struct LNode));
    s->Data=X;
    s->Next=p->Next;
    p->Next=s;                 //顺序不能乱
    return PtrL;
  }
}
List Delete(int i,List PtrL)
{
  List p,s;
  if (i==1) {
    s=PtrL;
    if (PtrL!=NULL) {
      PtrL=PtrL->Next;
    }else return NULL;
    free(s);
    return PtrL;
  }
  p=Find_id(i-1,PtrL);
  if(p==NULL){
    printf("第%d个节点不存在\n",i-1); return NULL;
  }else if (p->Next==NULL) {
    printf("第%d个节点不存在\n",i); return NULL;
  }else{
    s=p->Next;
    p->Next=s->Next;
    free(s);
    return PtrL;
  }
}
