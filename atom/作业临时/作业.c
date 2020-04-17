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
/*
解题思路：此题是用一个数的数组形式 + 一个整数， 返回和的数组形式。
模拟加法进行逐位相加， 从低位向高位相加，最后整体逆置，得到最终结果
1. 每一位的值 = 对应位值的和 + 前一位的进位
2. 每一位的值计算出来之后，需要检查是否需要进位
3. 最高位计算之后，需要考虑是否还需要向上进位
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
// 本题需要特别注意对[9,9,9,7] + 5的等特殊情况的处理
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){
  int* addRet = (int*)malloc(10001*sizeof(int));
  //reti: 第i位的结果
  int reti = 0;
  //从低位开始相加
  int ai = ASize-1;
  int next = 0; // 进位值
  while(ai >= 0 || K > 0)
  {
    int x1 = 0;
    //如果ai没有越界，还有未相加的位，取出一位存入x1
    if(ai >= 0)
    {
      x1 = A[ai];
      --ai;
    }
    int x2 = 0;
    //如果k大于0，获取k的第i位
    if(K > 0)
    {
      x2 = K%10;
      K /= 10;
    }
    //第i位的结果：每一位的值 + 进位
    int ret = x1+x2+next;
    //如果结果大于9，需要进位
    if(ret > 9)
    {
      ret %= 10;
      next = 1;
    }
    else
    {
      next = 0;
    }
    //存入第i位的结果到数组中
    addRet[reti++] = ret;
  }
  //如果最高位有进位，需要在存入1
  if(next == 1)
  {
    addRet[reti++] = 1;
  }
  //逆置结果
  reverse(addRet, 0, reti-1);
  *returnSize = reti;

  return addRet;
}
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    //end1:nums1的末尾
    //end2:nums2的末尾
    //end:合并之后整个数组的末尾
     int end1 = m-1;
     int end2 = n-1;
     int end = m+n-1;

    while(end1 >= 0 && end2 >= 0)
    {   //选出尾最大的元素，存放到整个数组的末尾
        //每存放一个元素，尾向前移动一个位置
        if(nums1[end1] > nums2[end2])
        {
            nums1[end--] = nums1[end1--];
        }
        else
        {
            nums1[end--] = nums2[end2--];
        }
    }
    //剩余元素依次向末尾存放
    while(end1 >= 0)
    {
        nums1[end--] = nums1[end1--];
    }

    while(end2 >= 0)
    {
        nums1[end--] = nums2[end2--];
    }
}
