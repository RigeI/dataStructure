//有效的括号序列

#include<iostream>
#include<stack>
using namespace std;

bool isValidParentheses(string& s) 
{
    if(s.size()%2)
        return false;

    stack<char> a;
    string::iterator itstr;
    char temp;
    for (itstr = s.begin(); itstr != s.end(); ++itstr)
    {
        if(*itstr=='('||*itstr=='{'||*itstr=='[')
            a.push(*itstr);
        
        else
        {
            temp = a.top();
            a.pop();

            if(temp=='(')
                if(')'!=*itstr)
                    return false;

            else if(temp=='{')
                if('}'!=*itstr)
                    return false;
            else
                if(']'!=*itstr)
                    return false;
        }
    }
    if(!a.empty())
    {
        return false;
    }
    return true;
}

int main()
{
    string s="()";
    cout<<isValidParentheses(s)<<endl;
}
