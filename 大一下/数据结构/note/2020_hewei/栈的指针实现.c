#include<stdio.h>
#define true 1
#define false 0
typedef int ElementType; /* 数据项类型暂定为int */
typedef struct SNode *PtrToSNode;
struct SNode {
	ElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack; /* 专指头结点 */
/* 指针实现栈时，top在头结点处，方便删除，因为删除要知道上一结点位置 */

/* 创建空栈 */
Stack CreateStack()
{/* 构建一个堆栈的头结点，返回该结点指针 */
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL; /* 头结点不存放数据 */
	/* 结点S->Next->data才存放首个数据 */
	return S;
}

/* 判断堆栈S是否为空，若是返回true，否则返回false */
int IsEmpty(Stack S)
{
	return (S->Next == NULL); /* 头结点下一个为NULL则空 */
}

/* 压入元素 */
int Push(Stack S, ElementType x)
{ /* 不用考虑栈满 */
	PtrToSNode TmpCell; /* 局部变量临时指针指向新结点 */
	TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
	TmpCell->Data = x;
	TmpCell->Next = S->Next;
	S->Next = TmpCell;
	return true;
}

/* 弹出元素 */
#define ERROR -999 /*错误标识，随ElementType而变*/
ElementType Pop(Stack S)
{ 
	PtrToSNode FirstCell; /* 指向栈顶元素 */
	ElementType TopElem;

	if (IsEmpty(S)) {
		printf("堆栈空");
		return ERROR;
	}
	else {
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell); /* 释放原栈顶元素空间 */
		return TopElem;
	}
}

/* 十进制整数转换为八进制输出 */
void Octal(int n)
{
	Stack S = CreateStack();
	while (n)
	{
		Push(S, n % 8);
		n /= 8;
	}
	while (!IsEmpty(S))
	{
		printf("%d", S->Next->Data);
		Pop(S);
	}
}



/* 测试用主函数 */
int main()
{
	int n = 0;
	printf("Input:");
	scanf("%d", &n);
	Octal(n);
	return 0;
}