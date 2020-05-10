#pragma  once
#include <stdlib.h>

typedef int QDataType;

typedef struct QNode
{
	struct QNode* _next;
	QDataType _data;
}QNode;

typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
	int _size;
}Queue;

void queueInit(Queue* q);

QNode* creatNode(QDataType data);

void queuePush(Queue* q, QDataType data);

void queuePop(Queue* q);

QDataType queueFront(Queue* q);

QDataType queueBack(Queue* q);

int queueSize(Queue* q);

int queueEmpty(Queue* q);

void queueDestory(Queue* q);
