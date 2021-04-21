#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef int ElementType; /* 数据项类型暂定为int */
typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position; /* 指向每一个结点可用 */
typedef PtrToLNode List;     /* 专指头结点 */

/* 初始化头结点 header结点是数据项a[1]的前驱，无数据，恒定的地址常量 */
Position MakeHeader()
{
	List p;
	p = (Position)malloc(sizeof(struct LNode)); /* 申请动态空间 */
	p->Next = NULL; /* 置空 */
	return p;
}

/* 将已有链表置空 */
List MakeNull(List L)
{
	Position p = L->Next; /* 慢指针p */
	Position q = p->Next; /* 快指针q */
	L->Next = NULL; 
	while (q != NULL) /* 当快指针指向NULL时结束 */
	{
		free(p);
		p = q;
		q = q->Next;
	}
	free(p); /* 慢指针停留在表尾，将其释放 */
	return L;
}

/* 查找表尾 */
Position End(List L)
{
	Position q = L;
	while (q->Next != NULL)
		q = q->Next;
	return q; /* 返回指向a[n]结点的指针 如果没有元素就返回头结点指针 */
}

/* 比较两个数据项 */
int Compare(ElementType x, ElementType y)
{
	return x == y; /* 数据项类型暂定为int */
}

/* 查找特定值x的首个位置 */
#define ERROR NULL /* 标志错误，查无时返回空指针 */
Position Find(List L, ElementType x)
{
	Position p = L; /* p指向L的header结点 */
	while (p->Next != NULL) {
		if (Compare(p->Next->Data, x))
			return p; /* 该位置指的是x的前驱的指针 */
		else
			p = p->Next;
	}
	printf("线性表内无该值\n");
	return ERROR;
}

/* 获取第i结点的位置 通常认为该位置是指向结点前驱a[i-1]的指针 */
Position GetPosition(List L, int i)
{
	Position p = L;
	int j = 0;
	while (p && j < i - 1)
	{
		p = p->Next;
		j++;
	}
	if (j == i - 1)
		return p; /* 返回指向其前驱的指针 */
	else
		return ERROR; /* 第i个结点不存在 */
}

/* 获取p指针指向结点的前驱 */
Position Previous(List L, Position p)
{
	Position pre;
	if (p  == L->Next)
	{
		printf("a[1]结点的前驱即为header结点\n");
		return L;
	}
	else
	{
		for (pre = L; pre && pre->Next != p; pre = pre->Next); 
		/* 注意&&两边的次序不能换，否则可能会越界访问NULL的空间 */
		if (!pre)
		{
			printf("该指针参数错误\n");
			return ERROR; /*查到表尾都没找到p指针*/
		}
		else
			return pre; /* 返回正确结果 */
	}
}

/* 带头结点的插入 所给的p是指向前驱的指针 */
int  Insert(List L, ElementType x, Position p)
{
	Position tmp;
	tmp = (Position)malloc(sizeof(struct LNode)); 
	tmp->Data = x; /* 申请、填装结点 */
	tmp->Next = p->Next; 
	p->Next = tmp; 
	return true;
}

/* 带头结点的删除 所给的p是指向前驱的指针 */
int Delete(List L, Position p)
{ 
	Position q;
	if (p->Next != NULL)
	{
		q = p->Next;
		p->Next = q->Next;
		free(q);
		return true;
	}
	else
	{
		printf("删除位置参数错误\n");
		return false;
	}
}

/* 获取链表长度 */
int Length(List L)
{
	Position p = L->Next;
	int n = 0;
	while (p)
	{
		n++;
		p = p->Next;
	}
	return n;
}

/* 遍历链表 */
void Run(List L)
{
	Position p = L->Next;
	int n = 0;
	while(p)
	{	
		printf("%d->", p->Data);
		n++;
		p = p->Next;
	}
	printf("\n链表长%d\n", n);
}

/* 逆序遍历链表 */
void BackRun(List L)
{
	Position p = L->Next;
	if (p->Next)
	{	/* 递归 */
		BackRun(p->Next);
	}
	printf("%d<-", p->Data);
}

/* 就地反向 时间复杂度O(n) 空间复杂度O(1)*/
void Reverse(List L)
{
	Position p, q; /* p慢q快*/
	p = L->Next;
	L->Next = NULL;
	while (p) 
	{
		q = p->Next; /* q指向下一结点防止丢失 */
		p->Next = L->Next; /* p指向头结点的下一个 即新链的首个 */
		L->Next = p; /* 头结点指向p 将新链续接 */
		p = q; /* p所指结点插入到头结点之后 p就和q归位到下一个要断的点 */
	}
}

