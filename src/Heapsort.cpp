#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}
/**
 * 说明:
 * 大根堆,即跟必须为最大的节点
 * 
 * 应用条件:
 * 除了被筛选节点和其左右儿子,该节点子树均为大根堆
 *
 * 参数:
 * r[] 为待调整数组
 * k 为被筛选的节点,从k,2k,2k+1中寻找最大值放在k的位置
 * m 为需要进行筛选的二叉堆的节点个数
 * */
void Sift(int r[], int k, int m)
{

    int i = k;
    int j = 2 * i;
    while (j <= m) {
        // j 定位到值最大的儿子
        if (j + 1 <= m && r[j - 1] < r[j])
            j++;

        // j 位置的值比 i 位置的小
        // 为大根堆,不需要调整
        if (r[j - 1] < r[i - 1])
            break;

        // 否则交换位置
        else {
            swap(r[j - 1], r[i - 1]);

            // 交换位置导致原本子树的大根堆被破坏
            // 所以要对该子树进行调整
            i = j;
            j = 2 * i;
        }
    }
}

/**
 * 说明:
 * 堆排序
 *
 * 参数:
 * r[] 为被排序数组,n为数组元素个数
 * */

void HeapSort(int r[], int n)
{
    for (int i = n / 2; i >= 1; i--) {
        // 由于Sift的应用条件是,i节点的子树必须为大根堆,
        // 所以从最后一个树开始,倒序至根节点
        // 循环结束后,跟节点为最大值
        Sift(r, i, n);
    }

    for (int i = 1; i < n; i++) {
        // 交换第一个节点和最后一个节点
        swap(r[0], r[n - i]);
        // 此时最后一个节点为最大值
        // 开始循环后
        // 待排序的最大值总被放到待排序数组的最后

        // 每次只有根节点不是最大堆,所以交换位置后只需从跟节点开始调整一次
        Sift(r, 1, n - i);
    }
}

int main()
{
    int t = 8;
    int a[] = { 9, -1, 1, 4, 2, 0, -2, 10 };
    HeapSort(a, t);
    for (int i = 0; i < t; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
