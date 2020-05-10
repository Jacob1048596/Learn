#pragma once
#include <stdlib.h>
#include <stdio.h>
//À≥–Ú±Ì µœ÷’ª
typedef int Type;

typedef struct Stack
{
	Type* _array;
	size_t _size;
	size_t _capacity;
}Stack;

void stackInit(Stack* st, size_t n);

void stackPush(Stack* st, Type data);
void stackPop(Stack* st);
Type stackTop(Stack* st);

size_t stackSize(Stack* st);
int stackEmpty(Stack* st);

void stackDestory(Stack* st);
