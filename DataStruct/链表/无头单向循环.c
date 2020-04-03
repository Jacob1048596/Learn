#include<stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDateType;
typedef struct SListNode
{
  struct SListNode* next;
  SLTDateType data;
}SListNode;
typedef struct SingleList
{
  SListNode* Head;
}SingleList;
void SingleListInit(SingleList* s1);
void SingleListPushBack(SingleList*s1,SLTDateType data);
void SingleListPopBack(SingleList* s1);
void SingleListPushFront(SingleList*s1,SLTDateType data);
void SingleListPopFront(SingleList* s1);
void SingleListInsertAfter(SListNode* pos,SLTDateType data);
void SingleListPopFront(SListNode* pos);
SListNode* Find(SLTDateType data);
void SingleListPrint(SingleList* s1);
void SingleListDestory(SingleList* s1);
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur)
	//while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

void SListPopBack(SListNode** pplist)
{
	SListNode* prev = NULL;
	SListNode* tail = *pplist;
	// 1.空、只有一个节点
	// 2.两个及以上的节点
	if (tail == NULL || tail->next == NULL)
	{
		free(tail);
		*pplist = NULL;
	}
	else
	{
		while (tail->next)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		tail = NULL;

		prev->next = NULL;
	}
}


void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);

	// 1.空
	// 2.非空
	SListNode* newnode = BuySListNode(x);
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}
}

void SListPopFront(SListNode** pplist)
{
	// 1.空
	// 2.一个
	// 3.两个及以上
	SListNode* first = *pplist;
	if (first == NULL)
	{
		return;
	}
	else if (first->next == NULL)
	{
		free(first);
		*pplist = NULL;
	}
	else
	{
		SListNode* next = first->next;
		free(first);
		*pplist = next;
	}
}

SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
			return cur;

		cur = cur->next;
	}

	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);
	SListNode* next = pos->next;
	// pos newnode next
	SListNode* newnode = BuySListNode(x);
	pos->next = newnode;
	newnode->next = next;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	// pos next nextnext
	SListNode* next = pos->next;

	if (next != NULL)
	{
		SListNode* nextnext = next->next;
		free(next);
		pos->next = nextnext;
	}
}
