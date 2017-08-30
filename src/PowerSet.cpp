#include<iostream>
#include<cmath>

using namespace std;

void PowerSet(char list[],int n){
    for(int i=0;i<pow(2,n);i++){
        cout<<'{';
        for(int t=0;t<n;t++)
            if((1<<t)&i) cout<<list[t];
        cout<<"}\n";
    }
}

int main(){
    char list[]="abc";
    PowerSet(list,3);
}
