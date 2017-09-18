#include<stdio.h>
#define max(a,b,c) ((a)>(b)?(a):(b))>(c)?((a)>(b)?(a):(b)):(c)
/**
 *
 * 最大字段和的分治法求解
 * 设全段范围为[left, right),所要寻找的最大子段范围为[m,n]
 * 在全段范围内选取 mid = (letf+right)/2
 * 最大字段和范围有三种情况
 *  1. 在 mid 左侧
 *  2. 在 mid 右侧
 *  3. 包含 mid
 * 
 * 实际运算的是第三种情况,其他两种情况总会递归成第三种情况进行返回
 * 所以程序的重点是,如何确定第三种情况的范围
 *
 * 分别求这三种情况的的最大值
 * 三种情况的最大值为最大字段和
 * */

int m,n;
int maximum_field_sum(int array[], int left, int right){
    
    int left_sum=0, right_sum=0 ,mid_sum=0;
    int mid = (left+right)/2;
    
    mid_sum = array[mid];
    for(int i=mid-1; i>=left; i--){
        if(mid_sum+array[i] > mid_sum){m=i;}
        mid_sum += array[i];
    }

    for(int i=mid+1;i<right;i++){
        if(mid_sum+array[i] > mid_sum){n=i;}
        mid_sum += array[i];
    }

    if(left<mid)  left_sum = maximum_field_sum(array,left,mid);
    if(mid+1<right) right_sum = maximum_field_sum(array,mid+1,right);
    
    return max(left_sum,right_sum,mid_sum);
}

int main(){
    int array[]={-3,-1,2,100,-4,-5,3,20};
    printf("最大字段和为%d\n",maximum_field_sum(array,0,sizeof(array)/sizeof(int)));
    printf("最大字段和范围为:[%d,%d]\n",m,n);
    return 0;
}

