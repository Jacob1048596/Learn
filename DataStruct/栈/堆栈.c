#include<stdio.h>
#include <stdlib.h>
// #define MaxSize 1000
typedef  int ElementType;
// typedef struct SNode *Strack;
// struct SNode{
//   ElementType Date[MaxSize];
//   int Top;
// };
// Stack CreatStack(int MaxSize)
// {
//
// }
// int IsFull(Stack S,int MaxSize)
// {
//   return(s->Top==S->MaxSize-1)
// }
// void Push(Stack PtrS,ElementType item)
// {
//   if (PtrS->Top==MaxSize-1) {
//     printf("��ջ��\n");return;
//   }else{
//     PtrS->Data[++(PtrS->Top)]=item;
//     return;
//   }
// }
// int IsEmpty(Stack S)
// {
//   return (S->next)
// }
// ElementType Pop(Stack PtrS)
// {
//   if (PtrS->Top==-1) {
//     printf("��ջ��\n");
//     return ERROR;
//   }else return (PtrS->Data[(PtrS->Top)--]);
// }
typedef int Position;
struct SNode {
    ElementType *Data; /* �洢Ԫ�ص����� */
    Position Top;      /* ջ��ָ�� */
    int MaxSize;       /* ��ջ������� */
};
typedef struct SNode *Stack;

Stack CreateStack( int MaxSize )
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

bool IsFull( Stack S )
{
    return (S->Top == S->MaxSize-1);
}

bool Push( Stack S, ElementType X )
{
    if ( IsFull(S) ) {
        printf("��ջ��");
        return false;
    }
    else {
        S->Data[++(S->Top)] = X;
        return true;
    }
}

bool IsEmpty( Stack S )
{
    return (S->Top == -1);
}

ElementType Pop( Stack S )
{
    if ( IsEmpty(S) ) {
        printf("��ջ��");
        return ERROR; /* ERROR��ElementType������ֵ����־���� */
    }
    else
        return ( S->Data[(S->Top)--] );
}
