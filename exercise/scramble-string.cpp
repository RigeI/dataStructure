#include <iostream>
#include <string>
using namespace std;

bool isScramble(string& s1, string& s2)
{

    if (s1.length() != s2.length()) {
        return false;
    }
    unsigned len = s1.length();
    if (len == 1) {
        return !s1.compare(s2);
    }

    for (unsigned int i = 1; i < len; i++) {
        /* s2分两段 */
        string s2_first = s2.substr(0, i);
        string s2_second = s2.substr(i, len);

        /* s1也分两段,但有可能存在交换 */
        string s1_first1 = s1.substr(0, i);
        string s1_sconde1 = s1.substr(i, len);
        string s1_first2 = s1.substr(len - i, len);
        string s1_sconde2 = s1.substr(0, len - i);

        if (isScramble(s1_first1, s2_first) && isScramble(s1_sconde1, s2_second)) {
            return true;
        }
        if (isScramble(s1_first2, s2_first) && isScramble(s1_sconde2, s2_second)) {
            return true;
        }
    }

    return false;
}

int main()
{
    string a = "great";
    string b = "rgtae";
    cout << isScramble(a, b) << endl;
}
