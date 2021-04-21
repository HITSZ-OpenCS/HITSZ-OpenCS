/* 图的邻接矩阵表示法 默认为无向带权图net */
#include<stdio.h>
#include<stdlib.h>

#define MaxVertexNum 100    /* 最大顶点数设为100 */
#define INFINITY 65535      /* ∞设为双字节无符号整数的最大值65535 */
typedef int Vertex;         /* 用顶点下标表示顶点,为整型 从0开始 */
typedef int WeightType;     /* 边的权值设为整型 */
typedef char DataType;      /* 顶点存储的数据类型设为字符型 */
							/* 正常还要定义枚举GraphKind枚举类型 但操作复杂省略 */
/* 边的定义 */
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;      /* 有向边<V1, V2> */
	WeightType Weight;  /* 权重 若有更多信息 用指针指向info结构体 */
						/* 若为无权图 则这项省略 邻接也可改成01数组 */
};
typedef PtrToENode Edge;

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode {
	int Nv;  /* 顶点数 */
	int Ne;  /* 边数   */
	WeightType G[MaxVertexNum][MaxVertexNum]; /* 邻接矩阵 */
											  /*有info结构体的图就改成*info二维数组 */
	DataType Data[MaxVertexNum]; /* 存顶点的数据 */
								 /* 注意：很多情况下，顶点无数据，此时Data[]可以不用出现 */
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型 */


/* 初始化一个有VertexNum个顶点但没有边的图 */
MGraph CreateGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;

	Graph = (MGraph)malloc(sizeof(struct GNode)); /* 建立图 */
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	/* 初始化邻接矩阵 */
	/* 注意：这里默认顶点编号从0开始，到（Nv - 1）*/
	for (V = 0; V < Graph->Nv; V++)
		for (W = 0; W < Graph->Nv; W++)
			Graph->G[V][W] = INFINITY; /* 所有边初始值默认为∞ */

	return Graph;
}

/* 插入单个边 需要传入Edge结构体指针 */
void InsertEdge(MGraph Graph, Edge E)
{
	/* 插入边 <V1, V2> */
	Graph->G[E->V1][E->V2] = E->Weight;
	/* 若是无向图，还要插入边<V2, V1> */
//	Graph->G[E->V2][E->V1] = E->Weight;
}

/* 创建图并赋值 */
MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;

	printf("Input the vextex num: ");
	scanf("%d", &Nv);   /* 读入顶点个数 */
	Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

	printf("Input the edge num: ");
	scanf("%d", &(Graph->Ne));   /* 读入边数 */
	if (Graph->Ne != 0)
	{	 /* 如果有边 */
		E = (Edge)malloc(sizeof(struct ENode)); /* 建立边结点 */
												/* 读入边，格式为"起点 终点 权重"，插入邻接矩阵 */
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
		scanf(" %c", &(Graph->Data[V]));
	}

	return Graph;
}

/* 返回图G中与顶点V邻接的第一个邻接点下标 -1为没有邻接点 */
Vertex FirstAdjV(MGraph Graph, Vertex V)
{
	Vertex W = 0;
	while ((W < Graph->Nv) && (Graph->G[V][W] == INFINITY))
		W++; /* 循环直到找到第一个 或 遍历完所有顶点都无邻接 */
	if (W < Graph->Nv)
		return W; /* 找到 */
	else
		return -1; /* 没找到 */
}

/* 返回图G中与顶点V邻接点中W的下一个邻接点 -1为无下一个邻接点 */
Vertex NextAdjV(MGraph Graph, Vertex V, Vertex W)
{
	W = W + 1; /* 从W后一个顶点下标开始找 此时已默认W正确 */
	while ((W < Graph->Nv) && (Graph->G[V][W] == INFINITY))
		W++; /* 循环直到找到下一个 或 遍历完所有顶点都无邻接 */
	if (W < Graph->Nv)
		return W; /* 找到 */
	else
		return -1; /* 没找到 */
}

