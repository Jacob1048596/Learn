#pragma once

void Swap(int* array, int i, int j);

void insertSort(int* array, int n);
void shellSort(int* array, int n);
void selectSort(int* array, int n);
void selectSort2(int* array, int n);
void bubbleSort(int* array, int n);

void shiftDown(int* array, int n, int parent);
void heapSort(int* array, int n);

int getMid(int* array, int begin, int end);
int partion(int* array, int begin, int end);
int partion2(int* array, int begin, int end);
int partion3(int* array, int begin, int end);
void quickSort(int* array, int begin, int end);
void quickSortNoR(int* array, int n);
void quickSortNoR2(int* array, int n);

void merge(int* array, int begin, int mid, int end, int* tmp);
void mergeSortR(int* array, int begin, int end, int* tmp);
void mergeSort(int* array, int n);
void mergeSortNoR(int* array, int n);

void countSort(int* array, int n);
