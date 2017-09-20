#include<stdio.h>

/* 计算begin到end范围的最大子段和 */
int maximum_field_sum(int array[], int begin, int end){
    if(begin==end-1) return array[begin]>0?array[begin]:0;
    int mid = (begin+end)/2; //中间位置
    int sum,lmax,rmax;;

    lmax=0;sum=0;
    for(int i=mid-1;i>=begin;i--){
        sum+=array[i];
        if(sum>lmax) {lmax = sum;}
    }    
    lmax = lmax>0?lmax:0;

    sum = 0; rmax=0;
    for(int i=mid;i<end;i++){
        sum+=array[i];
        if(sum>rmax) {rmax = sum;}
    }
    rmax = rmax>0?rmax:0;

    sum = lmax+rmax;
    if(begin<mid && sum<maximum_field_sum(array,begin,mid)) sum = maximum_field_sum(array,begin,mid);
    if(mid<end && sum<maximum_field_sum(array,mid,end)) sum = maximum_field_sum(array,mid,end);
    return sum;
}

int main(){
    int array[]={1,-3,7,8,-4,12,-10,6};
    printf("最大字段和为%d\n",maximum_field_sum(array,0,sizeof(array)/sizeof(int)));
    return 0;
}

