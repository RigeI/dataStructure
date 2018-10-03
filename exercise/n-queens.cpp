#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
// 用于显示当前vecotr
void show(vector<int> v)
{
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

// v 当前vector
// begin 开始检测的值
// end 结束检测的值
// return 可以插入的值,若不可插入返回-1
int next_can_insert(vector<int> v, int begin, int end)
{
    int local = v.size();
    for (int local_val = begin; local_val < end; local_val++) {
        int flag = 1;
        for (int j = 0; j < local; j++) {
            if (abs(j - local) == abs(v[j] - local_val) || v[j] == local_val) {
                flag = 0;
            }
        }
        if (flag) {
            return local_val;
        }
    }
    return -1;
}

void sloveNQueens(int end)
{
    vector<int> current_value;
    int check = -1;
    int begin = 0;
    while (true) {
        check = next_can_insert(current_value, begin, end);
        // 存在可以插入的数
        // 插入该数并将begin恢复0
        if (check >= 0) {
            current_value.push_back(check);
            begin = 0;
            continue;
        }
        // 不可继续插入,判断是否为可行解
        // 并对可行解进行输出
        if (check == -1 && (int)current_value.size() == end) {
            show(current_value);
        }
        // 删除最后一个数,并将开始位置+1
        begin = current_value[current_value.size() - 1] + 1;
        current_value.pop_back();
        // 最大检测到end-1,若要从end开始检测,表示已经结束,退出循环
        if (begin == end && current_value.size() == 0) {
            break;
        }
    }
}

int main()
{
    sloveNQueens(4);
}
