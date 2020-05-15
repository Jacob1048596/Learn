void InsertSort(int* a, int n)
{
	assert(a);
	//最后一次，是要把n - 1这个数进行排序，则已经
	//排好序的尾部为n - 2
	for (int i = 0; i < n-1; ++i)
	{
		//end表示已经排好序的尾标
		int end = i;
		//首先保存要排序的数，一会就会被覆盖了
		int tmp = a[end + 1];
		//只要前面的数大于end + 1,则前面的这些数都向后挪动一个位置
		while (end >= 0 && a[end] > tmp)
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 3, 5, 7 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void ShellSort(int* a, int n)
{
	assert(a);

	int gap = n;
	//不能写成大于0,因为gap的值始终>=1
	while (gap > 1)
	{
		//只有gap最后为1，才能保证最后有序
		//所以这里要加1
		gap = gap / 3 + 1;
		//这里只是把插入排序的1换成gap即可
		//但是这里不是排序完一个分组，再去
		//排序另一个分组，而是整体只过一遍
		//这样每次对于每组数据只排一部分
		//整个循环结束之后，所有组的数据排序完成
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end] > tmp)
			{
				a[end + gap] = a[end];
				end -= gap;
			}

			a[end + gap] = tmp;
		}
	}
}


void TestShellSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 3, 5, 7 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

/*
优化的选择排序，每次可以选择一个最大的和一个最小的
然后把他们放在合适的位置，
即最小的放在第一个位置，最大的放在最后一个位置，
然后再去选择次小的和次大的，依次这样进行，
直到区间只剩一个值或没有
*/
void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int min = begin, max = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] >= a[max])
				max = i;

			if (a[i] < a[min])
				min = i;
		}
		//最小的放在
		Swap(&a[begin], &a[min]);
		//如果最大的位置在begin位置
		//说明min是和最大的交换位置
		//这个时候max的位置就发生了变换
		//max变到了min的位置
		//所以要更新max的位置
		if (begin == max)
			max = min;

		Swap(&a[end], &a[max]);
		++begin;
		--end;

		//PrintArray(a, n);
	}
}

void TestSelectSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}
/*
n: 数组大小
root: 根位置
*/
void AdjustDown(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n) {
		if (child+1 < n && a[child+1] > a[child])
		 {
			++child;
		}

		if (a[child] > a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}


void HeapSort(int* a, int n)
{
	assert(a);

	// 建堆，先从最后两个叶子上的根(索引为(n - 2) / 2开始建堆
	// 先建最小的堆，直到a[0](最大的堆)
	// 这就相当于在已经建好的堆上面，新加入一个
	// 根元素，然后向下调整，让整个完全二叉树
	// 重新满足堆的性质
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	//end:表示最后一个位置
	int end = n - 1;
	//只剩一个数时，就不需要调整了
	while (end > 0)
	{
		//0位置和最后一个位置交换
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		--end;
	}
}

void TestHeapSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void BubbleSort(int* a, int n)
{
	assert(a);

	int end = n;
	while (end > 0)
	{
		/*
		加一个标记，如果中间没有发生交换
		说明前面的值都比后面的小
		即本身就是有序的，最好的情况下，
		它的时间复杂度就为N
		*/
		int flag = 0;
		for (int i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				flag = 1;
			}
		}

		if (flag == 0)
		{
			break;
		}

		--end;
	}
}

void TestBubbleSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// 三数取中法，三个中取一个中间值

int GetMidIndex(int* a, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
		{
			return mid;
		}
		else if (a[begin] > a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}
	else // begin >= mid
	{
		if (a[mid] > a[end])
		{
			return mid;
		}
		else if (a[begin] < a[end])
		{
			return begin;
		}
		else
		{
			return end;
		}
	}

}

int PartSort1(int* a, int begin, int end)
{
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	int key = a[begin];
	int start = begin;
	/*
	这里要从右边走，如果从左边走，
	可能最后一步，如果找不到大于
	基准值的，会导致begin == end
	即相遇，但是右边还没有走，所以
	这里的值一定大于基准值，最后交换
	就会出问题，所以一定要从右边走，
	即使最后一次找不到小于基准值的，
	会和左边相遇，而左边此时还没走，
	一定比基准值小，最后交换肯定没有问题
	*/
	while (begin < end)
	{
		// end 找小
		while (begin < end && a[end] >= key)
			--end;

		// begin找大
		while (begin < end && a[begin] <= key)
			++begin;

		Swap(&a[begin], &a[end]);
	}
    //最后的交换一定要保证a[begin] < a[start], 所以要从右边走
	Swap(&a[begin], &a[start]);
	return begin;
}

int PartSort2(int* a, int begin, int end)
{
	//begin是坑
	int key = a[begin];
	while (begin < end)
	{
		while (begin < end && a[end] >= key)
			--end;

		// end给begin这个坑，end就变成了新的坑。
		a[begin] = a[end];

		while (begin < end && a[begin] <= key)
			++begin;

		// end给begin这个坑，begin就变成了新的坑。
		a[end] = a[begin];
	}

	a[begin] = key;

	return begin;
}


/*
前后指针法
*/
int PartSort3(int* a, int begin, int end)
{
	int midindex = GetMidIndex(a, begin, end);
	Swap(&a[begin], &a[midindex]);

	int key = a[begin];
	int prev = begin;
	int cur = begin + 1;

	while (cur <= end)
	{
		// cur找小，把小的往前翻，大的往后翻
		if (a[cur] < key && ++prev != cur)
			Swap(&a[cur], &a[prev]);

		++cur;
	}

	Swap(&a[begin], &a[prev]);

	return prev;
}

