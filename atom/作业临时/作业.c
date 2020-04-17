#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;
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
	// 1.�ա�ֻ��һ���ڵ�
	// 2.���������ϵĽڵ�
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

	// 1.��
	// 2.�ǿ�
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
	// 1.��
	// 2.һ��
	// 3.����������
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
/*
����˼·����������һ������������ʽ + һ�������� ���غ͵�������ʽ��
ģ��ӷ�������λ��ӣ� �ӵ�λ���λ��ӣ�����������ã��õ����ս��
1. ÿһλ��ֵ = ��Ӧλֵ�ĺ� + ǰһλ�Ľ�λ
2. ÿһλ��ֵ�������֮����Ҫ����Ƿ���Ҫ��λ
3. ���λ����֮����Ҫ�����Ƿ���Ҫ���Ͻ�λ
*/
void reverse(int* nums, int begin, int end)
{
  while(begin < end)
  {
    int tmp = nums[begin];
    nums[begin] = nums[end];
    nums[end] = tmp;

    ++begin;
    --end;
  }
}
// ������Ҫ�ر�ע���[9,9,9,7] + 5�ĵ���������Ĵ���
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
  int* addRet = (int*)malloc(10001*sizeof(int));
  //reti: ��iλ�Ľ��
  int reti = 0;
  //�ӵ�λ��ʼ���
  int ai = ASize-1;
  int next = 0; // ��λֵ
  while(ai >= 0 || K > 0)
  {
    int x1 = 0;
    //���aiû��Խ�磬����δ��ӵ�λ��ȡ��һλ����x1
    if(ai >= 0)
    {
      x1 = A[ai];
      --ai;
    }
    int x2 = 0;
    //���k����0����ȡk�ĵ�iλ
    if(K > 0)
    {
      x2 = K%10;
      K /= 10;
    }
    //��iλ�Ľ����ÿһλ��ֵ + ��λ
    int ret = x1+x2+next;
    //����������9����Ҫ��λ
    if(ret > 9)
    {
      ret %= 10;
      next = 1;
    }
    else
    {
      next = 0;
    }
    //�����iλ�Ľ����������
    addRet[reti++] = ret;
  }
  //������λ�н�λ����Ҫ�ڴ���1
  if(next == 1)
  {
    addRet[reti++] = 1;
  }
  //���ý��
  reverse(addRet, 0, reti-1);
  *returnSize = reti;

  return addRet;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    //end1:nums1��ĩβ
    //end2:nums2��ĩβ
    //end:�ϲ�֮�����������ĩβ
     int end1 = m-1;
     int end2 = n-1;
     int end = m+n-1;

    while(end1 >= 0 && end2 >= 0)
    {   //ѡ��β����Ԫ�أ���ŵ����������ĩβ
        //ÿ���һ��Ԫ�أ�β��ǰ�ƶ�һ��λ��
        if(nums1[end1] > nums2[end2])
        {
            nums1[end--] = nums1[end1--];
        }
        else
        {
            nums1[end--] = nums2[end2--];
        }
    }
    //ʣ��Ԫ��������ĩβ���
    while(end1 >= 0)
    {
        nums1[end--] = nums1[end1--];
    }

    while(end2 >= 0)
    {
        nums1[end--] = nums2[end2--];
    }
}
