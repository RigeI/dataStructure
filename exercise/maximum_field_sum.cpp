#include <stdio.h>

/* 计算begin到end范围的最大子段和 */

struct Ans {
    int sum;
    int m;
    int n;
};
Ans maximum_field_sum(int array[], int begin, int end)
{
    Ans ans;
    int mid = (begin + end) / 2; //中间位置
    ans.m = begin;
    ans.n = end;
    if (begin == end - 1) {
        ans.sum = array[mid] > 0 ? array[mid] : 0;
        return ans;
    }

    int sum, lmax, rmax;
    ;

    lmax = 0;
    sum = 0;
    for (int i = mid - 1; i >= begin; i--) {
        sum += array[i];
        if (sum > lmax) {
            lmax = sum;
            ans.m = i;
        }
    }
    lmax = lmax > 0 ? lmax : 0;

    sum = 0;
    rmax = 0;
    for (int i = mid; i < end; i++) {
        sum += array[i];
        if (sum > rmax) {
            rmax = sum;
            ans.n = i;
        }
    }
    rmax = rmax > 0 ? rmax : 0;
    sum = lmax + rmax;
    ans.sum = sum;
    if (begin < mid && sum < maximum_field_sum(array, begin, mid).sum)
        ans = maximum_field_sum(array, begin, mid);
    if (mid < end && sum < maximum_field_sum(array, mid, end).sum)
        ans = maximum_field_sum(array, mid, end);
    return ans;
}

int main()
{
    int array[] = { 1, -3, 7, 8, -4, 12, -10, 6 };
    Ans ans = maximum_field_sum(array, 0, sizeof(array) / sizeof(int));
    printf("最大字段和为%d\n", ans.sum);
    printf("范围为[%d,%d]\n", ans.m, ans.n);
    return 0;
}
