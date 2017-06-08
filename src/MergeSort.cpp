#include<iostream>
using namespace std;

// 将数组a拆分成start到mid 和 mid+1到end 两部分
// 这两部分均有序
// 将这两部分合并成一个有序的数组
void merge(int a[],int start,int mid,int end)
{
    // 创建临时空间,大小为数组a的大小
    int *temp = new int[end-start+1];
    // i 为前半个数组的索引
    int i=start;
    // j 为后半个数组的索引
    int j=mid+1;
    // k为临时空间temp的索引
    int k=0;

    // 3个循环为具体合并过程
    while(i<=mid && j<=end)
    {
        if(a[i]<=a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=mid)
        temp[k++]=a[i++];
    while(j<=end)
        temp[k++]=a[j++];
    
    // 把临时空间的内容放回到a数组
    for(i=0;i<k;i++)
        a[start+i]=temp[i];
    
    // 删除临时空间
    delete []temp;
}



void merge_sort(int a[],int start,int end)
{
    // 空数组直接返回
    // start>end 是错误的输入
    // start=end 表示数组中只有一个元素需要排序,
    // 是递归退出的条件
    if(a==NULL || start>=end)
        return;
    
    // 分割数组,如果数组待排序个数大于1就继续分割
    // 只有一个元素可以视为有序
    int mid=(end+start)/2;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);

    // 将有序数组进行合并
    merge(a,start,mid,end);
}

// 输出数组,不属于归并排序,可忽略
void print_array(int a[],int start,int end)
{
    for(int i=start;i<=end;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int a[]={-20,2,1,6,3,-1,2,-10};
    print_array(a,0,7);
    merge_sort(a,0,7);
    print_array(a,0,7);
}

