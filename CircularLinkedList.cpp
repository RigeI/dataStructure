/**
 * 带头节点的循环链表
 * 解决约瑟夫环问题
 **/



#include<iostream>
using namespace std;
template<class DataType>
struct Node
{
    DataType data;
    Node<DataType> *next;
};


template<class DataType>
class CircularLinkedList
{ 
// 如果只实现约瑟夫环,可以简化类
// 只需用数组创建的对象
// 析构时用约瑟夫环的方法析构,最后删除表头

private:
	Node<DataType>* first;
public:
	CircularLinkedList();
	CircularLinkedList(DataType arr[],int n);
	~CircularLinkedList();
    int Length();
    void Kill(int num);
	void PrintList();
};

template<class DataType>
CircularLinkedList<DataType>::CircularLinkedList()
{
	first=new Node<DataType>;
	first->next=first;
}

template<class DataType>
CircularLinkedList<DataType>::CircularLinkedList(DataType arr[],int n)
{
	first=new Node<DataType>;
	first->next=first;
	Node<DataType>* r = first;
	for(int t=0;t<n;t++)
	{
		Node<DataType> *s=new Node<DataType>;
        s->data = arr[t];
        s->next=r->next;
        r->next=s;
        r=s;
	}
}


template<class DataType>
CircularLinkedList<DataType>::~CircularLinkedList()
{
    Node<DataType> *p=first->next;
    Node<DataType> *q;
    while(p!=first)
    {
        q = p;
        p=p->next;
        delete q;
    }
    delete first;
}


template<class DataType>
void CircularLinkedList<DataType>::PrintList()
{
    Node<DataType>* p = first->next;
    while(p!=first)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}


template<class DataType>
int CircularLinkedList<DataType>::Length()
{
    Node<DataType>* p=first;
    int t=0;
    while(p->next!=p) t++;
    return t;
}



/**
 * 约瑟夫环
 */
template<class DataType>
void CircularLinkedList<DataType>::Kill(int num)
{
    Node<DataType> *p=first;//工作指针,p->next将被删除
    Node<DataType> *q;//在p->next被删除之前保存p->next->next;
    int t=1;
    while(p!=p->next)
    {   
        p=p->next;
        
        if(p==first)
        {
            p=p->next;
        }
        
        t++;
    
        if(t%num==0)
        { 
            if(p->next==first)
            {
                p=p->next;
            }
        
            q=p->next->next;
            cout<<p->next->data<<endl;
            delete p->next;
            p->next=q;
            t=1;
        }
    }
}



int main()
{
    if(true)
    {
        //构造数组
    	int n=40;
   		int arr[n];
   		for(int i=0;i<n;i++)
   		{
    		arr[i]=i+1;
    	}
        
        //根据数组创建循环链表
   		CircularLinkedList<int> cll(arr,n);
        //约瑟夫环,每7个杀死一个人
   		cll.Kill(7);

       	}
}  
