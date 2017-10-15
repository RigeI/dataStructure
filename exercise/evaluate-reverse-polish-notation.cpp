#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<stack>

using namespace std;

int str_to_int(string s){
    istringstream in(s);
    int i;
    in>>i;
    return i;
}

bool isOp(string s){
    return s=="+"||s=="-"||s=="*"||s=="/";
}

void calculate(string op,stack<int> &s){
    int b=s.top();
    s.pop();
    int a=s.top();
    s.pop();
    switch(op.at(0)){
    case '+':
        s.push(a+b);
        break;
    case '-':
        s.push(a-b);
        break;
    case '*':
        s.push(a*b);
        break;
    case '/':
        s.push(a/b);
        break;
    }
}

int evalRPN(vector<string> &tokens){
    stack<int> s;
    for(int i=0;i<(int)tokens.size();i++){
        if(isOp(tokens[i])){
            calculate(tokens[i],s);
        }else{
            s.push(str_to_int(tokens[i]));
        }
    }
    return s.top();
}

int main(){
    vector<string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");
    
    cout<<evalRPN(tokens)<<endl;
}
