// #include<stdio.h>
// #include<stdlib.h>
// #define MAXSIZE 1000
// typedef  int ElementType;
// typedef struct LNode *List;
// struct LNode
// {
//   ElementType Data[MAXSIZE];
//   int Last;
//   int capycity;
// };

// struct LNode L;
// List PtrL;
// List MakeEmpty()
// {
//   List PtrL;
//   PtrL=(List)malloc(sizeof(struct LNode));
//   PtrL->Last=-1;
//   return PtrL;
// }
// int Find(ElementType X,List PtrL)
// {
//   int i=0;
//   while (i<PtrL->Last&&PtrL->Data[i]!=X) {
//     i++;
//   }
//   if (i>PtrL->Last) {
//     return -1;
//   }else return i;
// }
// void Insert(ElementType X,int i,List PtrL)
// {
//   int j;
//   if (PtrL->Last==MAXSIZE-1) {
//     printf("����\n");
//     return;
//   }
//   if (i<1||i>PtrL->Last+2) {
//     printf("����λ�ò��Ϸ�\n");
//     return;
//   }
//   for (j=PtrL->Last;j>=i-1;j--) {
//     PtrL->Data[j+1]=PtrL->Data[j];
//   }
//   PtrL->Data[i-1]=X;
//   PtrL->Last++;
//   return;
// }
// void Delete(int i,List PtrL)
// {
//   int j;
//   if (i<1||i>PtrL->Last+1) {
//     printf("�����ڵ�%d��Ԫ��\n",i);
//     return;
//   }
//   for  (j=i;j<=PtrL->Last;j++) {
//     PtrL->Data[j-1]=PtrL->Data[j];
//   }
//   PtrL->Last--;
//   return;
// }
// int main(int argc, char const *argv[]) {
//   List p=MakeEmpty();
//   Insert(5,3,p);
//   return 0;
// }
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;

// �����ݵĹ���:��ɾ���
void SeqListInit(SeqList* ps)
{
  assert(ps);
  ps->a=NULL;
  ps->size=0;
  ps->capacity=0;
}
void SeqListDestory(SeqList* ps);

void SeqListPrint(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDateType x);
void SeqListPushFront(SeqList* ps, SLDateType x);
void SeqListPopFront(SeqList* ps);
void SeqListPopBack(SeqList* ps);

// ˳������
int SeqListFind(SeqList* ps, SLDateType x);
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos);
void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);

	for (size_t i = 0; i < ps->size; ++i)
	{
		printf("%d ", ps->a[i]);
	}

	printf("%\n");
}

void CheckCacpity(SeqList* ps)
{
	if (ps->size == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		ps->a = (SLDateType*)realloc(ps->a, newcapacity*sizeof(SLDateType));
		ps->capacity = newcapacity;
	}
}

// ���¼����ӿ��Ƚ�������Insert��Erase��ʵ�֣�����ٽ�����ʵ��
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	//assert(ps);
	//CheckCacpity(ps);

	//ps->a[ps->size] = x;
	//ps->size++;

	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);

	/*CheckCacpity(ps);

	size_t end = ps->size;
	while (end > 0)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}

	ps->a[0] = x;
	++ps->size;*/

	SeqListInsert(ps, 0, x);
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);

	//size_t start = 0;
	//while (start < ps->size-1)
	//{
	//	ps->a[start] = ps->a[start + 1];
	//	++start;
	//}
	//size_t start = 1;
	//while (start < ps->size)
	//{
	//	ps->a[start-1] = ps->a[start];
	//	++start;
	//}

	//--ps->size;
	SeqListErase(ps, 0);
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);

	//ps->a[ps->size - 1] = 0;
	//ps->size--;
	SeqListErase(ps, ps->size-1);
}

int SeqListFind(SeqList* ps, SLDateType x)
{
	for (size_t i = 0; i < ps->size; ++i)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}

	return -1;
}

// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
	assert(ps);
	assert(pos <= ps->size);

	CheckCacpity(ps);

	//int end = ps->size - 1;
	//while (end >= (int)pos)
	//{
	//	ps->a[end + 1] = ps->a[end];
	//	--end;
	//}

	size_t end = ps->size ;
	while (end > pos)
	{
		ps->a[end] = ps->a[end - 1];
		--end;
	}


	ps->a[pos] = x;
	ps->size++;
}

// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps && pos < ps->size);

	//size_t start = pos;
	//while (start < ps->size-1)
	//{
	//	ps->a[start] = ps->a[start + 1];
	//	++start;
	//}

	size_t start = pos+1;
	while (start < ps->size)
	{
		ps->a[start-1] = ps->a[start];
		++start;
	}

	ps->size--;
}
int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
