#include<iostream>
using namespace std;

int kth_smallest_number(int arr[], int begin, int end, int k){
    int i = begin;
    int j = end;
    while(i<j){
        while(i < j && arr[i] < arr[j]) i++;
        while(i < j && arr[i] < arr[j]) j--;
        swap(arr[i], arr[j]);
    }
    if(i == k-1)
        return arr[i];
    else if(i > k-1)
        return kth_smallest_number(arr, begin, i-1, k);
    else
        return kth_smallest_number(arr, i+1, end , end - k -1);
}

int main(){
    int arr[] = {14,6,2,4,12,8,10};
    cout<<kth_smallest_number(arr, 0, 6, 3)<<endl;
}
