#include<iostream>
using namespace std;

template<class DataType>
struct Node
{
    DataType data;
    Node<DataType>* next;
};
template<class DataType>
class LinkStack
{
private:
    Node<DataType> * top;
public:
    LinkStack(){top=NULL;}
    ~LinkStack();
    void Push(DataType x);
    DataType Pop();
    DataType GetTop(){return top==NULL?0:top->data;}
    int Empty(){return top==NULL?1:0;}
};



template<class DataType>
LinkStack<DataType>::~LinkStack()
{
    Node<DataType>* q=top;
    while(top->next!=NULL)
    {
        q=top;
        top=top->next;
        delete q;
    }
}


template<class DataType>
void LinkStack<DataType>::Push(DataType x)
{
    Node<DataType>* s=new Node<DataType>;
    s->data=x;
    s->next=top;
    top=s;
}


template<class DataType>
DataType LinkStack<DataType>::Pop()
{   
    if(top==NULL) cout<<"下溢"<<endl;
    Node<DataType>* q=top;
    DataType x=q->data;
    top=top->next;
    delete q;
    return x;
}


int main()
{
    LinkStack<int> linkStack;
    linkStack.Push(1);
    linkStack.Push(3);
    linkStack.Push(2);
    linkStack.Push(4);

    cout<<linkStack.Pop()<<endl;
    cout<<linkStack.GetTop()<<endl;
    cout<<linkStack.Pop()<<endl;
    cout<<linkStack.Pop()<<endl;
    cout<<linkStack.Pop()<<endl;
    cout<<linkStack.Pop()<<endl;
}






