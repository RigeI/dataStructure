#include <iostream>
using namespace std;

void Swap(char& a, char& b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

// [k,m)为进行全排列的区间
void Perm(char list[], int k, int m)
{
    if (k + 1 == m) {
        cout << list << endl;
    }

    for (int i = k; i < m; i++) {
        Swap(list[k], list[i]);
        Perm(list, k + 1, m);
        Swap(list[k], list[i]);
    }
}

int main()
{
    char list[] = "abc";
    Perm(list, 0, 3);
}
