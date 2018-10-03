//同顺序表

#include <iostream>
#include <string>
using namespace std;

const int StackSize = 5;

//异常处理虚基类
class Exception {
public:
    virtual void ExceptionMsg() = 0;
};

//异常处理,上溢
class OverFlow : public Exception {
public:
    void ExceptionMsg()
    {
        cout << "上溢" << endl;
    }
};
//异常处理,下溢
class UnderFlow : public Exception {
public:
    void ExceptionMsg()
    {
        cout << "下溢" << endl;
    }
};

//顺序栈
template <class DataType>
class SeqStack {
private:
    DataType data[StackSize]; //栈的最大容量
    int top;                  //指示栈顶的位置,0为第一个元素
public:
    SeqStack() { top = -1; }
    ~SeqStack() {}
    void Push(DataType x); //插入元素x
    DataType Pop();        //删除栈定元素并返回栈顶元素的值
    DataType GetTop()
    {
        if (top != -1)
            return data[top];
    }                                         //得到栈顶元素的值,不删除元素
    int Empty() { return top == -1 ? 1 : 0; } //判断栈是否为空
};

template <class DataType>
void SeqStack<DataType>::Push(DataType x)
{
    //如果栈已经满,则插入元素报上溢异常
    try {
        if (top == StackSize - 1)
            throw OverFlow();
        data[++top] = x;
    } catch (OverFlow e) {
        e.ExceptionMsg();
    }
}

template <class DataType>
DataType SeqStack<DataType>::Pop()
{
    //如果栈已空,删除元素报下溢异常
    try {
        if (top == -1)
            throw UnderFlow();
    } catch (UnderFlow e) {
        e.ExceptionMsg();
    }
    return data[top--];
}

int main()
{
    SeqStack<int> seqStack;
    seqStack.Push(1);
    seqStack.Push(1);
    seqStack.Push(1);
    seqStack.Push(1);
    seqStack.Push(1);
    //上溢
    seqStack.Push(1);
    cout << seqStack.Pop() << endl;
    cout << seqStack.Pop() << endl;
    cout << seqStack.Pop() << endl;
    cout << seqStack.Pop() << endl;
    cout << seqStack.Pop() << endl;
    //下溢
    cout << seqStack.Pop() << endl;
}
