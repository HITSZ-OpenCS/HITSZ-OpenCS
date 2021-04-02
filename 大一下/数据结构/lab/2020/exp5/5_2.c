#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXINTEGER 2147483647
#define MININTEGER 0

#define MAX(a,b) ((a>b) ? a : b)
#define MIN(a,b) ((a<b) ? a : b)

//函数功能：返回快递员相邻年龄间隔的最大值
//参数说明：数组nums存储快递员年龄，numsSize代表快递员数量
int maximumGap(int* nums, int numsSize){
    //请完成此函数的功能
    return 0;
}
int main()
{
    int numsSize;  //快递员数量
    int count = 0; //测试用例编号
    int maxdiff;   //相邻年龄间隔的最大值
    freopen("5_2_input.in", "r", stdin);

    while(scanf("%d",&numsSize)!=EOF){
        count++;
        int nums[numsSize];  //快递员年龄数组
        for(int i = 0;i < numsSize;i++){
            scanf("%d",&nums[i]);
        }
        printf("====Case %d====\n",count);
        maxdiff = maximumGap(nums,numsSize);
        printf("%d\n", maxdiff);

    }
    fclose(stdin);
    //终端输入的方式
    /*while(scanf("%d",&numsSize)!=EOF){
        count++;
        int nums[numsSize];
        for(int i = 0;i < numsSize;i++){
            scanf("%d",&nums[i]);
        }
        printf("====Case %d====\n",count);
        maxdiff = maximumGap(nums,numsSize);
        printf("%d\n", maxdiff);
    }*/

    return 0;
    /*测试输入输出形式：
    输入：
    4
    1 3 5 10
    输出：
    5
    */
}
