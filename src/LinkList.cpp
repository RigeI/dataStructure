#include<iostream>
using namespace std;

template<class DataType>
struct Node
{
    DataType data;
    Node<DataType> *next;
};


template<class DataType>
class LinkList
{
private:
    Node<DataType> *first;
public:
    LinkList();
    LinkList(DataType a[],int n);
    ~LinkList();
    int Length();
    DataType Get(int i);
    int Locate(DataType x);
    void Insert(int i,DataType x);
    DataType Delete(int i);
    void PrintList();
    void Reverse();
    void DeleteTheSame();
};


template<class DataType>
LinkList<DataType>::LinkList()
{
    first = new Node<DataType>;
    first->next=NULL;
}


template<class DataType>
LinkList<DataType>::LinkList(DataType a[],int n)
{
    first=new Node<DataType>;
    first->next=NULL;

    Node<DataType> * r=first;

    for(int t=0;t<n;t++)
    {   
        Node<DataType> *s=new Node<DataType>;
        s->data = a[t];
        s->next=r->next;
        r->next=s;

        r=s;
    }
}


template<class DataType>
LinkList<DataType>::~LinkList()
{
    Node<DataType> *p;
    while(first!=NULL)
    {
        p = first;
        first=first->next;
        delete p;
    }
}


template<class DataType>
int LinkList<DataType>::Length()
{
    int t=0;
    Node<DataType> *p=first->next;
    while(p!=NULL)
    {
        t++;
        p=p->next;
    }
    return t;
}


template<class DataType>
DataType LinkList<DataType>::Get(int i)
{
    Node<DataType>* p = first;
    while(i--)
    {
        p=p->next;
    }
    return p->data;
}




template<class DataType>
int LinkList<DataType>::Locate(DataType x)
{
    Node<DataType>* p=first->next;
    int t=1;
    while(p!=NULL)
    {
        if(p->data==x)
        {   
            return t;
        }
        p=p->next;
        t++;
    }
    return 0;
}



template<class DataType>
void LinkList<DataType>::Insert(int i,DataType x)
{
    Node<DataType>* p=first;
   
    while(--i)
    {
        p=p->next;
    }

    Node<DataType> *s = new Node<DataType>;
    s->data=x;
    s->next=p->next;
    p->next=s;
}


template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{   
    Node<DataType>* p=first;
   
    while(--i)
    {
        p=p->next;
    }

    Node<DataType>* q=p->next;
    DataType x = q->data;
    p->next=q->next;
    delete q;
    return x;
}


template<class DataType>
void LinkList<DataType>::PrintList()
{
    Node<DataType>* p = first->next;
    while(p!=NULL)
    {
        cout<<p->data<<'\t';
        p=p->next;
    }
    cout<<endl;
}


template<class DataType>
void LinkList<DataType>::Reverse()
{

    if(Length()<2)
        return;
    Node<DataType> *p=first->next;
    Node<DataType> *q=p->next;
    Node<DataType> *r=q->next;

    p->next=NULL;
    while(r!=NULL)
    {
        q->next=p;
        p=q;
        q=r;
        r=r->next;
    }

    q->next=p;
    first->next=q;
}

template<class DataType>
void LinkList<DataType>::DeleteTheSame()
{
    int i=1;
    while(i<Length())
    {
        if(Get(i)==Get(i+1)){
            Delete(i);
        }else{
            i++;
        }
    }
}

int main()
{
    LinkList<int> s;
    if(true)
    {
        s.Insert(1,1);
        s.Insert(1,1);
        s.Insert(1,1);
        s.Insert(2,2);
        s.Insert(3,3);
        s.Insert(4,3);
        s.Insert(5,3);
        s.Insert(6,4);
        s.Insert(7,5);
        s.Insert(7,5);
        s.Insert(7,5);
        
        s.PrintList();
        s.DeleteTheSame();
        s.PrintList();
    }
}

