#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define true 1
#define false 0
typedef char ElementType; /* 数据项类型暂定为char */
typedef struct TNode *BinTree;
struct TNode { /* 树结点定义 */
	ElementType Data; /* 结点数据 */
	BinTree Left;     /* 指向左子树 */
	BinTree Right;    /* 指向右子树 */
};

/* 初始化空树 可以是根树也可以是子树 根节点空间可存放数据 */
BinTree MakeBT(ElementType data)
{
	BinTree BT;
	BT = (BinTree)malloc(sizeof(struct TNode));
	BT->Data = data; /* 直接存数据 方便递归调用 */
	BT->Left = NULL;
	BT->Right = NULL;
	return BT;
}

/* 判断树空 */
int IsEmpty(BinTree BT)
{	/* 直接对BT进行判断 方便递归调用 */
	if (BT == NULL) 
		return 1;
	else
		return 0;
}

/* 后序遍历释放整棵树空间 */
void DestroyBT(BinTree BT)
{	/* 只有后序遍历才能真正释放掉全部空间 而不丢失 */
	if (BT) {
		DestroyBT(BT->Left);
		DestroyBT(BT->Right);
		free(BT);
	}
}

/* 递归中序遍历 */
void InorderTraversal(BinTree BT)
{
	if (BT) {
		InorderTraversal(BT->Left);
		/* 此处假设对BT结点的访问就是打印数据 */
		printf("%c ", BT->Data); /* 假设数据为字符型 */
		InorderTraversal(BT->Right);
	}
}

