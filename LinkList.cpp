#include<iostream>
using namespace std;

template<class DataType>
struct Node
{
    DataType data;//节点的值
    Node<DataType> *next;//指向下个元素的指针
};



template<class DataType>
class LinkList
{
private:
    Node<DataType> *first;//单链表类,只需要给出头指针,所以数据成员只有头指针
public:
    //函数在实现的位置进行说明
    //这是个带头节点的链表
    //即有一个节点只保存指向下个元素的指针,此节点不保存数值
    //添加一个头节点的目的是统一"空表"与"非空表"的插入删除操作
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
};

template<class DataType>
LinkList<DataType>::LinkList()
{
    //新建一个空链表,头指针指向头节点,这个节点不保存数值
    first = new Node<DataType>;//生成头节点
    first->next=NULL;//头节点指向空
}


template<class DataType>
LinkList<DataType>::LinkList(DataType a[],int n)
{
    //此构造函数传进一个数组,按照数组的顺序存入链表(尾插法)
    //教材里也给出了头插法,链表的顺序与数组的顺序相反
    
    //创建头节点,让这个节点指向NULL
    first=new Node<DataType>;
    first->next=NULL;

    //创建尾指针,这个指针在每次插入完成后都指向最后一个元素
    Node<DataType> * r=first;

    for(int t=0;t<n;t++)
    {   
        //创建一个节点
        Node<DataType> *s=new Node<DataType>;
        //给节点赋值
        s->data = a[t];
        //让s指向原本r应该指向的值,此处r->next其实始终为NULL,为了与插入统一,此处这样写
        //现在只要找到s节点就能找到尾,但是还不能从头节点开始找到s节点
        //此时并未对r进行任何修改,r同样指向NULL
        s->next=r->next;
        //为了能从头节点找到s,需要把s的地址值放到目前链表的最后一个元素的next里
        //也就是把s的地址值放到r->next;
        //此时对r进行了修改,已经能从first的位置开始找到最后一个元素s
        r->next=s;

        //再把r指针指向最后一个元素s,为下次添加节点做准备
        r=s;
    }
}

template<class DataType>
LinkList<DataType>::~LinkList()
{
    //析构函数,只要头节点不为NULL,就保存头节点的地址值,删掉头节点占用的内存,再将头节点后移,直到释放全部内存
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
    //返回长度,移动指针,每次+1,直到指针指向NULL
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
    //得到i位置的值,只需要指针移动i次,返回最后一次指向的值
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
    //返回值为x的节点的位置
    //如果节点不存在返回0
    //以此移动指针,每次记录位置+1
    //找到x返回位置
    //链表的位置从1开始(不是数组的从0开始)
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
    //插入算法,首先要找到需要插入的位置,指针指向第2个元素,插入的元素位置为3
    Node<DataType>* p=first;
   
    while(--i)
    {
        p=p->next;
    }

    //插入的过程,思想同构造函数
    Node<DataType> *s = new Node<DataType>;
    s->data=x;
    s->next=p->next;
    p->next=s;
}


template<class DataType>
DataType LinkList<DataType>::Delete(int i)
{   
    //删除i位置的值,同插入,如果删除第3个元素,需要指针指向第2个元素
    Node<DataType>* p=first;
   
    while(--i)
    {
        p=p->next;
    }

    //创建一个指针q来保存需要删除的元素的地址
    //如果不声明q,同样可以完成删除节点的操作,但不能回收内存
    Node<DataType>* q=p->next;
    //若没有q,此处应该为
    //DataTyoe x =p->next->data;
    DataType x = q->data;
    //如果没有q
    //p->next=p->next->next
    p->next=q->next;
    //没有q此处将不能进行
    //如果delete p->next;则会删除原本链表p后面的后面的元素,同时运行程序时会报runtime error
    delete q;
    return x;
}



template<class DataType>
void LinkList<DataType>::PrintList()
{
    //打印列表
    Node<DataType>* p = first->next;
    while(p!=NULL)
    {
        cout<<p->data<<endl;
        p=p->next;
    }
}

template<class DataType>
void LinkList<DataType>::Reverse()
{

    //这个反转算法并不是很好,如果能看懂其他版本就忽略这个

    //首先清楚,这个链表有头节点
    //虽然反转链表,但头节点没变,即头指针不变

    //长度小于2
    //要么是空链表(空链表有一个头节点,first指向头节点,头节点指向空)
    //要么只有一个元素(有两个节点,一个是没有值的头节点)
    //所以这种情况不需要反转
    if(Length()<2)
        return;

    //首先声明三个指针,这三个指针指向的节点是按顺序的
    //如果p指向地一个,q就指向第二个,r就指向第三个
    //实际进行操作的只有q指针,但是q指针操作完成后就找不到它的下一个需要造作的元素的位置了
    //所以需要p和r两个指针辅助
    Node<DataType> *p=first->next;
    Node<DataType> *q=p->next;
    Node<DataType> *r=q->next;

    //首先让地一个元素指向NULL(头节点之后的那个元素,这个元素就相当与是最有一个节点了)
    //后面要把这个元素的地址保存到原来链表它所指向的元素的next里
    p->next=NULL;
    while(r!=NULL)
    {
        //把p的地址保存到原本它的下个元素q的next里
        //这样造成的结果是q指向的下一个又找不到了,所以要有另一个指针r来保存,r在前面已经初始化了
        q->next=p;
        //三个指针整体往后移动一位
        //因为指针的指向已经变了
        //所以不能用p=p->next
        p=q;
        q=r;
        r=r->next;
    }

    //调整最后一个元素,自己慢慢琢磨吧
    q->next=p;
    first->next=q;
}


int main()
{
    LinkList<int> s;
    
    if(true)
    {
        cout<<"顺序插入元素并输出,输出应为1 2 3 4 5,长度为5"<<endl;
        s.Insert(1,1);
        s.Insert(2,2);
        s.Insert(3,3);
        s.Insert(4,4);
        s.Insert(5,5);
        s.PrintList();
        
        cout<<"反转单链表"<<endl;
        s.Reverse();
        s.PrintList();
    }
    	
    if(false)
    {
        s.Insert(1,5);
        s.Insert(1,3);
        s.Insert(2,4);
        s.Insert(1,1);
        s.Insert(2,2);
        cout<<"不按顺序插入,插入后的值应该为1 2 3 4 5"<<endl;
        s.PrintList();
        cout<<"元素1所在的位置为"<<s.Locate(1)<<endl;
        cout<<"元素3所在的位置为"<<s.Locate(3)<<endl;
        cout<<"元素5所在的位置为"<<s.Locate(5)<<endl;
        cout<<"位置2的元素为"<<s.Get(2)<<endl;
        cout<<"位置4的元素为"<<s.Get(4)<<endl;
    }
   	
    if(false)
    {
        cout<<"用数组初始化单链表,输出1 2 3 4 5"<<endl;
        int arr[5]={1,2,3,4,5};
        LinkList<int> t(arr,5);
        t.PrintList();
    }	
    if(false)
    {
        LinkList<int> t;
        cout<<t.Length()<<endl;
    }
}