// []
void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;

	if (right - left + 1 < 10)
	{
		InsertSort(a+left, right - left + 1);
	}
	else
	{
		int div = PartSort3(a, left, right);
		//[left, div-1]
		//[div+1, right]
		QuickSort(a, left, div - 1);
		QuickSort(a, div + 1, right);
	}
}
//用栈模拟递归，用队列也可以实现
void QuickSortR(int* a, int left, int right)
{
	Stack st;
	StackInit(&st, 10);
	//先入大区间
	if (left < right)
	{
		StackPush(&st, right);
		StackPush(&st, left);
	}
	//栈不为空，说明还有没处理的区间
	while (StackEmpty(&st) != 0)
	{
		left = StackTop(&st);
		StackPop(&st);
		right = StackTop(&st);
		StackPop(&st);
		//快排单趟排序
		int div = PartSort1(a, left, right);
		// [left div-1]
		// 把大于1个数的区间继续入栈
		if (left < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, left);
		}

		// [div+1, right]
		if (div+1 < right)
		{
			StackPush(&st, right);
			StackPush(&st, div + 1);
		}
	}

}

void TestQuickSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	QuickSortR(a, 0, sizeof(a) / sizeof(int)-1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;

	int mid = left + ((right - left) >> 1);

	// [left, mid]
	// [mid+1, right]
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	memcpy(a+left, tmp+left, sizeof(int)*(right - left+1));
}


void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

/*
非递归排序与递归排序相反，将一个元素与相邻元素构成有序数组，
再与旁边数组构成有序数组，直至整个数组有序。
要有mid指针传入，因为不足一组数据时，重新计算mid划分会有问题
需要指定mid的位置
*/
void merge(int* a, int left, int mid, int right, int* tmp)
{
	// [left, mid]
	// [mid+1, right]
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}

	while (begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}

	memcpy(a+left, tmp+left, sizeof(int)*(right - left+1));
}

/*
k用来表示每次k个元素归并
*/
void mergePass(int *arr, int k, int n, int *temp)
{
    int i = 0;
    //从前往后,将2个长度为k的子序列合并为1个
    while(i < n - 2*k + 1)
    {
        merge(arr, i, i + k - 1, i + 2*k - 1, temp);
        i += 2*k;
    }
    //合并区间[i, n - 1]有序的左半部分[i, i + k - 1]以及不及一个步长的右半部分[i + k, n - 1]
    if(i < n - k )
    {
        merge(arr, i, i + k - 1,n-1, temp);
    }
    
}

// 归并排序非递归版
void MergeSortNonR(int *arr,int length)
{
    int k = 1;
    int *temp = (int *)malloc(sizeof(int) * length);
    while(k < length)
    {
        mergePass(arr, k, length, temp);
        k *= 2;
    }
    free(temp);
}

void TestMergeSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// O(Max(N, 范围))
// O(N+范围) 时间复杂度
// O(范围) 空间复杂度
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}
	//找到数据的范围
	int range = max - min + 1;
	int* countArray = (int*)malloc(range*sizeof(int));
	memset(countArray, 0, sizeof(int)*range);
	//存放在相对位置，可以节省空间
	for (int i = 0; i < n; ++i)
	{
		countArray[a[i] - min]++;
	}
	//可能存在重复的数据，有几个存几个
	int index = 0;
	for (int i = 0; i < range; ++i)
	{	
		while (countArray[i]--)
		{
			a[index++] = i+min;
		}
	}
}

void TestCountSort()
{
	int a[] = { 3, 4, 6, 2, 8, 5, 2, 2, 9, 9, 1000000, 99999};
	CountSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void TestSortOP()
{
	const int n = 1000000;
	int* a1 = (int*)malloc(sizeof(int)*n);
	int* a2 = (int*)malloc(sizeof(int)*n);
	int* a3 = (int*)malloc(sizeof(int)*n);
	int* a4 = (int*)malloc(sizeof(int)*n);
	int* a5 = (int*)malloc(sizeof(int)*n);
	int* a6 = (int*)malloc(sizeof(int)*n);
	int* a7 = (int*)malloc(sizeof(int)*n);
	int* a8 = (int*)malloc(sizeof(int)*n);

	srand(time(0));
	for (int i = 0; i < n; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
		a7[i] = a1[i];
		a8[i] = a1[i];
	}
	a8[n] = 100000000;

	size_t begin1 = clock();
	//InsertSort(a1, n);
	size_t end1 = clock();
	printf("%u\n", end1 - begin1);

	size_t begin2 = clock();
	ShellSort(a2, n);
	size_t end2 = clock();
	printf("%u\n", end2 - begin2);

	size_t begin3 = clock();
	//SelectSort(a3, n);
	size_t end3 = clock();
	printf("%u\n", end3 - begin3);

	size_t begin4 = clock();
	HeapSort(a4, n);
	size_t end4 = clock();
	printf("%u\n", end4 - begin4);
	
	size_t begin5 = clock();
	//BubbleSort(a5, n);
	size_t end5 = clock();
	printf("%u\n", end5 - begin5);

	size_t begin6 = clock();
	QuickSort(a6, 0, n-1);
	size_t end6 = clock();
	printf("%u\n", end6 - begin6);

	size_t begin7 = clock();
	MergeSort(a7, n);
	size_t end7 = clock();
	printf("%u\n", end7 - begin7);

	size_t begin8 = clock();
	CountSort(a8, n);
	size_t end8 = clock();
	printf("%u\n", end8 - begin8);
}