/* 递归先序遍历 */
void PreorderTraversal(BinTree BT)
{
	if (BT) {
		printf("%c ", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}

/* 递归后序遍历 */
void PostorderTraversal(BinTree BT)
{
	if (BT) {
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf("%c ", BT->Data);
	}
}

/* 递归双序遍历 先访问结点 再双序遍历左子树 再访问一次 再双序遍历右子树 */
void DoubleorderTraversal(BinTree BT)
{
	if (BT) {
		printf("%c ", BT->Data);
		DoubleorderTraversal(BT->Left);
		printf("%c ", BT->Data);
		DoubleorderTraversal(BT->Right);
	}
}

/** 层序遍历 利用队列 **/

struct QNode {
	BinTree *Data;     /* 存储树结点指针的数组的首地址 */
	int Front, Rear;  /* 队列的头、尾指针 */
	int MaxSize; /* 队列最大容量 真实容量为Maxsize-1 方便循环队列区分空满*/
};
typedef struct QNode *Queue;

Queue CreateQueue(int MaxSize)
{   /* 初始化队列 */
	Queue Q = (Queue)malloc(sizeof(struct QNode));
	Q->Data = (BinTree *)malloc(MaxSize * sizeof(BinTree));
	Q->Front = Q->Rear = 0;
	Q->MaxSize = MaxSize;
	return Q;
}

int IsQueueEmpty(Queue Q)
{   /* 判断队列空 仅当头尾指针重合 都指向同一个无用空间 */
	return (Q->Front == Q->Rear);
}

BinTree DeQueue(Queue Q)
{   /* 出队 无需判断队列空 因为循环条件已经限制 */
	Q->Front = (Q->Front + 1) % Q->MaxSize;
	return  Q->Data[Q->Front];
}

int EnQueue(Queue Q, BinTree x)
{	/* 入队 需要考虑队列满 */
	if ((Q->Rear + 1) % Q->MaxSize == Q->Front) {
		printf("队列满"); /* 提示队列申请空间不足 */
		return 0;
	}
	else {
		Q->Rear = (Q->Rear + 1) % Q->MaxSize;
		Q->Data[Q->Rear] = x;
		return 1;
	}
}

void LevelorderTraversal(BinTree BT)
{
	Queue Q;
	BinTree T;

	if (!BT) return; /* 若是空树则直接返回 */

	Q = CreateQueue(100); /* 创建空队列Q */
	EnQueue(Q, BT);
	while (!IsQueueEmpty(Q)) {
		T = DeQueue(Q);
		printf("%c ", T->Data); /* 访问取出队列的结点 */
		if (T->Left)   EnQueue(Q, T->Left);
		if (T->Right)  EnQueue(Q, T->Right);
	}
}	
/*  附：利用层序遍历 将一维数组改为结构体数组 
	还可存储每个结点所在的层数 第一个结点记为1 EnQueue孩子时增1 
	还可存储每个结点的双亲 EnQueue孩子时顺便记录双亲结点 
	还可存储每个结点的出度 成功EnQueue一次就增1 最大到2 
	遍历整个数组（包括已经出队列的结构体）可以找到最大层数 即树深度
	遍历时计数level[i]++ 还可求出每一层的宽度	
*/

/** 非递归中序遍历 利用栈 **/

struct SNode {
	BinTree *Data; /* 存储树结点指针的数组的首地址 Data是指针 */
	int Top;      /* 栈顶标识数 */
	int MaxSize;  /* 堆栈总长 数组[0]不存放 实际容量为MaxSize-1 */
};
typedef struct SNode *Stack;

Stack CreateStack(int MaxSize)
{	/* 创建空栈 */
	Stack S = (Stack)malloc(sizeof(struct SNode));
	S->Data = (BinTree *)malloc(MaxSize * sizeof(BinTree));
	S->Top = 0;
	S->MaxSize = MaxSize;
	return S;
}

int Push(Stack S, BinTree x)
{	/* 压入元素 需要考虑栈满 */
	if (S->Top == S->MaxSize - 1) {
		printf("堆栈满"); /* 提示栈申请空间不足 */
		return 0;
	}
	else {
		S->Data[++(S->Top)] = x;
		return 1;
	}
}

BinTree Pop(Stack S)
{	/* 出栈 无需判断栈空 因为循环条件已经限制 */
	return (S->Data[(S->Top)--]);
}

void InOrderStackTraversal(BinTree BT)
{
	Stack S;
	BinTree T = BT;

	if (!BT) return; /* 若是空树则直接返回 */

	S = CreateStack(100); /* 创建空栈S */
	do{
		while (T != NULL)
		{	/* 一直读取左子树直到最左下角NULL */
			Push(S, T);
			T = T->Left;
		}
		if (S->Top != 0)
		{	/* 若栈中还有结点 */
			T = Pop(S); /* 将中序遍历的下一结点弹出 */
			printf("%c ", T->Data); /* 输出 */
			T = T->Right; /* 再看右子树 */
		}
	} while ((S->Top != 0) || (T != NULL));
}

/** 非递归先序遍历 利用栈 **/
void  PreOrderStackTraversal(BinTree BT)
{
	Stack S;
	BinTree T = BT;

	if (!BT) return; /* 若是空树则直接返回 */

	S = CreateStack(100); /* 创建空栈S */
	do{
		while (T != NULL)
		{
			printf("%c ", T->Data); /* 输出 */
			Push(S, T);
			T = T->Left; /* 一直读取左子树直到最左下角NULL */
		}
		if (S->Top != 0)
		{
			T = Pop(S); /* 将先序遍历的下一结点弹出 */
			T = T->Right; /* 再看右子树 */
		}
	} while ((S->Top != 0) || (T != NULL));
}

/** 非递归后序遍历 利用栈 **/
void  PostOrderStackTraversal(BinTree BT)    //后序遍历，非递归
{
	Stack S;
	BinTree T = BT;

	if (!BT) return; /* 若是空树则直接返回 */

	BinTree p;
	int b;
	S = CreateStack(100); /* 创建空栈S */
	do {
		while (T != NULL)
		{
			Push(S, T);
			T = T->Left; /* 一直读取左子树直到最左下角NULL */
		}
		p = NULL;
		b = 1; /* 代表右子树不存在 */
		while ((S->Top != 0) && b)
		{	/* 当栈中还有元素 且栈顶指针右子树不存在或已访问 */
			T = S->Data[S->Top];
			if (T->Right == p) 
			{	/* p一开始是NULL 表示试探右子树发现不存在 */
				printf("%c ", T->Data); /*右子树不存在 输出根结点 */
				Pop(S); /* 弹出已经访问过的根结点 */
				p = T; /* 右子树已经访问过 用p标记 便于下次试探 */
			}
			else
			{	/* 右子树未探索 即 左子树已经完全探索过 */
				T = T->Right; /* 再看右子树 */
				b = 0; /* 代表右子树未探索过 进入新的子树循环 */
			}
		}
	} while (S->Top != 0);
}

/* 已知带#（空）的先序序列 生成整棵树 */
BinTree PreCreate()
{
	BinTree BT;
	ElementType ch;
	while (getchar() != '\n');
	scanf("%c", &ch);
	if (ch == '#')
		BT = NULL; /* 直接置空 因为不设置空头结点 第一个结点就要存放数据 */
	else
	{
		BT = MakeBT(ch);
		if (!BT) exit(0); /* 申请不到空间 直接结束程序 */
		BT->Left = PreCreate();
		BT->Right = PreCreate(); /* 递归调用函数 生成左右子树 */
	}
	return BT;
}

/* 二叉树的交互问答建立 */
BinTree QACreate(int flag)
{	
	BinTree BT = NULL;
	ElementType ch;
	if (flag == 0)
	{	/* 初次调用函数时 传入参数为0 输出相应提示 */
		printf("根结点：");
	}
	scanf(" %c", &ch);
	while (getchar() != '\n');
	if (ch != '#')
	{	/* 非空 递归调用 */
		BT = MakeBT(ch);
		printf("%c的左孩子是：", BT->Data);
		BT->Left = QACreate(1);
		printf("%c的右孩子是：", BT->Data);
		BT->Right = QACreate(1);
	}
	return BT;
}

/* 递归求任意二叉树的深度 不用层序遍历 */
int Depth(BinTree BT)
{
	int ldepth, rdepth; /* 不需要赋初值 */
	if (BT == NULL)
		return 0; /* 基层条件：递归到叶子结点的NULL子树 */
	else
	{	/* 非空 */
		ldepth = Depth(BT->Left);
		rdepth = Depth(BT->Right); /* 递归求左右子树深度 */
		if (ldepth > rdepth) /* 取较深的+1 为自己所在树的深度 */
			return ldepth + 1;
		else
			return rdepth + 1;
	}
}

/* 判断两颗二叉树是否等价 */
int Equal(BinTree BT1, BinTree BT2)
{
	int x = 0; 
	if (IsEmpty(BT1) && IsEmpty(BT2))
	{	/* 如果两树都空 必定相等 */
		x = 1;
	}
	else if (!IsEmpty(BT1) && !IsEmpty(BT2))
	{	/* 排除掉一空一有的情况 两树都非空时 */
		if (BT1->Data == BT2->Data)
		{	/* 先判断数据相等 */
			if (Equal(BT1->Left, BT2->Left))
			{	/* 两子树等价 这里把判断条件挪到赋值处 简化代码 */
				x = Equal(BT1->Right, BT2->Right);
			}
		}
	}
	return x;
}

/* 已知先序+中序 生成整棵树 */
BinTree PreInOrderCreate(ElementType a[], ElementType b[], int r1, int l1, int r2, int l2)
{	//四个参数分别为：先序遍历的起始位置和结束位置和中序遍历的起始位置和结束位置
	int i;
	if (r1 > l1)//如果已经到达叶子，返回
		return NULL;
	
	for (i = r2; b[i] != a[r1]; ++i);//找到根节点在中序遍历中的位置
	BinTree BT = MakeBT(a[r1]);
	BT->Left = PreInOrderCreate(a, b, r1 + 1, l1 - l2 + i, r2, i - 1);//递归求左子树的后序遍历，r1+1是指把根去掉之后的位置
	BT->Right = PreInOrderCreate(a, b, l1 - l2 + i + 1, l1, i + 1, l2);//递归求右子树的后序遍历
	return BT;
}
/* 已知后序+中序 生成整棵树 */

/* 已知带#层序序列 生成整棵树 */
/* 判断一颗任意二叉树是否为满二叉树 */
int isFull(BinTree BT)
{
	struct Node
	{
		BinTree bt;
		int level;     
	} Q[100]; /* 通过数组实现简单队列 不能申请循环队列 否则会丢失数据 */ 
     
	if (BT == NULL)
		return true;

	int rear = 0, front = 0; /* 第0个结点也存放数据 重合时表示有一个元素 */
	Q[rear].bt = BT;
	Q[rear].level = 1;
	int tot = 1; /* 总结点数 已经包含了根结点 */

	while (rear >= front) /* 只有当front反超rear才结束 */
	{
		if (Q[front].bt->Left)
		{
			tot++;
			Q[++rear].bt = Q[front].bt->Left;
			Q[rear].level = Q[front].level + 1;
		}
		if (Q[front].bt->Right)
		{
			tot++;
			Q[++rear].bt = Q[front].bt->Right;
			Q[rear].level = Q[front].level + 1;
		}
		front++;  /* 出队 */
	}
	int deep = Q[rear].level;; /* 总深度 rear必为最后一层的某个结点 */
	printf("\ndeep=%d, tot=%d\n", deep, tot);
	return 1 << deep == tot + 1; /* 位运算实现2^n */
}

/* 判断一颗任意二叉树是否为完全二叉树 也是层序遍历 但包含NULL 如果是完全二叉树则NULL必定连续出队 */
/* 求任意结点的所有祖先结点（根到该结点的路径）*/
/* 二叉链表存储的二叉树转换到按照完全二叉树存储的数组中 #号表示空结点 */
/* 测试主函数 */
int main()
{
	int i;
	char a[30];
	char b[30];
	BinTree BT;
	scanf("%s %s", a, b);
	int l = strlen(a);
	BT = PreInOrderCreate(a, b, 0, l - 1, 0, l - 1);
	PostorderTraversal(BT);
	return 0;
}
/* 二叉搜索树的建立，插入和删除 */
/* 堆排序的应用 */