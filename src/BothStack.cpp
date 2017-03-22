#include<iostream>
using namespace std;

const int StackSize=5;

template<class DataType>
class BothStack
{
private:
    DataType data[StackSize];
    int top1,top2;

public:
    BothStack(){top1=-1;top2=StackSize;}
    ~BothStack(){}
    void Push (int i,DataType x);
    DataType Pop(int i);
    DataType GetTop(int i);
    int Empty(int i);
};


template<class DataType>
void BothStack<DataType>::Push (int i,DataType x)
{
    if(top1+1==top2)
    {
        cout<<"上溢"<<endl;
        return;
    }
    else if(i==1)
    {
        data[++top1]=x;
    }
    else if(i==2)
    {
        data[--top2]=x;
    }
    else
    {
        cout<<"参数i非法"<<endl;
    }
}



template<class DataType>
DataType BothStack<DataType>::Pop(int i)
{
    if(i==1)
    {
        if(top1==-1){cout<<"栈1下溢"<<endl;}
        else
        {
            return data[top1--];
        }
    }
    else if(i==2)
    {
        if(top2==StackSize){cout<<"栈2下溢"<<endl;}
        else
        {
            return data[top2++];
        }
    }
    else
    {
        cout<<"参数i非法"<<endl;
    }
}


template<class DataType>
DataType BothStack<DataType>::GetTop(int i)
{
    if(i==1)
    {
        return data[top1];
    }
    else if(i==2)
    {
        return data[top2];
    }
    else
    {
        cout<<"参数i非法"<<endl;
    }

}


int main()
{
    BothStack<int> bothStack;
    bothStack.Push(1,1);
    bothStack.Push(1,1);
    bothStack.Push(2,2);
    bothStack.Push(2,2);
    bothStack.Push(1,1);
    bothStack.Push(2,2);

    cout<<bothStack.GetTop(1)<<endl;
    cout<<bothStack.Pop(1)<<endl;
    cout<<bothStack.Pop(1)<<endl;
    cout<<bothStack.Pop(1)<<endl;
    cout<<bothStack.Pop(2)<<endl;
    cout<<bothStack.Pop(2)<<endl;
    cout<<bothStack.Pop(2)<<endl;
}


