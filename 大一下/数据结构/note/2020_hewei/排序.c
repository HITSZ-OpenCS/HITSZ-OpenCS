#include<stdio.h>
#include<stdlib.h>

/* 以下所有排序都按升序 */
/* 数据暂定为整型 下标0存放数据 总共n个 第n位无数据 */
typedef int ElementType;

/* 简单插入排序 O(n^2) 稳定 */
void InsertSort(ElementType A[], int n)
{
	int p, i;
	ElementType tmp;

	for (p = 1; p < n; p++)
	{	/* 下标0的元素当成排序过的 */
		tmp = A[p]; /* 取出未排序序列中的第一个元素 减少交换的三步 */
		for (i = p; i > 0 && A[i - 1] > tmp; i--)/* 及时跳出循环 减少插入时不必要的探查 */
			A[i] = A[i - 1]; /*依次与已排序序列中元素比较并右移 */
		A[i] = tmp; /* 放进合适的位置 */
	}
}

/* 交换函数 */
void Swap(ElementType *x, ElementType *y)
{
	ElementType temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

/* 简单冒泡排序 O(n^2) 稳定 */
void BubbleSort(ElementType A[], int n)
{
	int i;
	int flag = 1; /* 标记是否进行了交换 */
	while (flag)
	{
		flag = 0; /* 假设没有交换 */
		for (i = 1; i < n; i++)
		{	/* 从下标1开始 每个数与前驱比较 */
			if (A[i] < A[i - 1])
			{
				Swap(&A[i], &A[i - 1]);
				flag = 1; /* 发生了交换 说明排序还没结束 */
			}
		}
	}
}

/* 简单选择排序 O(n^2) 不稳定 */
void SelectSort(ElementType A[], int n)
{
	int i, j;
	int index; /* 标记未排序序列中的最小数位置 */
	for (i = 0; i < n - 1; i++)
	{	/* 最后一次是下标n-2和下标n-1排序 */
		index = i;
		for (j = i + 1; j < n; j++)
		{
			if (A[j] < A[index])
			{
				index = j;
			}
		}
		Swap(&A[i], &A[index]);
	}
}

/* 原始希尔排序 不稳定 用减半序列 */
void OriShellSort(ElementType A[], int n)
{
	int  D, P, i;
	ElementType tmp;

	for (D = n / 2; D > 0; D /= 2)
	{
		for (P = D; P < n; P++)
		{ /* 插入排序 从下标D的开始 相当于普通从下标1开始 */
			tmp = A[P];
			for (i = P; i >= D && A[i - D] > tmp; i -= D)
				A[i] = A[i - D];
			A[i] = tmp;
		}
	}
}

/* 最优希尔排序 O(n^1.3) 不稳定 用Sedgewick增量序列 */
void ShellSort(ElementType A[], int n)
{
	int Si, D, P, i;
	ElementType tmp;
	/* 这里只列出一小部分增量 */
	int Sedgewick[] = { 929, 505, 209, 109, 41, 19, 5, 1, 0 };

	for (Si = 0; Sedgewick[Si] >= n; Si++);
	/* 初始的增量Sedgewick[Si]不能超过待排序列长度 */

	for (D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
	{
		for (P = D; P < n; P++)
		{ /* 插入排序 从下标D的开始 相当于普通从下标1开始 */
			tmp = A[P];
			for (i = P; i >= D && A[i - D] > tmp; i -= D)
				A[i] = A[i - D];
			A[i] = tmp;
		}
	}
}

/* 堆排序 O(nlogn) 不稳定 */

void PercDown(ElementType A[], int p, int N)
{ /* 过滤函数 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
	int Parent, Child;
	ElementType X;

	X = A[p]; /* 取出根结点存放的值 */
	for (Parent = p; (Parent * 2 + 1) < N; Parent = Child)
	{ /* 因为头结点下标是0 所以2 * N + 1表示左子树 */
		Child = Parent * 2 + 1;
		if ((Child != N - 1) && (A[Child] < A[Child + 1]))
		{	/* 如果不是最后一个Child 还有右Child且更大 */
			Child++;  /* Child指向左右子结点的较大者 */
		}
		if (X >= A[Child])
			break; /* 找到了合适位置 */
		else  /* 下滤X */
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

void HeapSort(ElementType A[], int N)
{ /* 堆排序 N是结点总数 下标N不存放 */
	int i;

	for (i = N / 2 - 1; i >= 0; i--)
	{	/* 建立最大堆 从最后一个非叶子结点开始 */
		PercDown(A, i, N);
	}

	for (i = N - 1; i > 0; i--)
	{	/* 删除最大堆顶 */
		Swap(&A[0], &A[i]); /* 最大堆顶置于数组末 */
		PercDown(A, 0, i); /* 剩余的元素组建新堆 */
	}
}

/* 归并排序 - 递归实现 优点：稳定 缺点：额外空间 */

/* L = 左边起始位置, R = 右边起始位置, RightEnd = 右边终点位置*/
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{ /* 将有序的A[L]~A[R-1]和A[R]~A[RightEnd]归并成一个有序序列 */
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R - 1; /* 左边终点位置 */
	Tmp = L;         /* 有序序列的起始位置 */
	NumElements = RightEnd - L + 1;

	while (L <= LeftEnd && R <= RightEnd)
	{
		if (A[L] <= A[R])
			TmpA[Tmp++] = A[L++]; /* 将左边元素复制到TmpA */
		else
			TmpA[Tmp++] = A[R++]; /* 将右边元素复制到TmpA */
	}

	while (L <= LeftEnd)
		TmpA[Tmp++] = A[L++]; /* 直接复制左边剩下的 */
	while (R <= RightEnd)
		TmpA[Tmp++] = A[R++]; /* 直接复制右边剩下的 */

	for (i = 0; i < NumElements; i++, RightEnd--)
		A[RightEnd] = TmpA[RightEnd]; /* 将有序的TmpA[]复制回A[] */
}

void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{ /* 核心递归排序函数 */
	int Center;

	if (L < RightEnd) {
		Center = (L + RightEnd) / 2;
		Msort(A, TmpA, L, Center);              /* 递归解决左边 */
		Msort(A, TmpA, Center + 1, RightEnd);     /* 递归解决右边 */
		Merge(A, TmpA, L, Center + 1, RightEnd);  /* 合并两段有序序列 */
	}
}

void MergeSort(ElementType A[], int N)
{ /* 归并排序 */
	ElementType *TmpA;
	TmpA = (ElementType *)malloc(N*sizeof(ElementType));

	if (TmpA != NULL) {
		Msort(A, TmpA, 0, N - 1);
		free(TmpA);
	}
	else printf("空间不足");
}

/* 归并排序 - 循环实现 */
/* 这里Merge函数在递归版本中给出 */

/* length = 当前有序子列的长度*/
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{ /* 两两归并相邻有序子列 */
	int i, j;

	for (i = 0; i <= N - 2 * length; i += 2 * length)
		Merge(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < N) /* 剩余大于1个 但不足2个 子列归并 */
		Merge(A, TmpA, i, i + length, N - 1);
	else /* 最后只剩1个子列 */
		for (j = i; j < N; j++) TmpA[j] = A[j];
}

void Merge_Sort(ElementType A[], int N)
{
	int length;
	ElementType *TmpA;

	length = 1; /* 初始化子序列长度 */
	TmpA = (ElementType *)malloc(N * sizeof(ElementType));
	if (TmpA != NULL) {
		while (length < N)
		{
			Merge_pass(A, TmpA, N, length);
			length *= 2;
			/* 如果Merge里面有复制过程 以下代码就不用 */
			/* 否则利用以下代码可以保证最后进行偶数次Merge_pass 结果保存在A数组 */
			Merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
	else printf("空间不足");
}

/* 快速排序 */

ElementType Median3(ElementType A[], int Left, int Right)
{ /* 在左、中、右中选取中位数作枢轴 */
	int Center = (Left + Right) / 2;
	if (A[Left] > A[Center])
		Swap(&A[Left], &A[Center]);
	if (A[Left] > A[Right])
		Swap(&A[Left], &A[Right]);
	if (A[Center] > A[Right])
		Swap(&A[Center], &A[Right]);
	/* 此时A[Left] <= A[Center] <= A[Right] */
	Swap(&A[Center], &A[Right - 1]); /* 将基准Pivot藏到右边*/
									 /* 只需要考虑A[Left+1] … A[Right-2] */
	return  A[Right - 1];  /* 返回基准Pivot */
}

void Qsort(ElementType A[], int Left, int Right)
{ /* 核心递归函数 */
	int Pivot, Low, High;
	int Cutoff = 100; /* 阈值 */

	if (Cutoff <= Right - Left) { /* 如果序列元素充分多，进入快排 */
		Pivot = Median3(A, Left, Right); /* 选基准 */
		Low = Left; High = Right - 1;
		while (1)
		{ /*将序列中比基准小的移到基准左边，大的移到右边*/
			while (A[++Low] < Pivot);
			while (A[--High] > Pivot);
			/* 注意此处相等也要停下换 否则如果不停 遇到全等序列 就会使枢轴一直在右端 O(n^2) */
			if (Low < High) Swap(&A[Low], &A[High]);
			else break; /* Low超过/等于High 表示指针已经越位 */
		}
		Swap(&A[Low], &A[Right - 1]);   /* 将基准换到正确的位置 */
		Qsort(A, Left, Low - 1);    /* 递归解决左边 */
		Qsort(A, Low + 1, Right);   /* 递归解决右边 */
	}
	else InsertSort(A + Left, Right - Left + 1); /* 元素太少，用简单排序 避免递归占用 */
}

void QuickSort(ElementType A[], int N)
{ /* 统一接口 */
	Qsort(A, 0, N - 1);
}

/* 基数排序 */

/* 假设元素最多有MaxDigit个关键字，基数全是同样的Radix */
#define MaxDigit 4
#define Radix 10

/* 桶元素结点 */
typedef struct Node *PtrToNode;
struct Node {
	int key;
	PtrToNode next;
};

/* 桶头结点 */
struct HeadNode {
	PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit(int X, int D)
{ /* 默认次位D=1, 主位D<=MaxDigit */
	int d, i;

	for (i = 1; i <= D; i++) {
		d = X % Radix;
		X /= Radix;
	}
	return d;
}

void LSDRadixSort(ElementType A[], int N)
{	/* 基数排序 - 次位优先 */
	/* 次位即最不重要的位 先排次位后 只能再对整体排序 不能内部排 */
	int D, Di, i;
	Bucket B;
	PtrToNode tmp, p, List = NULL;

	for (i = 0; i < Radix; i++) /* 初始化每个桶为空链表 */
		B[i].head = B[i].tail = NULL;
	for (i = 0; i < N; i++)
	{	/* 将原始序列逆序存入初始链表List 这个顺序无所谓 */
		tmp = (PtrToNode)malloc(sizeof(struct Node));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp; /* 将tmp插在List与已有序列间 */
	}
	/* 下面开始排序 */
	for (D = 1; D <= MaxDigit; D++)
	{ /* 对数据的每一位循环处理 */
		/* 下面是分配的过程 */
		p = List;
		while (p) {
			Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
			tmp = p; p = p->next; /* 从List中摘除 */
			/* 插入B[Di]号桶尾 后进的元素在tail */
			tmp->next = NULL;
			if (B[Di].head == NULL)
				B[Di].head = B[Di].tail = tmp;
			else {
				B[Di].tail->next = tmp;
				B[Di].tail = tmp;
			}
		}
		/* 下面是收集的过程 */
		List = NULL;
		for (Di = Radix - 1; Di >= 0; Di--)
		{	/* 将每个桶的元素顺序收集入List 一定要先放最大基数 */
			if (B[Di].head)
			{	/* 如果桶不为空 */
				/* 整桶插入List表头 */
				B[Di].tail->next = List;
				List = B[Di].head;
				B[Di].head = B[Di].tail = NULL; /* 清空桶 */
			}
		}
	}
	/* 将List倒入A[]并释放空间 */
	for (i = 0; i < N; i++) {
		tmp = List;
		List = List->next;
		A[i] = tmp->key;
		free(tmp);
	}
}

void MSD(ElementType A[], int L, int R, int D)
{ /* 核心递归函数: 对A[L]...A[R]的第D位数进行排序 */
	int Di, i, j;
	Bucket B;
	PtrToNode tmp, p, List = NULL;
	if (D == 0) return; /* 递归终止条件 */

	for (i = 0; i < Radix; i++) /* 初始化每个桶为空链表 */
		B[i].head = B[i].tail = NULL;
	for (i = L; i <= R; i++) 
	{ /* 将原始序列逆序存入初始链表List */
		tmp = (PtrToNode)malloc(sizeof(struct Node));
		tmp->key = A[i];
		tmp->next = List;
		List = tmp;
	}
	/* 下面是分配的过程 */
	p = List;
	while (p) {
		Di = GetDigit(p->key, D); /* 获得当前元素的当前位数字 */
		tmp = p; p = p->next; /* 从List中摘除 */
		/* 插入B[Di]号桶头 后进的元素在head */
		if (B[Di].head == NULL) B[Di].tail = tmp;
		tmp->next = B[Di].head;
		B[Di].head = tmp;
	}
	/* 下面是收集的过程 */
	i = j = L; /* i, j记录当前要处理的A[]的左右端下标 */
	for (Di = 0; Di < Radix; Di++)
	{ /* 对于每个桶 */
		if (B[Di].head)
		{ /* 将非空的桶整桶倒入A[], 递归排序 */
			p = B[Di].head;
			while (p) {
				tmp = p;
				p = p->next;
				A[j++] = tmp->key;
				free(tmp);
			}
			/* 递归对该桶内数据排序, 位数减1 */
			MSD(A, i, j - 1, D - 1);
			i = j; /* 为下一个桶对应的A[]左端 */
		}
	}
}

void MSDRadixSort(ElementType A[], int N)
{	/* 基数排序 - 主位优先   统一接口 */
	/* 主位即最重要的位 主位先有序了 再内部排序 整体必定有序 */
	MSD(A, 0, N - 1, MaxDigit); /* 因此D要传最高位 */
}