#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <memory.h>
#include "sort.h"

void printArray(int* array, int n)
{
	for (int i = 0; i < n; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void test()
{
	int array[] = { 10, 2, 4, 1, 3, 6, 5, 12, 8, 6, 2 };
	int size = sizeof(array) / sizeof(array[0]);

	int* copy = (int*)malloc(sizeof(int)* size);
	memcpy(copy, array, sizeof(int)* size);

	int* copy2 = (int*)malloc(sizeof(int)* size);
	memcpy(copy2, array, sizeof(int)* size);

	int* copy3 = (int*)malloc(sizeof(int)* size);
	memcpy(copy3, array, sizeof(int)* size);

	int* copy4 = (int*)malloc(sizeof(int)* size);
	memcpy(copy4, array, sizeof(int)* size);

	int* copy5 = (int*)malloc(sizeof(int)* size);
	memcpy(copy5, array, sizeof(int)* size);

	int* copy6 = (int*)malloc(sizeof(int)* size);
	memcpy(copy6, array, sizeof(int)* size);

	int* copy7 = (int*)malloc(sizeof(int)* size);
	memcpy(copy7, array, sizeof(int)* size);

	int* copy8 = (int*)malloc(sizeof(int)* size);
	memcpy(copy8, array, sizeof(int)* size);

	int* copy9 = (int*)malloc(sizeof(int)* size);
	memcpy(copy9, array, sizeof(int)* size);

	int* copy10 = (int*)malloc(sizeof(int)* size);
	memcpy(copy10, array, sizeof(int)* size);

	int* copy11 = (int*)malloc(sizeof(int)* size);
	memcpy(copy11, array, sizeof(int)* size);

	printArray(array, size);
	insertSort(array, size);
	printf("insertSort: \n");
	printArray(array, size);

	shellSort(copy, size);
	printf("shellSort: \n");
	printArray(copy, size);

	selectSort(copy2, size);
	printf("selectSort: \n");
	printArray(copy2, size);

	selectSort2(copy3, size);
	printf("selectSort2: \n");
	printArray(copy3, size);

	bubbleSort(copy4, size);
	printf("bubbleSort: \n");
	printArray(copy4, size);

	bubbleSort(copy4, size);
	printf("sorted bubbleSort: \n");
	printArray(copy4, size);

	heapSort(copy5, size);
	printf("heapSort: \n");
	printArray(copy5, size);

	quickSort(copy6, 0, size - 1);
	printf("quickSort: \n");
	printArray(copy6, size);

	quickSortNoR(copy7, size);
	printf("quickSortNoR: \n");
	printArray(copy7, size);

	quickSortNoR2(copy8, size);
	printf("quickSortNoR2: \n");
	printArray(copy8, size);

	mergeSort(copy9, size);
	printf("mergeSort: \n");
	printArray(copy9, size);

	mergeSortNoR(copy10, size);
	printf("mergeSortNoR: \n");
	printArray(copy10, size);

	countSort(copy11, size);
	printf("countSort: \n");
	printArray(copy11, size);
	
}

void testTime()
{
	srand(time(NULL));
	int n;
	scanf("%d", &n);
	int* array = (int*)malloc(sizeof(int)* n);
	for (int i = 0; i < n; ++i)
	{
		array[i] = rand();
	}

	int* copy = (int*)malloc(sizeof(int)* n);
	memcpy(copy, array, sizeof(int)* n);

	int* copy2 = (int*)malloc(sizeof(int)* n);
	memcpy(copy2, array, sizeof(int)* n);

	int* copy3 = (int*)malloc(sizeof(int)* n);
	memcpy(copy3, array, sizeof(int)* n);

	int* copy4 = (int*)malloc(sizeof(int)* n);
	memcpy(copy4, array, sizeof(int)* n);

	int* copy5 = (int*)malloc(sizeof(int)* n);
	memcpy(copy5, array, sizeof(int)* n);

	int* copy6 = (int*)malloc(sizeof(int)* n);
	memcpy(copy6, array, sizeof(int)* n);

	int* copy7 = (int*)malloc(sizeof(int)* n);
	memcpy(copy7, array, sizeof(int)* n);

	size_t begin = clock();
	insertSort(array, n);
	size_t end = clock();
	printf("insertSort: %d\n", end - begin);

	begin = clock();
	insertSort(array, n);
	end = clock();
	printf("sorted insertSort: %d\n", end - begin);

	begin = clock();
	shellSort(copy, n);
	end = clock();
	printf("shellSort: %d\n", end - begin);

	begin = clock();
	shellSort(copy, n);
	end = clock();
	printf("sorted shellSort: %d\n", end - begin);

	begin = clock();
	selectSort(copy2, n);
	end = clock();
	printf("selectSort: %d\n", end - begin);

	begin = clock();
	selectSort(copy2, n);
	end = clock();
	printf("sorted selectSort: %d\n", end - begin);

	begin = clock();
	selectSort2(copy3, n);
	end = clock();
	printf("selectSort2: %d\n", end - begin);
	/*
	begin = clock();
	bubbleSort(copy4, n);
	end = clock();
	printf("bubbleSort: %d\n", end - begin);

	begin = clock();
	bubbleSort(copy4, n);
	end = clock();
	printf("sorted bubbleSort: %d\n", end - begin);
	*/
	begin = clock();
	heapSort(copy5, n);
	end = clock();
	printf("heapSort: %d\n", end - begin);

	begin = clock();
	quickSort(copy6, 0, n - 1);
	end = clock();
	printf("quickSort: %d\n", end - begin);

	begin = clock();
	quickSort(copy6, 0, n - 1);
	end = clock();
	printf("sorted quickSort: %d\n", end - begin);

	begin = clock();
	mergeSort(copy7, n);
	end = clock();
	printf("mergeSort: %d\n", end - begin);

	begin = clock();
	mergeSort(copy7, n);
	end = clock();
	printf("sorted mergeSort: %d\n", end - begin);

}

int main()
{
	test();
	//testTime();
	return 0;
}