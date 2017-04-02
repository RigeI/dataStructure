// 写一个程序来检测一个整数是不是丑数。
//
// 丑数的定义是，只包含质因子 2, 3, 5 的正整数。比如 6, 8 就是丑数，但是 14 不是丑数因为他包含了质因子 7。
//
// 1是丑数

#include<iostream>
using namespace std;


// 给出程序终止条件
// 如果num为 0 1 2 3 5则终止
// 0没有质引子 为假
// 1是题目中给出的　必为真
// 只有2 3 5　才会真中用到递归
// 如果一个数是2 3 5的倍数
// 则求其与2 3 5的商
// 并判断商是否为2 3 5的倍数
// 若商不是,则为假
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
