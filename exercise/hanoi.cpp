#include <iostream>
using namespace std;
void hanoi(int n, char a, char b, char c)
{
    if (n >= 1) {
        hanoi(n - 1, a, c, b);
        cout << a << "->" << c << endl;
        hanoi(n - 1, b, a, c);
    }
}

int main()
{
    hanoi(2, 'A', 'B', 'C');
}
//如果汉诺塔只有一层
//只需要将A->C
//带入hanoi函数可以得到正确结果
//
//如果汉诺塔有两层
//把最上面那层视为一层的汉诺塔 注*
//将其移动到B
//再把最下面的一层移动到C 　注*
//最后把B上的一层汉诺塔移动到C
//
//注*
//把一层视为一个汉诺塔,那么两层三层同样适用
//在主函数中可以看出,一个hanoi函数可以操作一个汉诺塔
//所以在hanoi中的hanoi(n-1,a,c,b)的作用就是把除了最下面的一层以外的其他层视为一个汉诺塔进行操作
