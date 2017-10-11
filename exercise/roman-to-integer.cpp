#include<iostream>
#include<string>
using namespace std;

int romanToInt(string &s) {
	// 字母转数字
	int arr[20]={0};
	for(unsigned int i=1;i<=s.size();i++){
		switch(s[i-1]){
			case 'I':
				arr[i]=1;break;
			case 'V':
				arr[i]=5;break;
			case 'X':
				arr[i]=10;break;
			case 'L':
				arr[i]=50;break;
			case 'C':
				arr[i]=100;break;
			case 'D':
				arr[i]=500;break;
			case 'M':
				arr[i]=1000;break;
		}
	}
	int tmp=0;
	int ans=0; // 最终答案

	for(unsigned int i=0;i<=s.size();i++){
		//cout<<arr[i]<<'\t'<<ans<<endl;
		if(arr[i]<arr[i+1]){
			tmp+=arr[i];
		}else{
			ans+=(arr[i]-tmp);
			tmp=0;
		}
	}
	return ans;
}

int main(){
    string s="XCIX";
    cout<<romanToInt(s)<<endl;
}
