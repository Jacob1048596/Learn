#include <stdlib.h>
#include <memory.h>

#include "sort.h"
#include "Stack.h"
#include "queue.h"

void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}


/*
	时间复杂度：最坏O(n^2) 平均O(n^2)  最好O(n)
	空间复杂度：O(1)
	稳定性：稳定
	数据敏感：敏感
*/

void insertSort(int* array, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		//新数据插入
		//end: 有序序列的最后一个位置
		int end = i;
		//key: 待插入的数据
		int key = array[end + 1];
		//找到第一个小于等于key的位置
		while (end >= 0 && array[end] > key)
		{
			//当前数据向后移动
			array[end + 1] = array[end];
			--end;
		}
		array[end + 1] = key;
	}
}

/*
时间复杂度：最坏O(n^1.3) 平均O(n^1.3)  最好O(n)
空间复杂度：O(1)
稳定性：不稳定  ---> 分组时相同值的元素不一定可以分到同一组，预排序是可能导致相对位置发生变化
数据敏感：敏感
*/
void shellSort(int* array, int n)
{
	//gap: 步长
	int gap = n;
	//多轮插入排序
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		// gap = gap / 2;
		//一轮插入排序
		for (int i = 0; i < n - gap; ++i)
		{
			//通过步长gap进行逻辑分组
			//组内进行插入排序
			//不同组的元素交替进行排序
			int end = i;
			int key = array[end + gap];
			while (end >= 0 && array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}	
}

/*
时间复杂度：最坏O(n^2) 平均O(n^2)  最好O(n^2)
空间复杂度：O(1)
稳定性：稳定
数据敏感：不敏感
*/
void selectSort(int* array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		//start:未排序数据的最左边
		int start = i;
		//min: 最小值的位置
		int min = start;
		//从未排序的数据中找最小值
		for (int j = start + 1; j < n; ++j)
		{
			if (array[j] < array[min])    //12   19   5  100  20  30     5
				min = j;
		}
		Swap(array, start, min);
	}
}

void selectSort2(int* array, int n)
{
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		//每一次选择最大值和最小值
		int min = begin, max = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (array[i] >= array[max])   //  100  3   5  100  10
				max = i;
			if (array[i] < array[min])
				min = i;
		}
		//最小值放在begin
		Swap(array, begin, min);
		//如果最大值位置发生了变化，需要更新
		if (max == begin)
			max = min;
		//最大值放在end
		Swap(array, end, max);

		/*
		Swap(array, max, end);
		if (min == end)
			min = max;
		Swap(array, min, begin);
		*/
		++begin;
		--end;
	}
}

/*
时间复杂度：最坏O(n^2) 平均O(n^2)  最好O(n)
空间复杂度：O(1)
稳定性：稳定
数据敏感：敏感
*/
void bubbleSort(int* array, int n)
{
	while (n)
	{
		//对于已经有序的序列，通过标签提前结束排序过程
		// flag: 1 ---> 一轮冒泡排序过程中没有发生元素交换
		int flag = 1;
		int end = n;
		//一轮冒泡排序
		//for (int i = 0; i < end - 1; ++i)
		for (int i = 1; i < end; ++i)
		{
			//相邻元素进行比较, 大的向后移动
			//if (array[i] > array[i + 1])
			if (array[i - 1] > array[i])
			{
				Swap(array, i, i - 1);
				flag = 0;
			}
		}
		//没有发生元素交换，数据已经有序
		if (flag)
			break;
		--n;
	}
}

