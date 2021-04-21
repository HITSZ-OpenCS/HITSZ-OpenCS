#include<stdio.h>
#define true 1
#define false 0
typedef char ElementType; /* 数据项类型暂定为char */
typedef int Position;
struct SNode {
	ElementType *Data; /* 存储元素的数组 Data是指针 */
	Position Top;      /* 栈顶标识数 */
	int MaxSize;       /* 堆栈总长 数组[0]不存放 实际容量为MaxSize-1 */
};
typedef struct SNode *Stack;

/* 创建空栈 */
Stack CreateStack(int MaxSize)
{
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
	S->Top = 0;
	S->MaxSize = MaxSize;
	return S;
}

/* 还原空栈 */
void MakeNull(Stack S)
{
	S->Top = 0;
}

/* 检查是否栈满 */
int IsFull(Stack S)
{
	return (S->Top == S->MaxSize - 1); /* 达到实际容量 */
}

/* 压入元素 */
int Push(Stack S, ElementType x)
{
	if (IsFull(S)) {
		printf("堆栈满");
		return false;
	}
	else {
		S->Data[++(S->Top)] = x;
		return true;
	}
}

/* 检查是否栈空 */
int IsEmpty(Stack S)
{
	return (S->Top == 0);
}

/* 弹出元素 */
#define ERROR -999 /* 错误标志，随ElementType而变 */
ElementType Pop(Stack S)
{
	if (IsEmpty(S)) {
		printf("堆栈空");
		return ERROR; /* ERROR是ElementType的特殊值，标志错误 */
	}
	else
		return (S->Data[(S->Top)--]);
}

/* 将中缀表达式转换为后缀表达式 */
void Change(char str[],Stack S)
{
	int i;
	ElementType e;
	for (i = 0; str[i] != '\0'; i++)  /* 遍历中缀表达式中的字符 */
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
		{   /* 如果为字母，则直接输出 */
			printf("%c", str[i]);
		}
		if (str[i] == "(")
		{	/* 遇到左括号直接入栈 */
			Push(S, str[i]);
		}
		if (str[i] == ")")
		{	/* 遇到右括号代表截止括号内的一切运算 */
			while (S->Data[S->Top] != "(")
			{
				e = Pop(S);
				printf("%c", e);
			}
			Pop(S); /* 最后再把左括号弹出 */
		}
		if (str[i] == '+' || str[i] == '-')  
		{   /*如果为加号或减号，则判断栈顶元素是否为乘除 */
			while (S->Data[S->Top] == '*' || S->Data[S->Top] == '/')
			{   /* 若此时栈顶为乘除，则输出栈顶元素 */
				e = Pop(S);   
				printf("%c", e);  
			}
			Push(S, str[i]);
		}
		if (str[i] == '*' || str[i] == '/') 
		{   /* 如果为乘除，则直接入栈 */
			Push(S, str[i]);
		}
	}
	while (S->Top != 0)    //若栈不为空，则将栈中的元素全部输出
	{
		e = Pop(S);
		printf("%c", e);
	}
}

/* 测试用主函数 */
int main()
{
	char str[100];
	Stack S = CreateStack(100);
	scanf("%s", str);
	Change(str, S);
	return 0;
}