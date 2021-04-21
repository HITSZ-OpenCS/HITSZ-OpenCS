/* 图的邻接表表示法 默认为无向带权图net */
#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100    /* 最大顶点数设为100 */
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;     /* 边的权值设为整型 */
typedef char DataType;      /* 顶点存储的数据类型设为字符型 */

/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      /* 有向边<V1, V2> */
	WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;         /* 邻接点下标 不直接用Data 便于修改值 */
	WeightType Weight;   /* 边权重 */
	PtrToAdjVNode Next;  /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode {
	PtrToAdjVNode FirstEdge;  /* 边表头指针 首个邻接点 */
	DataType Data;            /* 存顶点的数据 */
							  /* 注意：很多情况下，顶点无数据，此时Data可以不用出现 */
} AdjList;	/* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;     /* 顶点数 */
	int Ne;     /* 边数   */
	AdjList G[MaxVertexNum];  /* 邻接表 采用顺序存储 数组下标即顶点下标 从0开始 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */


/* 初始化一个有VertexNum个顶点但没有边的图 */
LGraph CreateGraph(int VertexNum)
{
	Vertex V;
	LGraph Graph;

	Graph = (LGraph)malloc(sizeof(struct GNode)); /* 建立图 */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* 初始化邻接表头指针 */
	/* 注意：这里默认顶点编号从0开始，到(Nv - 1) */
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;

	return Graph;
}

/* 插入单个边 需要传入Edge结构体指针 */
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;

	/* 插入边 <V1, V2> */
	/* 为V2建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	/* 将V2插入到V1的表头 */
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;

	/* 若是无向图，还要插入边 <V2, V1> */
	/* 为V1建立新的邻接点 */
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	/* 将V1插入到V2的表头 */
	NewNode->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode;
}

/* 创建图并赋值 */
LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	printf("Input the vextex num: ");
	scanf("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

	printf("Input the edge num: ");
	scanf("%d", &(Graph->Ne));   /* 读入边数 */
	if (Graph->Ne != 0)
	{	/* 如果有边 */
		E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
												/* 读入边，格式为"起点 终点 权重"，插入邻接表 */
		for (i = 0; i < Graph->Ne; i++) {
			printf("Input an edge as (V1 V2 Weight): ");
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			/* 注意：如果权重不是整型，Weight的读入格式要改 */
			InsertEdge(Graph, E);
		}
		free(E); /* 释放临时边结点空间 */
	}

	/* 如果顶点有数据的话，读入数据 */
	for (V = 0; V < Graph->Nv; V++)
	{
		printf("Input the vextex data in char: ");
		scanf(" %c", &(Graph->G[V].Data));
	}

	return Graph;
}

/* 返回图G中与顶点V邻接的第一个邻接点下标 -1为没有邻接点 */
Vertex FirstAdjV(LGraph Graph, Vertex V)
{
	if (Graph->G[V].FirstEdge)
		return Graph->G[V].FirstEdge->AdjV; /* 找到 */
	else /* 第一个邻接点就是NULL */
		return -1; /* 没找到 */
}

/* 返回图G中与顶点V邻接点中W的下一个邻接点 -1为无下一个邻接点 */
Vertex NextAdjV(LGraph Graph, Vertex V, Vertex W)
{
	PtrToAdjVNode P;
	P = Graph->G[V].FirstEdge; /* 引入指针指向邻接表头 */
	while (P->AdjV != W)
		P = P->Next; /* 先循环找到W所在的弧 此时已默认W正确 */
	if (P->Next) /* 看下一个邻接点 */
		return P->Next->AdjV; /* 找到 */
	else
		return -1; /* 没找到 */

}

/* 深度优先搜索递归函数 */
void  DFStravel(LGraph Graph, Vertex V, int* visited)
{
	visited[V] = 1; /* 标记访问过 */
	printf("%c ", Graph->G[V].Data);

	Vertex W;
	for (W = FirstAdjV(Graph, V); W != -1; W = NextAdjV(Graph, V, W))
	{	/* 该顶点的所有邻接点都要遍历 */
		if (!visited[W]) /* 如果该邻接点未访问过 */
			DFStravel(Graph, W, visited); /* 则递归调用 至最深处 */
	}
}

