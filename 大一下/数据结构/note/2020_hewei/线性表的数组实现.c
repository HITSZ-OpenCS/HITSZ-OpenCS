#include<stdio.h>
#define true 1
#define false 0
#define MAXSIZE 100
typedef int ElementType; /* 数据项类型暂定为int */
typedef int Position; /* 在数组中位置即整数 */
struct LNode {
	ElementType Data[MAXSIZE];
	Position Last;
};
typedef struct LNode *List;

/* 初始化 */
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = 0; /* 第一个位置不存放数据 */
	return L;
}

/* 置空 */
void Clear(List L)
{
	L->Last = 0;
}

/* 查找 */
#define ERROR -1
Position Find(List L, ElementType X)
{
	Position i = 1;
	while (i <= L->Last && L->Data[i] != X)
		i++;
	if (i > L->Last)  return ERROR; /* 如果没找到，返回错误信息 */
	else  return i;  /* 找到后返回的是存储位置 */
}

/* 插入 */
int Insert(List L, ElementType X, Position p)
{ /* 在L的指定位置P前插入一个新元素X */
	Position i;
	if (L->Last == MAXSIZE - 1) {
		/* 表空间已满，不能插入 */
		printf("表满");
		return false;
	}
	else if (p<1 || p>L->Last + 1) { /* 检查插入位置的合法性 */
		printf("位置不合法");
		return false;
	}
	else {
		for (i = L->Last; i >= p; i--)
			L->Data[i + 1] = L->Data[i]; /* 将位置P及以后的元素顺序向后移动 */
		L->Data[p] = X;  /* 新元素插入 */
		L->Last++;       /* Last自增1仍指向最后元素 */
		return true;
	}
}

/* 删除 */
int Delete(List L, Position p)
{ /* 从L中删除指定位置P的元素 */
	Position i;
	if (p<1 || p>L->Last) { /* 检查空表及删除位置的合法性 */
		printf("位置%d不存在元素", p);
		return false;
	}
	else {
		L->Last--; /* Last仍指向最后元素 */
		for (i = p; i <= L->Last; i++)
			L->Data[i] = L->Data[i + 1]; /* 将位置P+1及以后的元素顺序向前移动 */
		return true;
	}
}

/* 取值 */
ElementType Retrieve(Position p, List L)
{
	if (p > L->Last) {
		printf("指定元素不存在");
		return false;
	}
	else {
		return(L->Data[p]);
	}
}

/* 前驱位置 */
Position Pre(Position p, List L)
{
	if ((p <= 1) || (p > L->Last)) {
		printf("前驱元素不存在");
		return false;
	}
	else
		return p - 1;
}

/* 后继位置 */
Position Next(Position p, List L)
{
	if ((p < 1) || (p >= L->Last)) {
		printf("后继元素不存在");
		return false;
	}
	else
		return p + 1;
}

/* 开头位置 */
Position First(List L)
{
	return 1;
}

/* 结束位置 */
Position End(List L)
{
	return L->Last + 1; /* 最后一个元素的后一位 */
}

/* 判断数据项相同 */
int Same(ElementType x, ElementType y)
{
	if (x == y) /* 当数据类型改变时，换成相应的比较方法 */
		return true;
	else
		return false;
}

/* 去除所有值为d的元素 */
void DeleteSame(List L, ElementType d)
{
	Position p;
	p = First(L);
	while (p != End(L)) { /* 遍历直到p指向最后一个元素的后一位 */
		if (Same(Retrieve(p, L), d))
			Delete(p, L);
		else
			p = Next(p, L);
	}
}

/* 在升序数组上查找两个数，使它们的和正好是输入数字 */
int FindPair(List L, ElementType x, ElementType *a,ElementType *b)
{
	int length = L->Last;
	if (length < 2) /* 基础条件判断 */
		return false;
	else if (L->Data[1] >= x) /* 基础条件判断 */
		return false;
	int i = 1;
	while (i < length) /* 首尾数字向中间逼近直到重合 */
	{
		if (L->Data[i] + L->Data[length] == x)
		{
			*a = L->Data[i];
			*b = L->Data[length];
			return true; /* 成功找到 用指针域返回两个数的值 */
		}
		else if (L->Data[i] + L->Data[length] >x)
			length--;
		else
			i++;
	}
	return false;
}

/* 数组就地反向 */
void Reverse(List L)
{
	int length = L->Last;
	int i;
	ElementType temp;
	for (i = 0; i < length / 2; i++)
	{	/* 两数交换 总共进行length/2次 奇数时中间元素不换 */
		temp = L->Data[i + 1];
		L->Data[i + 1] = L->Data[length - i];
		L->Data[length - i] = temp;
	}
}

/* 数组[x,y]部分就地反向 */
void SectionReverse(List L, Position x, Position y)
{
	int i;
	ElementType temp;
	for (i = 0; i < (y - x + 1) / 2; i++)
	{	/* 两数交换 总共进行(y - x + 1)/2次 奇数时中间元素不换 */
		temp = L->Data[x + i];
		L->Data[x + i] = L->Data[y - i];
		L->Data[y - i] = temp;
	}
}

/* 数据循环移位 将数组元素向右循环移动k位 时间复杂度O(n) 允许两个额外变量 */
void Kshift(List L, int k)
{
	int length = L->Last;
	k %= length; /* 取模防止k超过总数 */

	SectionReverse(L, 1, length - k);
	SectionReverse(L, length - k + 1, length);
	Reverse(L);
}

/* 升序数组合并 且保持升序 返回新的数组 */
List Merge(List La, List Lb)
{
	List Lc = MakeEmpty();
	Position pa = First(La);
	Position pb = First(Lb);
	while (pa <= La->Last && pb <= Lb->Last)
	{	/* 较小数优先插入 */
		if (La->Data[pa] <= Lb->Data[pb])
			Insert(Lc, La->Data[pa++], End(Lc));
		else
			Insert(Lc, Lb->Data[pb++], End(Lc));
	}
	while(pa <= La->Last) /* 插入剩余部分 */
		Insert(Lc, La->Data[pa++], End(Lc));
	while(pb <= Lb->Last)
		Insert(Lc, Lb->Data[pb++], End(Lc));

	return Lc;
}