#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef struct node
{
  int num;
  struct node *next;
}list,*linklist;
int linklistcreat(linklist &L)
{
  L=(linklist)malloc(sizeof(list));
  if(L==NULL) return 0;
  L->next=NULL;
}
void linkcin(linklist &L,int a)
{
  linklist p,q;
  p=L;
  for(int i=0;i<a;i++){
    q=(linklist)malloc(sizeof(list));
    cin>>q->num;
    p->next=q;
    p=q;
  }
  p->next=NULL;
}
void linkheadcin(linklist &L,int a)
{
  linklist p;
  for(int i=0;i<a;i++){
    p=(linklist)malloc(sizeof(list));
    cin>>p->num;
    p->next=L->next;
    L->next=p;
  }
}
int klistdeltet(linklist &L,int a)
{
  linklist p,q;
  int num=0;
  p=L;
  if(a<0||p->next==NULL) return 0;
  while(p->next!=NULL&&num<a-1){
    p=p->next;
    ++num;
  }
  q=p->next;
  p->next=q->next;
  free(q);
  return 1;
}
int linklist_into(linklist &L,int e,int a,int length)
{
  linklist p,q;
  p=L;
  int num=0;
  if(a<0||a>length||p->next==NULL) return 0;
  while(p->next!=NULL&&num<a-1){
    p=p->next;
    ++num;
  }
  q=new node;
  q->num=e;
  q->next=p->next;
  p->next=q;
}
int linklength(linklist &L)
{
  linklist p;
  int num=0;
  p=L;
  while(p->next!=NULL){
    num++;
  }
  return num;
}
void linkprint(linklist &L)
{
  linklist p;
  p=L->next;
  while(p!=NULL){
    cout<<p->num<<" ";
    p=p->next;
  }
  cout<<endl;
}
void list_link(linklist &L,linklist &T)
{
  linklist p;
  p=L->next;
  while(p->next!=NULL){
    p=p->next;
  }
  p->next=T->next;
}
void destorylinklist(linklist &L)
{
  linklist p,q;
  p=L;
  while(p->next!=NULL){
    q=(linklist)malloc(sizeof(list));
    q=p->next;
    p=q->next;
    delete q;
  }
}
int main()
{
  int a,b;
  cin>>a;
  linklist l,s;
  linklistcreat(l);
  linklistcreat(s);
  linkcin(l,a);
  linkprint(l);
  linkheadcin(s,a);
  linkprint(s);
  list_link(l,s);
  linkprint(l);
  cin>>b;
  klistdeltet(l,b);
  linkprint(l);
  return 0;
}
