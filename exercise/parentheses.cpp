// 有效的括号序列
// 遇到左半个括号则入栈
// 遇到右半个括号则出栈,并判断出栈元素是否与右半个括号匹配
#include<iostream>
#include<stack>
using namespace std;

bool isValidParentheses(string& s) 
{
    if(s.size()%2) return false;

    stack<char> a;
    string::iterator itstr;
    char temp;
    for (itstr = s.begin(); itstr != s.end(); ++itstr)
    {
        if(*itstr=='('||*itstr=='{'||*itstr=='[')
            a.push(*itstr);
        
        else
        {
            if(a.empty())    return false;
            temp = a.top();
            a.pop();

            if(temp=='(' && ')'!=*itstr) return false;
            if(temp=='{' && '}'!=*itstr) return false;
            if(temp=='[' && ']'!=*itstr) return false;
        }
    }

    if(!a.empty()) return false;
    return true;
}

int main()
{
    string s="([()]){}";
    cout<<isValidParentheses(s)<<endl;
}
