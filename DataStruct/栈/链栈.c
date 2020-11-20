#include<stdio.h>
#include <stdlib.h>
// #define MaxSize 1000
typedef  int ElementType;
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack( )
{ /* ����һ����ջ��ͷ��㣬���ظý��ָ�� */
    Stack S;

    S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty ( Stack S )
{ /* �ж϶�ջS�Ƿ�Ϊ�գ����Ƿ���true�����򷵻�false */
    return ( S->Next == NULL );
}

bool Push( Stack S, ElementType X )
{ /* ��Ԫ��Xѹ���ջS */
    PtrToSNode TmpCell;

    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}

ElementType Pop( Stack S )
{ /* ɾ�������ض�ջS��ջ��Ԫ�� */
    PtrToSNode FirstCell;
    ElementType TopElem;

    if( IsEmpty(S) ) {
        printf("��ջ��");
        return ERROR;
    }
    else {
        FirstCell = S->Next;
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}
