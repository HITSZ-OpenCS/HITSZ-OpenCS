#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 10020
#define maxm 200020
//图的定义使用链式前向星方式构建图
//当然你也可以用自己的方法构建图,如临接矩阵或者临接表
#define INF 2147483647
int ans[maxn];
struct Edge
{
    int start, end, weight;

    //该边，同一起点的上一边在edgs中存储的下标。以next作为链式寻找同一起点的所有边
    int next;
};

struct Graph
{
    struct Edge edegs[maxm];

    //head[i] 记录的是以i为起点的边集中第一条边在edges中的index,
    int head[maxn];

    //当前第几条边
    int tot;
};

struct Graph *init_graph()
{
    struct Graph *new_grapth = (struct Graph *)malloc(sizeof(struct Graph));
    new_grapth->tot = 0;
    memset(new_grapth->head, -1, sizeof(new_grapth->head));
    return new_grapth;
}

void add_edge(int start, int end, int weight, struct Graph *graph)
{
    graph->edegs[++graph->tot].start = start;
    graph->edegs[graph->tot].end = end;
    graph->edegs[graph->tot].weight = weight;

    //链式前向星存储，每加一条边的时候，同一起点的边用next来做链式存储
    graph->edegs[graph->tot].next = graph->head[start];
    graph->head[start] = graph->tot;
}

void visit_graph(int n, struct Graph *graph)
{

    for (int i = 1; i <= n; i++) //n个起点
    {
        printf("start with %d\n", i);
        for (int j = graph->head[i]; j != -1; j = graph->edegs[j].next) //遍历以i为起点的边
        {
            printf("edgs i is start:%d,end:%d,weight is:%d\n", graph->edegs[j].start, graph->edegs[j].end, graph->edegs[j].weight);
        }
    }
    //debug 函数，提供这种存储方式的遍历过程，方便同学们debug
    for (int i = 1; i <= n; i++) //n个起点
    {
        printf("start with %d\n", i);
        for (int j = graph->head[i]; j != -1; j = graph->edegs[j].next) //遍历以i为起点的边
        {
            printf("edgs i is start:%d,end:%d,weight is:%d\n", graph->edegs[j].start, graph->edegs[j].end, graph->edegs[j].weight);
        }
    }
    
    //遍历图中同一起点所有边的方法
    
    // int  index;
    // index = graph->head[startpoint];
    // while (index!=-1)
    // {
    //     /* code */
    //     //do something
        
    //     index = graph->edegs[index].next;
    // }
    
    
}


void forward_propagation(int n_total, int n_input, int n_output, int *input_array, struct Graph *graph)
{
    //最终结果存储到全局变量ans中
}

int main()
{

    int input[maxn];
    int n_total, m_total, n_input, n_output;

    //文件输入的方式
    freopen("4_2_input.in", "r", stdin);
    while (scanf("%d%d%d%d", &n_total, &m_total, &n_input, &n_output) != EOF)
    {

        struct Graph *g = init_graph();
        int x, y, z;
        int start, end, weight;

        for (int i = 1; i <= m_total; i++)
        {
            scanf("%d%d%d", &start, &end, &weight);
            add_edge(start, end, weight, g);
        }
        for (int i = 1; i <= n_input; i++)
        {
            scanf("%d", &input[i]);
        }
        //结果保存在全局变量ans数组中
        forward_propagation(n_total, n_input, n_output, input, g);

        for (int i = n_total - n_output + 1; i <= n_total; i++)
        {
            printf(i < n_total ? "%d " : "%d\n", ans[i]);
        }
    }
    fclose(stdin);

    /*
    //终端输入的方式进行io
    while (scanf("%d%d%d%d", &n_total, &m_total, &n_input, &n_output) != EOF)
    {

        struct Graph *g = init_graph();
        int x, y, z;
        int start, end, weight;

        for (int i = 1; i <= m_total; i++)
        {
            scanf("%d%d%d", &start, &end, &weight);
            add_edge(start, end, weight, g);
        }
        for (int i = 1; i <= n_input; i++)
        {
            scanf("%d", &input[i]);
        }
        //结果保存在全局变量ans数组中
        forward_propagation(n_total, n_input, n_output, input, g);

        for (int i = n_total - n_output + 1; i <= n_total; i++)
        {
            printf(i < n_total ? "%d " : "%d\n", ans[i]);
        }
    }
    */
/*
输入输出样例
输入：
8 10 2 1
1 3 2
1 4 1
2 4 3
2 5 3
3 6 4
4 6 2
4 7 2
5 7 7
6 8 2
7 8 1
5 10
输出：
500
*/
    return 0;
}
