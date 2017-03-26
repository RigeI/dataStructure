#include<iostream>
using namespace std;

int length(char a[]){
    return sizeof(a)/sizeof(a[0]);
}

int kmp(char s[],char t[]){
    for(int i=0;i<0;i++)
    {
        cout<<s[i];
    }
    return 0;
}

int main(){
    char s[]="abcabcacb";
    char t[]="abcac";
    
    cout<<length(s)<<endl;
}