/*
时间复杂度：O(nlogn)
空间复杂度：O(1)
稳定性：不稳定  --> 调整的过程中相对位置可能会发生变化
数据敏感：不敏感
*/
//大堆的调整
void shiftDown(int* array, int n, int parent)
{
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n && array[child + 1] > array[child])
			++child;
		if (array[child] > array[parent])
		{
			Swap(array, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
void heapSort(int* array, int n)
{
	//建堆
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		shiftDown(array, n, i);
	}
	//循环删除
	while (n)
	{
		Swap(array, 0, n - 1);
		--n;
		shiftDown(array, n, 0);
	}
}

//三数取中
int getMid(int* array, int begin, int end)
{
	int mid = begin + (end - begin) / 2;
	// begin, mid, end选择中间值的位置
	if (array[begin] < array[mid])
	{
		// begin <  mid;
		if (array[mid] < array[end])
			return mid;
		else{
			// begin < mid,  end <= mid
			if (array[begin] > array[end])
				return begin;
			else
				return end;
		}
	}
	else
	{
		// begin >= mid;
		if (array[mid] > array[end])
			return mid;
		else
		{
			//begin >= mid, end >= mid
			if (array[begin] < array[end])
				return begin;
			else
				return end;
		}
	}
}


//hora划分
int partion(int* array, int begin, int end)
{
	//三数取中
	int mid = getMid(array, begin, end);
	//交换 mid -- begin
	Swap(array, begin, mid);

	//选择基准值
	int key = array[begin];
	int start = begin;
	//划分
	while (begin < end)
	{
		
		//从后往前找第一个小于key的位置
		while (begin < end && array[end] >= key)
			--end;

		//从前向后找第一个大于key的位置
		while (begin < end && array[begin] <= key)
			++begin;
		
		//交换 end, begin
		Swap(array, begin, end);
	}

	//key和相遇位置的数据交换
	Swap(array, start, begin);
	//返回基准值的位置
	return begin;
}

//第二种划分方法： 挖坑法
int partion2(int* array, int begin, int end)
{
	//三数取中
	int mid = getMid(array, begin, end);
	//交换 mid -- begin
	Swap(array, begin, mid);

	int key = array[begin];
	while (begin < end)
	{
		//从后向前找
		while (begin < end && array[end] >= key)
			--end;
		//填坑: begin
		array[begin] = array[end];
		//从前向后找
		while (begin < end && array[begin] <= key)
			++begin;
		//填坑：end
		array[end] = array[begin];
	}
	//最后一个坑： 相遇的位置  --> 填充基准值
	array[begin] = key;
	//返回基准值的位置
	return begin;
}

//前后指针法
int partion3(int* array, int begin, int end)
{
	//三数取中
	int mid = getMid(array, begin, end);
	//交换 mid -- begin
	Swap(array, begin, mid);

	//prev: 最后一个小于基准值的位置
	int prev = begin;
	//cur：新发现的下一个小于基准值的位置
	int cur = prev + 1;
	int key = array[begin];
	while (cur <= end)
	{
		//新发现的小数据和尾指针指向的位置不连续，则中间含有大于基准值的数据，故进行交换
		//大数据向后移动，小数据向前移动
		if (array[cur] < key && ++prev != cur)
			Swap(array, prev, cur);
		++cur;
	}
	Swap(array, begin, prev);
	return prev;
}

/*
时间复杂度：最坏：O(n^2)-->不会出现   最好:O(nlogn)  平均：O(nlogn)
空间复杂度：O(logn)  函数调用栈，  极端情况: O(n)-->不会出现
稳定性：不稳定
数据敏感：敏感
*/
void quickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;
	//划分当前区间
	//int keyPos = partion(array, begin, end);
	//int keyPos = partion2(array, begin, end);
	int keyPos = partion3(array, begin, end);
	//划分子区间
	quickSort(array, begin, keyPos - 1);
	quickSort(array, keyPos + 1, end);
}

//栈实现非递归: 保存待划分的区间
void quickSortNoR(int* array, int n)
{
	Stack st;
	stackInit(&st, 10);
	//起始区间入栈: 先右后左
	if (n > 1)
	{
		stackPush(&st, n - 1);
		stackPush(&st, 0);
	}
	//遍历栈，划分栈中的每一个区间
	while (stackEmpty(&st) != 1)
	{
		//获取栈顶区间
		int begin = stackTop(&st);
		stackPop(&st);
		int end = stackTop(&st);
		stackPop(&st);
		//划分
		int keyPos = partion3(array, begin, end);
		//子区间入栈： 先入右区间
		// 右： keyPos + 1, end
		if (keyPos + 1 < end)
		{
			stackPush(&st, end);
			stackPush(&st, keyPos + 1);
		}
		//左： begin ,  keyPos - 1
		if (begin < keyPos - 1)
		{
			stackPush(&st, keyPos - 1);
			stackPush(&st, begin);
		}
	}
}

