#include<stdio.h>
#include<stack>
#define MAX 100

int help[MAX]; // help[i],记录到array[i]为止的,比array[i]小的那个最大的数的值
int help2[MAX]; // 第二个辅助数组,记录上述对应值的位置
std::stack<int> ans; // 最优解数组
int longest_increase_sequence(int array[],int n){
    help[0]=1;
    help2[0]=-1;
    for(int i=1;i<n;i++){
        help[i]=0;
        for(int j=i-1;j>=0;j--){
            if(array[j]<array[i]&&help[j]>help[i]){
                help[i]=help[j];
                help2[i]=j;
            }
        }
        help[i]++;
    }

    int max=help[0];
    int tmp=0;
    for(int i=0;i<n;i++){
        if(help[i]>max){
            tmp = i;
            max = help[i];
        }
    }
    
    while(tmp>=0){
        //printf("tmp=%d\n",tmp);
        ans.push(tmp);
        tmp = help2[tmp];
    }
    return max;
}

int main(){
    int array[]={-5,1,2,3,4,-3,-2,5,-1,-6,6,7,8,0,1,2,3};
    int lis = longest_increase_sequence(array,sizeof(array)/sizeof(int));
    printf("%d\n",lis);
    while(ans.size()){
        printf("array[%d]=%d\n",ans.top(),array[ans.top()]);
        ans.pop();
    }
    
    for(unsigned int i=0;i<sizeof(array)/sizeof(int);i++){
    //    printf("help[%d]=%d\t",i,help[i]);
    //    printf("help2[%d]=%d\t",i,help2[i]);
    //    printf("%d ",array[i]);
    }
    
}
