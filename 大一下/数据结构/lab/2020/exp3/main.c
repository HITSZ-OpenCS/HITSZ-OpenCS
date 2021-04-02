
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int FLAG = 0;  //标识是否能由后序中序建立二叉树

typedef struct Node
{
    char data;
    struct Node *lchild, *rchild;
} TreeNode, *BiTree; //定义树节点的结构体

BiTree createBiTree()//建立二叉树
{
    char data;

    return bt;

}
void preOrderTraverse(BiTree p)//函数功能：前序遍历
{
    return;

}
void inOrderTraverse(BiTree p)//函数功能：中序遍历
{
    return;

}
void postOrderTraverse(BiTree p)//函数功能：后序遍历
{
    return;

}
BiTree* PostInCreate(char post[],int s1,int e1,char in[],int s2,int e2)
{
//函数功能：根据后序与中序序列构造二叉树，并返回根节点
//参数说明：post[]为后序序列，s1,e1为后序的第一和最后一个节点下标，in[]为中序序列，s2,e2为中序的第一和最后一个节点下标。

    return NULL; //可删除
}
int countLeafSum(BiTree root)
{
//函数功能：计算叶子节点数

    return 0; //可删除
}
int countHeight(BiTree root)
{
//函数功能：计算二叉树的高度,二叉树的高度是其左子树或右子树中较高的一个子树的高度再加1

    return 0;//可删除
}
void getwidth(BiTree root,int *count,int counter)
{
//函数功能：得到一个二叉树每层的节点数目。
//参数说明：counter记录层数,数组count记录每一层的节点数

}
int isEquivalent(BiTree bt1,BiTree bt2)
{
   //函数功能：判断两树是否等价
    //参数说明：bt1:第一个二叉树，bt2:第二个二叉树

}
void task1(BiTree bt){
    //任务1：实现二叉树先序、中序、后序遍历
    printf("start task (1) Create Tree in PreOrder\n");
    printf("preOrderTraverse\n");
    preOrderTraverse(bt);
    printf("\n");
    printf("inOrderTraverse\n");
    inOrderTraverse(bt);
    printf("\n");
    printf("postOrderTraverse\n");
    postOrderTraverse(bt);
    printf("\n");
}

void task2(BiTree *bt){
    //任务2：请利用PostInCreate函数根据后序与中序序列构造二叉树
    //使用函数：PostInCreate
    printf("start task (2) Input the postOrder and inOrder Sequence ,Then build the tree\n");
    char post[20];  //后序序列
    char in[20];    //中序序列
    int postlen;    //后序序列长度
    int inlen;      //中序序列长度
    printf("please input the postorder sequence\n");
    scanf("%s",post);
    printf("please input the inorder sequence\n");
    scanf("%s",in);
    //请完善函数




    printf("preOrderTraverse:\n");
    preOrderTraverse(*bt);
    printf("\n");

}

void task3(BiTree bt){
    //任务3：计算二叉树的叶节点个数和宽度。（注：计算宽度所需的函数是出题者所设计，若你能有更好的办法得到宽度，自己设计亦可。）
    //使用函数：countLeafSum、countHeight、getwidth
    printf("start task (3) ------------------------------\n");
    int height;     //树的高度
    int maxwidth=-1;     //树的宽度，预设为-1。（宽度：二叉树每一层节点数的最大值）
    printf("The number of leaf nodes of the tree is:\n");
    printf("%d\n",countLeafSum(bt));
    //请完善函数



    printf("The widht of the tree is:\n");
    printf("%d\n",maxwidth);
}


void task4(BiTree bt1,BiTree bt2){
    //任务4：判断两个二叉树是否等价
    //使用函数：isEquivalent
    printf("start task (4) Are two Bitrees equivalent?\n");
    printf("%d\n",isEquivalent(bt1,bt2));

}
int main()
{
    BiTree bt1,bt2;
    printf("Create Tree1 in PreOrder\n");
    bt1=createBiTree();

    task1(bt1);
    task2(&bt2);
    task3(bt2);
    //task4(bt1,bt2);

    return 0;
}