/* 传入递增有序链表，删除表中所有大于x且小于y的元素 */
void DeleteXtoY(List L, ElementType x, ElementType y)
{
	Position p; /* 指针p遍历链表 直到指向末结点或指向待删除元素的前驱*/
	for (p = L; p->Next && p->Next->Data <= x ; p = p->Next);
	while (p->Next && p->Next->Data < y)
	{
		Delete(L, p); /* 删除结点 p是指向其前驱的指针 */
	}
	/* 循环结束时删光目标结点 p可能指向末结点 */
}

/* 两个递增链表合并成一个递增链表 */
List MergeIncrease(List La, List Lb)
{
	List Lc = MakeHeader();
	Position pa = La->Next;
	Position pb = Lb->Next;
	while (pa && pb)
	{	/* 较小数优先插入到Lc表尾 */
		if (pa->Data <= pb->Data)
		{
			Insert(Lc, pa->Data, End(Lc));
			pa = pa->Next;
		}
		else
		{
			Insert(Lc, pb->Data, End(Lc));
			pb = pb->Next;
		}
	}
	while (pa) /* 插入剩余部分 */	
	{
		Insert(Lc, pa->Data, End(Lc));
		pa = pa->Next;
	}
	while (pb)
	{
		Insert(Lc, pb->Data, End(Lc));
		pb = pb->Next;
	}
	return Lc;
}

/* 两个递增链表合并成一个递减链表 */
List MergeDecrease(List La, List Lb)
{
	List Lc = MakeHeader();
	Position pa = La->Next;
	Position pb = Lb->Next;
	while (pa && pb)
	{	/* 较小数优先插入到Lc表头 */
		if (pa->Data <= pb->Data)
		{
			Insert(Lc, pa->Data, Lc); /* 唯一的差别是去掉了End */
			pa = pa->Next;
		}
		else
		{
			Insert(Lc, pb->Data, Lc);
			pb = pb->Next;
		}
	}
	while (pa) /* 插入剩余部分 */
	{
		Insert(Lc, pa->Data, Lc);
		pa = pa->Next;
	}
	while (pb)
	{
		Insert(Lc, pb->Data, Lc);
		pb = pb->Next;
	}
	return Lc;
}

/* 判断单向链表中是否存在环 并返回相遇点 利用快慢指针相遇*/
Position IsCircle(List L)
{
	Position fast = L->Next; /* 开始都指向1号位 */
	Position slow = L->Next;
	while (fast && fast->Next) /* &&两边不能换 */
	{
		fast = fast->Next->Next; 
		slow = slow->Next;
		if (fast == slow)
			return fast; /* 返回相遇结点 即encounter指针 */
	}
	return NULL;
}

/* 已知存在环 利用encounter找到环的入口结点 */
Position FindEntry(List L)
{
	Position p1 = L->Next; /* 开始指向1号位 */
	Position p2 = IsCircle(L); /* 开始指向encounter */
	while (p1 != p2)
	{	/* 两个结点都以1的速度向前 最终必定会相遇在入口 */
		p1 = p1->Next;
		p2 = p2->Next; 
	}
	//计算过程：慢指针走了s=x+y 快指针走了2s=s+nr（多走n圈）
	//两式相减得x=nr-y x是1号位到入口的步数 y是入口到相遇处的步数
	//让p1走x步 则p2必定走nr后再退y步回到入口 两指针相遇
	return p1;
}

/* 查找链表倒数第k个数的位置 */
Position BackwardsK(List L, int k)
{
	Position p = L->Next;
	Position q = L->Next;
	int i;
	for (i = 0; i < k && p; i++)
		p = p->Next; /* p指针先向前k位 */
	if (!p)
	{
		printf("错误，链表长度不足%d位", k);
		retrun ERROR;
	}
	else
	{	/* 再让两个指针共同前进 直到p指向表尾 q就指向倒数第k位 */
		while (p)
		{
			p = p->Next;
			q = q->Next;
		}
	}
	return q;
}

/* 查找链表的中间位置 如果是偶数则返回前一个 */
Position FindMiddle(List L)
{
	int flag = 0; /* flag为1表示找到奇数的中间位置 */
	Position p = L->Next;
	Position mid = L->Next;
	while (p)
	{
		if (p->Next == NULL)
		{
			flag = 1;
			break;
		}
		p = p->Next->Next;
		mid = mid->Next;
	}
	if (flag)
		printf("有奇数个元素\n");
	else
		printf("有偶数个元素,返回前一个\n");
	return mid;
}

/* 临时主函数 */
int main()
{
	return 0;
}
