#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef int ElementType; /* 数据项类型暂定为int */
typedef struct Node *PtrToNode;
struct Node { /* 队列中的结点 */
	ElementType Data;
	PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode { /* 队列本身 */
	Position Front, Rear;  /* 队列的头、尾指针 */
};
typedef struct QNode *Queue;

/* 初始化队列 */
Queue MakeNull()
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Front = (Position)malloc(sizeof(struct Node));
	Q->Front->Next = NULL;
	Q->Rear = Q->Front; /* 空队列的头、尾指针指向同一个无数据的结点 该结点不用 */
	return Q;
}

/* 判断空队列 */
int IsEmpty(Queue Q)
{
	return (Q->Front == Q->Rear);
}

/* 返回队列首数据 */
ElementType GetFront(Queue Q)
{
	return Q->Front->Next->Data; /* 跳过队首不用的结点 */
}

/* 出队 */
#define ERROR -999 /* 标志错误 */
ElementType DeQueue(Queue Q)
{
	Position tmp;
	ElementType FrontElem;

	if (IsEmpty(Q)) {
		printf("队列空");
		return ERROR;
	}
	else {
		FrontElem = GetFront(Q);
		tmp = Q->Front->Next;
		Q->Front->Next = tmp->Next;
		free(tmp);  /* 释放被删除结点空间  */
		if (Q->Front->Next == NULL) /* 若队列本只有一个元素，出队后Rear没有目标 */
			Q->Rear = Q->Front; /* 让头尾指针重合，代表队列空 */
		return  FrontElem;
	}
}

/* 入队 */
void EnQueue(ElementType x, Queue Q)
{
	Q->Rear->Next = (Position)malloc(sizeof(struct Node));
	Q->Rear = Q->Rear->Next; /* 尾指针后移 */
	Q->Rear->Data = x;
	Q->Rear->Next = NULL;
}