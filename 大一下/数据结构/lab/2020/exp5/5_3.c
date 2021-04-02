#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxS 1000

int task5_3(int array[],int n){
    //实现函数功能，返回至少的邮递员人数。
    int pNumber=0;//一共有_名邮递员

    return pNumber;
}

int main(){

    int n,i;//参与回答的邮递员数目
    int *array;
    //文件输入输出
    freopen("5_3_input.in", "r", stdin);
    //freopen("5_3_output.out","w",stdout);
    while(scanf("%d",&n)!=EOF){
        array=(int*)calloc(n,sizeof(int));
        for(i=0;i<n;i++){
            scanf("%d",&array[i]);
        }

        printf("There are at lest %d postmen.\n",task5_3(array,n));

    }
    fclose(stdin);
    //fclose(stdout);



    /*终端输入
    printf("please enter the number of the answering postman:\n");
    scanf("%d",&n);
    getchar();
    array=(int*)calloc(n,sizeof(int));
    printf("please enter their answers:\n");
    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    printf("There are at lest %d postmen.\n",task5_3(array,n));
    */
    return 0;
}
