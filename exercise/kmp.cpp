#include<iostream>
#include<string>
using namespace std;

int kmp(string s,string t){

    //定义next数组,并赋值
    int next[t.length()];
    int temp=0;
    for(int j=0;j<t.length();j++)
    {
        if(j==0) 
        {
            next[j]=-1;
        }
        else if(t[j-1]==t[next[j-1]])
        {
            temp++; next[j]=temp;
        }
        else
        {
            next[j]=0; temp=0;
        }
    }
    
    //KMP匹配过程
    int i=0,j=0;
    while(i<s.length())
    {
        if(s[i]==t[j])
        {
            i++;j++;
            if(j==t.length()) return i-j;
        }
        else
        {
            j=next[j];
        }
        if(j==-1)
        {
            i++;j++;
        }
    }
    return -1;
}

int main()
{
    string s="ababaababcb";
    string t="ababc";

    cout<<kmp(s,t)<<endl;
}
