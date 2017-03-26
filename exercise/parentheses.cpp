//有效的括号序列
//原题测试数据不足
//如果"))"应该返回false
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
