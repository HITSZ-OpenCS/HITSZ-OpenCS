#include <stdio.h>
#include <stdlib.h>

void sort(int * array, int n)
{
    /** 排序函数 */
    // Tips: 可根据自己的需求调整传入参数和函数返回值类型
    // Todo
    
}

int minTotalDistance(int * X, int * Y, int n)
{
    /** 返回最短距离之和 */
    // Tips: 可根据自己的需求调整传入参数和函数返回值类型
    // Todo
    int distance = 0; // 最短距离之和
    
    return distance;
}

int main()
{
    int n;
    
    // 文本输入方式
    freopen("5_1_input.in", "r", stdin);
    while (scanf("%d", &n) != EOF)
    {
        int distance;   // 最短距离之和
        int X[n], Y[n]; // 坐标数组,用于保存X坐标和Y坐标
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &X[i], &Y[i]);
        }
        distance = minTotalDistance(X, Y, n);
        printf("Min total distance: %d\n", distance);
    }
    fclose(stdin);
    
    /*
    // 终端输入方式
    while (scanf("%d", &n) != EOF)
    {
        int distance;   // 最短距离之和
        int X[n], Y[n]; // 坐标数组,用于保存X坐标和Y坐标
        for (int i = 0; i < n; i++)
        {
            scanf("%d%d", &X[i], &Y[i]);
        }
        distance = minTotalDistance(X, Y, n);
        printf("Min total distance: %d\n", distance);
    }
    */
    return 0;
}
