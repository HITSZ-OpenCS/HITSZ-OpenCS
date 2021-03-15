#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1002

/**
 Maze矩阵用于表示迷宫
 mark矩阵用于记录已到达的位置，初值为0，达到位置(i,j)后置mark[i][j] = 1
 dir矩阵表示往上下左右四个方向移动的增量
 */
/**
 * path矩阵用于记录路径
 * 用在栈中可记录栈弹出的元素，即找到的路径
 * 用在队列中可记录队列遍历过程中，当前点为之前点通过i方向抵达，i为dir矩阵中的0-3
 */ 
char Maze[MAXN][MAXN];
int mark[MAXN][MAXN];
int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int path[MAXN][MAXN];


int LegalPosition(int x,int y,int rows,int cols){
    /* 判断位置(x,y)是否可以行走通过 **/
    return 1;//可删除
}

typedef struct StackNode{
    /* 栈中存储的节点 **/
    int x;
    int y;
    int dirCount;
    struct StackNode* next;
    /* 可自由添加需要用的变量 **/
}StackNode;

typedef struct LinkStack{
    /* 栈 **/
    StackNode *top;
    int size;
    /* 可自由添加需要用的变量 **/
}LinkStack;


LinkStack* InitStack(){
    /* 初始化栈 **/
    LinkStack* linkStack = (LinkStack*)malloc(sizeof(LinkStack));
    linkStack->top = NULL;
    linkStack->size = 0;
    return linkStack;
}

int StackEmpty(LinkStack *linkStack){
    /* 判断栈是否为空，为空返回0，非空返回1 **/
    return (linkStack->size == 0);
}

StackNode* InitStackNode(int x,int y,int dirCount){
    /* 根据x与y的坐标建立栈中一个节点 **/
    
    //tips:如若打算实现该函数
    //malloc时记得转为结构体指针
    //别忘记对新建节点中的next默认值的思考
    return NULL;//可删除
    /* 可自由选择是否实现该函数 **/
}

int Push(LinkStack* linkStack,StackNode* stackNode){
    /** 将一个节点压入栈 */
    //Todo
    return 1;//可删除
}

int Pop(LinkStack* linkStack,int* popX,int* popY,int* popDirCount){
    /** 将一个节点弹出栈 */
    return 1;//可删除
}

int GetTop(LinkStack *linkStack,int* topX,int* topY){
    /**  若栈不为空，用topX、topY返回栈顶元素值*/
    return 1;//可删除
    /* 可自由选择是否实现该函数 **/
}

int StackLength(LinkStack* linkStack){
    /** 返回栈的长度 */
    return 1;//可删除
}

void printStackSteps(int rows,int cols,LinkStack* linkStack){
    /** 输出栈求解迷宫经过的路径*/
    memset(path, 0, sizeof(path)); //path矩阵记录栈弹出的元素，即找到的路径
    StackNode* stackNode = linkStack->top;
    //Tips:遍历栈得到求解过程，即经过的路径
    //Todo
}

void SolveByStack(int rows,int cols){
    /** 运用栈求解迷宫路径 */
    LinkStack *linkStack = InitStack();
    memset(mark, 0, sizeof(mark));
    int startX,startY;  //起点坐标
    int destX,destY;    //终点坐标
    int dirCount;       //已探索的方向
    int find = 0;       //是否已达到出口，找到路径
    /** 找到起点与终点 */
    
    //Todo
    
    /**
     * 注：实现思路仅供参考，实现方法不唯一
     从起点开始对四个方向的位置逐个进行试探，如若某个位置未访问过且可以通行，将新位置入栈，当某个位置四个方向走不通时回退到上一个位置。
     找到终点或者访问所有位置后退出。
     */

    //Todo
    
    /**
     根据找到与否输出对应的结果
     */
    if(find){
        printStackSteps(rows, cols,linkStack);
    }else{
        printf("Impossible!\n");
    }
}


typedef struct QueueNode{
    /** 队列中存储的节点 */
    int x;
    int y;
    struct QueueNode* next;
    /** 可自由添加需要的变量 */
}QueueNode;

typedef struct Queue{
    /** 队列 */
    QueueNode *front;
    QueueNode *rear;
    int size;
    /** 可自由添加需要的变量 */
}LinkQueue;

LinkQueue* InitQueue(){
    /** 初始化队列 */    LinkQueue* linkQueue = (LinkQueue*)malloc(sizeof(LinkQueue));
    linkQueue->front = linkQueue->rear = (QueueNode*)malloc(sizeof(QueueNode));
    linkQueue->front->next = NULL;
    linkQueue->size = 0;
    return linkQueue;
}

int QueueEmpty(LinkQueue* linkQueue){
    /** 判断队列是否为空 */
    return(linkQueue->front == linkQueue->rear);
}

QueueNode* InitQueueNode(int x,int y){
    /** 根据给定的坐标x与y，初始化队列节点 */
    return NULL;//可删除
    /** 可自由选择是否实现该函数*/
}

int EnQueue(LinkQueue* linkQueue,QueueNode* queueNode){
    /** 入队 */
    return 1;//可删除
}

int DeQueue(LinkQueue* linkQueue,int* DeQueueX,int* DeQueueY){
    /** 出队 */
    return 1;//可删除
}

void printQueueSteps(int rows,int cols){
    /** 找到迷宫出口 */
    
    // Todo
    
    /** 
     从迷宫出口开始，利用path矩阵记录的信息，
     各位置往其前驱位置回溯，直到回到入口，
     记录完整路径，并将路径按要求格式输出 
     */
    
    // Todo
}

void solveByQueue(int rows,int cols){
    /** 运用队列对迷宫进行试探 */
    LinkQueue* linkQueue = InitQueue();
    memset(mark,0,sizeof(mark));
    int find = 0;       // 记录是否达到出口，在迷宫中找到路径
    int endX,endY;      // 记录出口坐标
    /** 找到起点，从起点开始试探，将其方向与位置入队*/
    
    // Todo
    
    /**
     当队列中仍有可访问的位置时，从该位置四个方向中找到仍为访问且可通行的位置。
     将该位置入队，用path矩阵记录其与前驱位置的相对方向，即dir数组中的0-3
     */
    
    // Todo
    
    /**
     根据是否找到路径输出对应的内容
     */
    if(find){
    printQueueSteps(rows,cols);
    }else{
        printf("Impossible!\n");
    }
}

int main(){
    
    int count = 0;
    int rows,cols;
    
    /** 从文件"Maze.in"中读入 */
    freopen("Maze.in", "r", stdin);
    while(scanf("%d %d",&rows,&cols)!=EOF){
        count++;
        char ch;
        for(int i =0; i < rows;i++){
            for(int j = 0; j < cols;j++){
                while((ch = getchar())&&ch != '=' && ch!='0' && ch != '!' && ch != '@');
                Maze[i][j] = ch;
            }
        }
        
        printf("=== Case %d ===\n",count);
        printf("The size of Maze : %d by %d\n",rows,cols);
        printf("StackSolution:\n");//为了便于区分
        SolveByStack(rows, cols);
        printf("QueueSolution:\n");//为了便于区分
        solveByQueue(rows, cols);
    }
    fclose(stdin);
    
    return 0;
}
