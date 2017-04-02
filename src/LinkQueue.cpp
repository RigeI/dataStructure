#include<iostream>
using namespace std;

//链队列
//只能在尾插入
//头删除
//操作过程类似单链表

template<class DataType>
struct Node
{
    DataType data;
    Node<DataType> *next;
};


template<class DataType>
class LinkQueue
{
private:
    Node<DataType> *front,*rear;
public:
    LinkQueue();
    ~LinkQueue();
    void EnQueue(DataType x);
    DataType DeQueue();
    DataType GetQueue();
    int Empty(){return front==rear?1:0;}
};


template<class DataType>
LinkQueue<DataType>::LinkQueue()
{
    Node<DataType> *s = new Node<DataType>;
    s->next=NULL;//个人觉得这个没必要赋值
    front=rear=s;
}

template<class DataType>
LinkQueue<DataType>::~LinkQueue()
{
    Node<DataType> *q;
    while(front!=NULL)
    {   
        q=front->next;
        delete front;
        front=q;
    }
}



template<class DataType>
void LinkQueue<DataType>::EnQueue(DataType x)
{
    Node<DataType> *s=new Node<DataType>;
    s->data=x;
    s->next=rear->next;
    rear->next=s;
    rear=s;
}

template<class DataType>
DataType LinkQueue<DataType>::DeQueue()
{
    Node<DataType> *q=front->next;
    if(q==rear)
    {
        rear=front;
    }
    DataType x=q->data;
    front->next=q->next;
    delete q;
    return x;
}

template<class DataType>
DataType LinkQueue<DataType>::GetQueue()
{
    return front->next->data;
}


int main()
{
    LinkQueue<int> linkQueue;
    linkQueue.EnQueue(1);
    linkQueue.EnQueue(2);
    linkQueue.EnQueue(3);
    linkQueue.EnQueue(4);
    cout<<"得到队首元素1"<<endl
        <<linkQueue.GetQueue()<<endl;
    cout<<"1 2出队: "<<endl;
    cout<<linkQueue.DeQueue()<<endl
        <<linkQueue.DeQueue()<<endl;
    
    linkQueue.EnQueue(5);
    linkQueue.EnQueue(6);

    cout<<"5 6入队"<<endl;
    cout<<"3 4 5 6出队:"<<endl;
    cout<<linkQueue.DeQueue()<<endl
        <<linkQueue.DeQueue()<<endl
        <<linkQueue.DeQueue()<<endl
        <<linkQueue.DeQueue()<<endl;

    cout<<"空队列测试"<<endl;
    cout<<linkQueue.Empty()<<endl;

    LinkQueue<int> emptyQueue;
    cout<<emptyQueue.Empty()<<endl;

}
