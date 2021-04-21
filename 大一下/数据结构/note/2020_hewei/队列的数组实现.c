#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef int ElementType; /* 数据项类型暂定为int */
typedef int Position;
struct QNode {
	ElementType *Data;     /* 存储元素的数组的首地址 */
	Position Front, Rear;  /* 队列的头、尾指针 */
	int MaxSize; /* 队列最大容量 真实容量为Maxsize-1 方便循环队列区分空满*/
};
typedef struct QNode *Queue;

/* 初始化队列 */
Queue CreateQueue(int MaxSize)
{
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}

/* 判断队列满 头尾指针相差一个位置 头指针指的空间永远无用 */
int IsFull(Queue Q)
{
	return ((Q->Rear + 1) % Q->MaxSize == Q->Front);
}

/* 入队 */
int EnQueue(Queue Q, ElementType x)
{
	if (IsFull(Q)) {
		printf("队列满");
		return false;
	}
	else {
		Q->Rear = (Q->Rear + 1) % Q->MaxSize;
		Q->Data[Q->Rear] = x;
		return true;
	}
}

/* 判断队列空 仅当头尾指针重合 都指向同一个无用空间 */
int IsEmpty(Queue Q)
{
	return (Q->Front == Q->Rear);
}

/* 出队 */
#define ERROR -999 /* 标志错误 */
ElementType DeQueue(Queue Q)
{
	if (IsEmpty(Q)) {
		printf("队列空");
		return ERROR;
	}
	else {
		Q->Front = (Q->Front + 1) % Q->MaxSize; /* 从空头结点指向下一位置 */
		return  Q->Data[Q->Front]; /* 此时的Front指的就是第一个数据 */
	}
}