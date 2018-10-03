#include <stdio.h>
#define CAP 1500
#define NUM 50

int w[NUM];
int v[NUM];
int p[NUM][CAP]; // 所有值为0

// c 背包容量
// n 物品数量
int knapsack(int c, int n)
{
    // 需要初始化两个条件
    // 在容量为0时,放入所有物品的价值均为0
    // 放入0个物品时,所有容量的价值均为0
    int tmp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            tmp = 0;
            if (w[i] <= j) {
                tmp = v[i] + p[i - 1][j - w[i]];
            }
            if (p[i - 1][j] > tmp) {
                tmp = p[i - 1][j];
            }
            p[i][j] = tmp;
            printf("p[%d][%d]=%d\t", i, j, tmp);
        }
        printf("\n");
    }
    return tmp;
}

int main()
{
    int n = 4, c = 5;
    w[1] = 2;
    w[2] = 1;
    w[3] = 3;
    w[4] = 2;
    v[1] = 12;
    v[2] = 10;
    v[3] = 20;
    v[4] = 15;
    int sum = knapsack(c, n);
    printf("sum=%d\n", sum);
}
