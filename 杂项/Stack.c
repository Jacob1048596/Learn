#include "Stack.h"

void stackInit(Stack* st, size_t n)
{
	st->_array = (Type*)malloc(sizeof(Type)* n);
	st->_capacity = n;
	st->_size = 0;
}

void stackPush(Stack* st, Type data)
{
	//¼ì²éÈÝÁ¿
	if (st->_size == st->_capacity)
	{
		st->_capacity *= 2;
		st->_array = (Type*)realloc(st->_array, st->_capacity * sizeof(Type));
	}
	//Î²²å
	st->_array[st->_size++] = data;
}
void stackPop(Stack* st)
{
	//Î²É¾
	if (st->_size)
		--st->_size;
}
Type stackTop(Stack* st)
{
	return st->_array[st->_size - 1];
}

size_t stackSize(Stack* st)
{
	return st->_size;
}
int stackEmpty(Stack* st)
{
	if (st->_size == 0)
		return 1;
	return 0;
}

void stackDestory(Stack* st)
{
	free(st->_array);
	st->_array = NULL;
	st->_size = st->_capacity = 0;
}
