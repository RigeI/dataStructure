#include <iostream>
using namespace std;
void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

/**
 * 参数:
 * r[]为待排序数组
 * first,end为索引
 *
 * 说明:
 * 此函数将待排数组以第一个元素为标准
 * 分为两部分,小的在该元素前,大的在该元素后
 * 并返回最后该元素的位置
 * */
int Partition(int r[], int first, int end)
{
    int i = first;
    int j = end;
    while (i < j) {
        while (i < j && r[i] <= r[j])
            j--;
        if (i < j) {
            swap(r[i], r[j]);
            i++;
        }

        while (i < j && r[i] <= r[j])
            i++;
        if (i < j) {
            swap(r[i], r[j]);
            j--;
        }
    }
    return i;
}

/**
 *
 * 说明:
 * 递归调用排序算法
 *
 * */
void QuickSort(int r[], int first, int end)
{
    if (first < end) {
        int pivot = Partition(r, first, end);
        QuickSort(r, first, pivot - 1);
        QuickSort(r, pivot + 1, end);
    }
}

int main()
{
    int a[] = { 15, -4, 3, -2, 1, 55 };

    // 数组a的索引从0到5,
    QuickSort(a, 0, 5);
    for (int i = 0; i <= 5; i++) {
        cout << a[i] << '\t';
    }
    cout << endl;
}
