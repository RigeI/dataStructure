#include <iostream>
#include <limits>
#include <map>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    Point()
        : x(0)
        , y(0)
    {
    }
    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }
};

class Solution {
public:
    static int maxPoints(vector<Point>& points)
    {
        int POINT_NUM = points.size();
        if (POINT_NUM <= 2)
            return POINT_NUM;

        int ans = 0;
        // map 保存过points[i],且斜率为k,的直线数
        map<double, int> m;
        for (int i = 0; i < POINT_NUM; i++) {
            m.clear();
            // 重合点的个数
            int same = 0;
            for (int j = i + 1; j < POINT_NUM; j++) {
                // 相同点
                if (!((points[j].y - points[i].y) || (points[j].x - points[i].x))) {
                    same++;
                    continue;
                }
                // 计算斜率
                double k = points[j].x - points[i].x ? 1.0 * (points[j].y - points[i].y) / (points[j].x - points[i].x) : numeric_limits<double>::max();

                pair<double, int> t;
                t.first = k;
                t.second = m[k] ? m[k] + 1 : 2;

                m.erase(k);
                m.insert(t);
            }

            if (!m.size()) {
                ans = ans > same + 1 ? ans : same + 1;
            } else {
                for (map<double, int>::iterator it = m.begin(); it != m.end(); it++) {
                    ans = ans > (*it).second + same ? ans : (*it).second + same;
                }
            }

#if (0)
            cout << "对于第" << i << "个点:" << endl;
            cout << "重合点有" << same << "个" << endl;
            for (map<double, int>::iterator it = m.begin(); it != m.end(); it++) {
                cout << "m[" << (*it).first << "]=" << (*it).second << endl;
            }
            cout << "----------------" << endl;
#endif
        }
        return ans;
    }
};

int main()
{
    vector<Point> points;

    int x, y;
    char trash;
    cin >> trash;
    while (cin >> trash >> x >> trash >> y >> trash >> trash) {
        points.push_back(Point(x, y));
    }

    cout << Solution::maxPoints(points) << endl;
}
