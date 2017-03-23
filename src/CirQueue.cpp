#include<iostream>
using namespace std;

//一下运算均为模5
//队列的大小为5
//队列里只能存放4个元素
//添加元素时rear向后移动
//删除元素时front向后移动
//当front==rear时,为空
//当rear+1==front时,为满
//如果存放5个元素，则空和满均为front==rear
const int QueueSize=5;

template <class DataType>
class CirQueue
{
private:
    DataType data[QueueSize];
    int front,rear;
public:
    CirQueue(){front=rear=0;}
    ~CirQueue(){}
    void EnQueue(DataType x);
    DataType DeQueue();
    DataType GetQueue();
    int Empty(){return front==rear?1:0;}
};



template <class DataType>
void CirQueue<DataType>::EnQueue(DataType x)
{
    if((rear+1)%QueueSize==front%QueueSize)
    {
        cout<<"队列满,上溢"<<endl;;
        return;
    }
    data[rear]=x;
    rear=(rear+1)%QueueSize;
}


template <class DataType>
DataType CirQueue<DataType>::DeQueue()
{
    if(Empty())
    {
        cout<<"队列空,下溢"<<endl;
    }
    DataType temp=data[front];
    front=(front+1)%QueueSize;
    return temp;
}

template <class DataType>
DataType CirQueue<DataType>::GetQueue()
{
    if(Empty())
    {
        cout<<"队列空"<<endl;
    }
    return data[front];
}


int main()
{
    CirQueue<int> cirQueue;
    cirQueue.EnQueue(1);
    cirQueue.EnQueue(2);
    cirQueue.EnQueue(3);
    cirQueue.EnQueue(4);
    cout<<"得到队首元素1"<<endl
        <<cirQueue.GetQueue()<<endl;
    cout<<"1 2出队: "<<endl;
    cout<<cirQueue.DeQueue()<<endl
        <<cirQueue.DeQueue()<<endl;
    
    cirQueue.EnQueue(5);
    cirQueue.EnQueue(6);

    cout<<"5 6入队"<<endl;
    cout<<"3 4 5 6出队:"<<endl;
    cout<<cirQueue.DeQueue()<<endl
        <<cirQueue.DeQueue()<<endl
        <<cirQueue.DeQueue()<<endl
        <<cirQueue.DeQueue()<<endl;
}
