#include<stdio.h>

int max_sum(int array[], int n, int &besti, int &bestj){
    int begin=0;
    int sum=0;
    int b=0; // 从大于0的某个数(begin)开始加到当前位置(i)的和

    for(int i=0;i<n;i++){
        if(b>0){ b+=array[i]; }
        else{ b=array[i]; begin=i;}
        if(b>sum){ sum=b; besti=begin; bestj=i;}
    }
    return sum;
}

int main(){
    int array[]={100,-3,7,8,-4,12,-10,100};
    int besti,bestj;
    int sum = max_sum(array,sizeof(array)/sizeof(int),besti,bestj);
    printf("sum=%d\n",sum);
    printf("范围[%d,%d]\n",besti,bestj);
}
