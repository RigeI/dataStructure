//两栈共享一块内存单元,
//盏低分别为数组的第一个元素和最后一个元素,
//插入操作时向中间靠拢

#include<iostream>
using namespace std;

const int StackSize=5;

template<class DataType>
class BothStack
{
private:
    DataType data[StackSize];//一块内存
    int top1,top2;//两个栈顶指针

public:
    //初始情况两个栈都为空,不指向实际的位置
    //所以指向数组边缘外的两个值
    BothStack(){top1=-1;top2=StackSize;}
    //没有动态申请内存,析构函数为空
    ~BothStack(){}

    //入栈,选择要插入第一个栈还是第二个栈
    //并给出插入的元素
    void Push (int i,DataType x);
    
    //从栈顶删除一个元素,并得到栈顶元素
    DataType Pop(int i);

    //得到栈顶元素
    DataType GetTop(int i);
    
    //判断栈是否为空,为空返回1
    int Empty(int i);
};


//操作类似顺序表
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



//操作类似顺序表
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


//操作类似顺序表
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