/* 深度优先搜索主算法 */
void DFS(LGraph Graph)
{
	Vertex V;
	int *visited = (int *)malloc(Graph->Nv * sizeof(int)); /* 动态申请标记数组 */
	/* 此处还可以申请count作先深编号计数器 */
	/* 在递归时用整型数组 dnf[V]=count 记录每个顶点访问的次序 */

	printf("DFS: ");
	for (V = 0; V < Graph->Nv; V++)
	{	/* 标记数组初始化 也可用memset */
		visited[V] = 0;
	}
	for (V = 0; V < Graph->Nv; V++)
	{	/* 从下标为0的顶点开始遍历 每次循环走过的边为一颗先深树 */
		if (!visited[V]) /* 循环的实际次数为图的连通分量数 */
			DFStravel(Graph, V, visited); /* 调用递归函数 */
	}

	free(visited); /* 释放动态空间 */
}

/* 广度优先搜索主算法 利用队列 */
void BFS(LGraph Graph)
{
	Vertex V;
	int *visited = (int *)malloc(Graph->Nv*sizeof(int)); /* 动态申请标记数组 */
	for (V = 0; V < Graph->Nv; V++)
	{	/* 标记数组初始化 也可用memset */
		visited[V] = 0;
	}

	printf("BFS: ");
	Vertex *VexQ = (Vertex *)malloc(Graph->Nv * sizeof(Vertex));
	int front = 0, rear = 0; /* 队列头尾位置标识重合 */
	/* 注意 此时的队列不是循环队列 申请了相同大小空间来存放所有结点 */
	/* 队列中的结点顺序最后还可用于记录 每个顶点访问的次序 */

	Vertex W;
	for (V = 0; V < Graph->Nv; V++)
	{	/* 从下标为0的顶点开始遍历 每次循环走过的边为一棵先广树 */
		if (!visited[V])
		{	/* 如果该顶点未访问过 */
			visited[V] = 1; /* 标记访问过 */
			printf("%c ", Graph->G[V].Data);
			VexQ[rear++] = V; /* 入队 */
			while (front != rear)
			{	/* 队首和队尾指针重合表示队列空 */
				for (W = FirstAdjV(Graph, V); W != -1; W = NextAdjV(Graph, V, W))
				{	/* 访问V结点的每个邻接点 */
					if (!visited[W])
					{	/* 如果该邻接点未访问过 */
						visited[W] = 1; /* 标记访问过 */
						printf("%c ", Graph->G[V].Data);
						VexQ[rear++] = W; /* 入队 */
					}
				}
				front++; /* 队首元素出队 */
			}
		}
	}
	free(VexQ); /* 释放动态空间 */
}

/* 邻接表存储 - 拓扑排序算法 */

int TopSort(LGraph Graph, Vertex TopOrder[])
{ /* 对Graph进行拓扑排序,  TopOrder[]顺序存储排序后的顶点下标 */
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	Vertex *VexQ = (Vertex *)malloc(Graph->Nv * sizeof(Vertex));
	int front = 0, rear = 0; /* 队列头尾位置标识重合 */
	/* 注意 此时的队列不是循环队列 申请了相同大小空间来存放所有结点 */

	/* 初始化Indegree[] */
	for (V = 0; V < Graph->Nv; V++)
		Indegree[V] = 0;

	/* 遍历图，得到Indegree[] */
	Vertex W;
	for (V = 0; V < Graph->Nv; V++)
		for (W = FirstAdjV(Graph, V); W != -1; W = NextAdjV(Graph, V, W))
			Indegree[W]++; /* 对有向边<V, W->AdjV>累计终点的入度 */

	/* 将所有入度为0的顶点入列 */
	for (V = 0; V < Graph->Nv; V++)
		if (Indegree[V] == 0)
		{
			VexQ[rear++] = V; /* 入队 */
		}

	/* 下面进入拓扑排序 */
	cnt = 0;
	while (front != rear)
	{
		V = VexQ[front];
		TopOrder[cnt++] = V; /* 将之存为结果序列的下一个元素 */
		front++; /* 弹出一个入度为0的顶点 */
		/* 对V的每个邻接点W删去一个入度 */
		for (W = FirstAdjV(Graph, V); W != -1; W = NextAdjV(Graph, V, W))
			if (--Indegree[W] == 0)/* 若删除V使得W->AdjV入度为0 */
				VexQ[rear++] = W;  /* 则该顶点入列 */
	}

	if (cnt != Graph->Nv)
		return 0; /* 说明图中有回路, 返回不成功标志 */
	else
		return 1;
}


int main()
{
	LGraph G = BuildGraph();
	DFS(G);
	printf("\n");
	BFS(G);
	return 0;
}