//写一个算法来判断一个数是不是"快乐数"。

//一个数是不是快乐是这么定义的：对于一个正整数，每一次将该数替换为他每个位置上的数字的平方和，
//然后重复这个过程直到这个数变为1，或是无限循环但始终变不到1。
//如果可以变为1，那么这个数就是快乐数。

//哈哈哈哈哈哈这题好玩

#include<iostream>
#include<cmath>
using namespace std;

bool isHappy(int n) 
{
    int temp=n;
    int sum;

    while(1)
    { 
        sum=0;
        while(temp!=0)
        {
            sum+=pow(temp%10,2);
            temp=temp/10;
        }
        if(sum==1) return true;
        if(sum==0) return false;
        if(sum==4) return false;
        temp=sum;
    }
}


int main()
{
    for(int i=0;i<10000;i++)
    {
        cout<<i<<(isHappy(i)?"是":"不是")<<"欢乐数"<<endl;
    }
}
