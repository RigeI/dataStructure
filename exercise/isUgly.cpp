// 写一个程序来检测一个整数是不是丑数。
//
// 丑数的定义是，只包含质因子 2, 3, 5 的正整数。比如 6, 8 就是丑数，但是 14 不是丑数因为他包含了质因子 7。
//
// 1是丑数

#include<iostream>
using namespace std;

bool isUgly(int num) 
{
    if(num==0) return false;
    else if(num==1) return true;
    else if(num==2) return true;
    else if(num==3) return true;
    else if(num==5) return true;

    if (num%2==0) return isUgly(num/2);
    else if(num%3==0) return isUgly(num/3);
    else if(num%5==0) return isUgly(num/5);
    return false;
}


int main()
{
    for(int i=0;i<20;i++)
    {
        cout<<i<<(isUgly(i)?"是":"不是")<<"丑数"<<endl;
    }
}