//队列非递归: 保存待划分的区间
void quickSortNoR2(int* array, int n)
{
	Queue q;
	queueInit(&q);

	if (n > 1)
	{
		//先左后右
		queuePush(&q, 0);
		queuePush(&q, n - 1);
	}
	while (queueEmpty(&q) != 1)
	{
		//获取队头区间
		int begin = queueFront(&q);
		queuePop(&q);
		int end = queueFront(&q);
		queuePop(&q);
		//划分
		int keyPos = partion3(array, begin, end);
		//子区间入队
		if (begin < keyPos - 1)
		{
			queuePush(&q, begin);
			queuePush(&q, keyPos - 1);
		}
		if (keyPos + 1 < end)
		{
			queuePush(&q, keyPos + 1);
			queuePush(&q, end);
		}
	}
}


//合并： 需要知道两个有序子序列的区间: [begin, mid]  [mid + 1, end]
void merge(int* array, int begin, int mid, int end, int* tmp)
{
	int begin1 = begin, end1 = mid, begin2 = mid + 1, end2 = end;
	int idx = begin;
	//合并
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (array[begin1] <= array[begin2])
			tmp[idx++] = array[begin1++];
		else
			tmp[idx++] = array[begin2++];
	}
	//查看是否有剩余元素
	if (begin1 <= end1)
		memcpy(tmp + idx, array + begin1, sizeof(int)* (end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, array + begin2, sizeof(int)* (end2 - begin2 + 1));
	//拷贝到原始空间
	memcpy(array + begin, tmp + begin, sizeof(int)* (end - begin + 1));
}

void mergeSortR(int* array, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;

	//首先保证子区间有序，首先子区间的排序
	mergeSortR(array, begin, mid, tmp);
	mergeSortR(array, mid + 1, end, tmp);

	//合并有序子区间
	merge(array, begin, mid, end, tmp);
}

/*
时间复杂度：O(nlogn)
空间复杂度：O(n)
稳定：稳定
数据敏感：不敏感
*/
void mergeSort(int* array, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	mergeSortR(array, 0, n - 1, tmp);
	free(tmp);
}

void mergeSortNoR(int* array, int n)
{
	int* tmp = (int*)malloc(sizeof(int)* n);
	//待合并区间的元素个数
	int k = 1;
	//多轮的归并
	while (k < n)
	{
		//一轮归并
		for (int i = 0; i < n; i += 2 * k)
		{
			//[begin, mid]  [mid + 1, end]
			int begin = i;

			int mid = i + k - 1;
			//判断mid是否越界
			if (mid >= n - 1)
				continue;

			int end = i + 2 * k - 1;
			//判断end是否越界
			if (end >= n)
				end = n - 1;
			merge(array, begin, mid, end, tmp);
		}
		k *= 2;
	}
	
	
}
/*
时间复杂度：O(max(n,范围))
空间复杂度：O(范围)
稳定：一般教材认为是稳定的(欠妥)
数据敏感：不敏感
计数排序： 只适合小范围数据， 如果范围大，空间复杂度较高
*/
void countSort(int* array, int n)
{
	// 1, 2, 3,   1000000
	//统计范围
	int min = array[0], max = array[0];
	for (int i = 1; i < n; ++i)
	{
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}
	int range = max - min + 1;
	//开辅助空间，进行计数
	int* countArr = (int*)malloc(sizeof(int)* range);
	//初始化为0
	memset(countArr, 0, sizeof(int)* range);
	//统计次数
	for (int i = 0; i < n; ++i)
	{
		countArr[array[i] - min]++;
	}
	//恢复数据， 遍历计数数组
	int idx = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArr[i]--)
		{
			array[idx++] = i + min;
		}
	}

	free(countArr);
}