/* 深度优先搜索递归函数 */
void  DFStravel(MGraph Graph, Vertex V, int* visited)
{
	visited[V] = 1; /* 标记访问过 */
	printf("%c ", Graph->Data[V]);

	Vertex W;
	for (W = FirstAdjV(Graph, V); W != -1; W = NextAdjV(Graph, V, W))
	{	/* 该顶点的所有邻接点都要遍历 */
		if (!visited[W]) /* 如果该邻接点未访问过 */
			DFStravel(Graph, W, visited); /* 则递归调用 至最深处 */
	}
}

/* 深度优先搜索主算法 */
void DFS(MGraph Graph)
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
void BFS(MGraph Graph)
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
			printf("%c ", Graph->Data[V]);
			VexQ[rear++] = V; /* 入队 */
			while (front != rear)
			{	/* 队首和队尾指针重合表示队列空 */
				for (W = FirstAdjV(Graph, V); W != -1; W = NextAdjV(Graph, V, W))
				{	/* 访问V结点的每个邻接点 */
					if (!visited[W])
					{	/* 如果该邻接点未访问过 */
						visited[W] = 1; /* 标记访问过 */
						printf("%c ", Graph->Data[W]);
						VexQ[rear++] = W; /* 入队 */
					}
				}
				front++; /* 队首元素出队 */
			}
		}
	}
	free(VexQ); /* 释放动态空间 */
}

/* 最小生成树 Prim算法 */
void Prim(MGraph Graph)
{
	int i, j, k;
	WeightType minCost; /* 辅助量 用于在lowCost数组中求最小值 */
	WeightType lowCost[MaxVertexNum]; /* 存储到外界所有顶点的最短距离 */
	Vertex closeV[MaxVertexNum]; /* 最短距离对应的最近结点 */

	lowCost[0] = -1; /* 先将下标为0的顶点纳入 */
	for (i = 1; i < Graph->Nv; i++)
	{	/* 初始化 */
		lowCost[i] = Graph->G[0][i]; /* 将第一行权重存入 */
		closeV[i] = 0; /* 最近结点都设为下标0的结点 */
	}

	printf("MST by Prim: ");
	for (i = 1; i < Graph->Nv; i++)
	{	/* 进行(Nv - 1)次遍历 输出对应的树边 */
		minCost = INFINITY; /* 将最短距离初值设为∞ */
		for (j = 1; j < Graph->Nv; j++)
		{	/* 找最短距离 */
			if (lowCost[j] < minCost && lowCost[j] != -1)
			{	/* 找最短距离时应排除已经纳入的顶点 */
				minCost = lowCost[j];
				k = j; /* 标记为k 下标k即为当前可达最近的外顶点 */
			}
		}
		printf("(%d,%d)%d ", closeV[k], k, lowCost[k]);
		lowCost[k] = -1; /* 将k纳入 */
		for (j = 1; j < Graph->Nv; j++)
		{	/* 更新最短距离 */
			if (Graph->G[k][j] < lowCost[j])
			{	/* 已经纳入的顶点置为-1 因此不会被考虑 */
				lowCost[j] = Graph->G[k][j];
				closeV[j] = k;
			}
		}
	}
}

/* 有向图单源最短路径 Dijkstra算法 默认可以遍历 */
void Dijkstra(MGraph Graph)
{
	int i, j, k;
	int sum; /* 存储新结点加入后可能带来的路径更新 */
	int inVex[MaxVertexNum]; /* 标记每个顶点是否已经在路径中 取0/1 */
	WeightType Di[MaxVertexNum]; /* 当前可达路径 */
	WeightType minDi; /* 当前可达路径中的最短路径 */

	inVex[0] = 1; /* 先将下标为0的顶点纳入 */
	for (i = 1; i < Graph->Nv; i++)
	{	/* 初始化 */
		Di[i] = Graph->G[0][i]; /* 将第一行权重存入 */
		inVex[i] = 0; /* 不在路径中的结点都标记为0 */
	}

	for (i = 1; i < Graph->Nv; i++)
	{	/* 进行(Nv - 1)次循环 每次纳入一个顶点 */
		minDi = INFINITY; /* 将最短可达路径初值设为∞ */
		for (j = 1; j < Graph->Nv; j++)
		{	/* 找到最短可达路径 */
			if (!inVex[j] && Di[j] < minDi)
			{	/* 找最短可达距离时应排除已经纳入的顶点 */
				minDi = Di[j];
				k = j; /* 标记为k 下标k即为当前可达最近的外顶点 */
			}
		}
		/* 如果图不完全连通 遍历时会找不到k k就会取上一次的值 最后输出中会有65535 */
		/* 如果连上一次都没有 如2顶点0边 则会bug 因此默认可遍历 */
		inVex[k] = 1; /* 将k纳入 */
		for (j = 1; j < Graph->Nv; j++)
		{	/* 更新当前可达路径 */
			if (!inVex[j])
			{	/* 已纳入的顶点不考虑 */
				sum = Di[k] + Graph->G[k][j]; /* 从k路径到外顶点的嫌疑路径 */
				if (sum < Di[j])
				{	/* 嫌疑路径更短 更新为新可达路径 */
					Di[j] = sum;
				}
			}
		}
	}
	printf("Shortest path from v0 by Dijkstra: ");
	for (i = 1; i < Graph->Nv; i++)
	{	/* 输出遍历后的可达路径 此时每个点都是最优解 */
		printf("%d ", Di[i]);
	}
}

