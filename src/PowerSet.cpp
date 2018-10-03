#include <cmath>
#include <iostream>

using namespace std;

void PowerSet(char list[], int n)
{
    for (int i = 0; i < 1 << n; i++) {
        cout << '{';
        for (int t = 0; t < n; t++)
            if ((1 << t) & i)
                cout << list[t];
        cout << "}\n";
    }
}

int main()
{
    char list[] = "abcdefg";
    // list 包括\0
    // 减1正好为字符个数
    PowerSet(list, sizeof(list) - 1);
}