/* 有向图单源最短路径 Dijkstra算法 输出经过的路径踪迹 */
void DisplayPath(Vertex *path, Vertex v)
{
	if (path[v] != 0)
	{	/* 当路径中还有其他踪迹 递归调用函数 */
		DisplayPath(path, path[v]);
		printf("v%d->", path[v]);
	}
}

void DijkstraWithPath(MGraph Graph)
{
	int i, j, k;
	int sum;
	int inVex[MaxVertexNum];
	WeightType Di[MaxVertexNum];
	WeightType minDi;
	Vertex path[MaxVertexNum]; /* 存储到达该结点的路径踪迹 */

	inVex[0] = 1;
	for (i = 1; i < Graph->Nv; i++)
	{	/* 初始化 */
		Di[i] = Graph->G[0][i];
		inVex[i] = 0;
		path[i] = 0; /* 默认路径踪迹由下标为0的顶点出发 */
	}

	for (i = 1; i < Graph->Nv; i++)
	{	/* 进行(Nv - 1)次循环 每次纳入一个顶点 */
		minDi = INFINITY;
		for (j = 1; j < Graph->Nv; j++)
		{
			if (!inVex[j] && Di[j] < minDi)
			{
				minDi = Di[j];
				k = j;
			}
		}
		inVex[k] = 1;
		for (j = 1; j < Graph->Nv; j++)
		{	/* 更新当前可达路径 */
			if (!inVex[j])
			{
				sum = Di[k] + Graph->G[k][j];
				if (sum < Di[j])
				{
					Di[j] = sum;
					path[j] = k; /* 到达j的踪迹更新为到达k的踪迹 加上路径（k,j) */
				}
			}
		}
	}
	printf("Shortest path from v0 by Dijkstra: \n");
	for (i = 1; i < Graph->Nv; i++)
	{	/* 输出遍历后的可达路径 此时每个点都是最优解 */
		printf("To v%d :", i);
		DisplayPath(path, i);
		printf("v%d ", i); /* 输出路径踪迹 */
		printf("Sum:%d\n", Di[i]); /* 输出路径长度 */
	}
}

/* 多源最短路算法 Floyd算法 O(V^3) 对稠密图友好 */
int Floyd(MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum])
{
	Vertex i, j, k;

	/* 初始化 直接存入权重矩阵 */
	for (i = 0; i < Graph->Nv; i++)
		for (j = 0; j < Graph->Nv; j++) {
			D[i][j] = Graph->G[i][j];
			path[i][j] = -1;
		}

	for (k = 0; k < Graph->Nv; k++)
		for (i = 0; i < Graph->Nv; i++)
			for (j = 0; j < Graph->Nv; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					if (i == j && D[i][j] < 0) /* 若发现负值圈 */
						return 0; /* 不能正确解决，返回错误标记 */
					/* 有负权边可以 但不能有负权环 */
					path[i][j] = k; /* 输出路径时递归调用即可 为-1时表示直达 */
				}
	return 1; /* 算法执行完毕，返回正确标记 */
}

int main()
{
	MGraph G = BuildGraph();
	Dijkstra(G);
	printf("\n");

	return 0;
}