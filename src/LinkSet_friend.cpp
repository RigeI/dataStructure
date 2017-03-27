#include<iostream>
using namespace std;
/*
 * 友元函数+模板
 * 只在类内声明友元函数
 * 函数在类外定义
 * 实现起来较为复杂
 * 所以把友元函数的定义直接写在类里面
 * 非要写在外面的同学请自行参考
 * https://isocpp.org/wiki/faq/templates#template-friends
 * */

template<class DataType>
struct Node
{
    DataType data;//节点的值
    Node<DataType> *next;//指向下个元素的指针
};


template<class DataType>
class LinkSet{
    private:
        Node<DataType> *first;
    public:
        LinkSet();
        ~LinkSet();
        bool IsInSet(DataType x);//判断元素是否在集合中
        void Insert(DataType x);
        void Delete(DataType x);
        void PrintSet();
        friend LinkSet<DataType> Union (LinkSet<DataType> &set1,LinkSet<DataType> &set2)//传入集合的引用,返回并集
        {
            LinkSet<DataType> result;
            Node<DataType> *p;
            for(p=set1.first->next;p;p=p->next)
            {
                result.Insert(p->data);
            }

            for(p=set2.first->next;p;p=p->next)
            {
                result.Insert(p->data);
            }
            return result;
        }

        friend LinkSet<DataType> Intersection (LinkSet<DataType> &set1,LinkSet<DataType> &set2)//传入集合的引用,返回交集
        {
            LinkSet<DataType> result;
            Node<DataType> *p;
            for(p=set1.first->next;p;p=p->next)
            {   
                if(set2.IsInSet(p->data))
                    result.Insert(p->data);
            }
            return result;
        }

        friend LinkSet<DataType> Difference (LinkSet<DataType> &set1,LinkSet<DataType> &set2)//差集的引用
        {
            LinkSet<DataType> result;
            Node<DataType> *p;
            for(p=set1.first->next;p;p=p->next)
            {   
                if(!set2.IsInSet(p->data))
                    result.Insert(p->data);
            }
            return result;
        }


};

template<class DataType>
LinkSet<DataType>::LinkSet()
{
    Node<DataType> *s = new Node<DataType>;
    s->next=NULL;
    first=s;
}




template<class DataType>
LinkSet<DataType>::~LinkSet()
{
    Node<DataType> *q;
    while(first)
    {   
        q=first->next;
        delete first;
        first=q;
    }
}

template<class DataType>
bool LinkSet<DataType>::IsInSet(DataType x)
{
    Node<DataType> *p=first->next;
    while(p)
    {
        if(p->data==x) return true;
        p=p->next;
    }
    return false;
}

template<class DataType>
void LinkSet<DataType>::Insert(DataType x)
{
    if(IsInSet(x)) return;

    Node<DataType> *s = new Node<DataType>;
    s->data = x;
    s->next = first->next;
    first->next=s;
}

template<class DataType>
void LinkSet<DataType>::Delete(DataType x)
{
    Node<DataType> *p=first,*q;
    while(p->next)
    {
        if(p->next->data==x)
        {
            q=p->next;
            p->next = q->next;
            delete q;
            return;
        }
        p=p->next;
    }
}


template<class DataType>
void LinkSet<DataType>::PrintSet()
{
    Node<DataType> *p=first;
    while(p->next)
    {
        cout<<p->next->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    /* 集合插入删除操作
       LinkSet<int> linkset;
       linkset.Insert(1);
       linkset.Insert(2);
       linkset.Insert(3);
       linkset.Insert(4);
       linkset.Insert(5);
       linkset.Insert(5);
       linkset.Insert(5);
       linkset.PrintSet();
       linkset.Delete(5);
       linkset.Delete(1);
       linkset.PrintSet();    
       */
    
    cout<<"因为集合元素不分先后,所以使用头插法,输出的顺序与插入顺序相反"<<endl;

    LinkSet<int> s1;
    s1.Insert(3);
    s1.Insert(2);
    s1.Insert(1);
    cout<<"集合A: ";
    s1.PrintSet();

    LinkSet<int> s2;
    s2.Insert(5);
    s2.Insert(4);
    s2.Insert(3);
    cout<<"集合B: ";
    s2.PrintSet();

    LinkSet<int> s3=Union(s1,s2);
    cout<<"A+B: ";
    s3.PrintSet();

    LinkSet<int> s4=Intersection(s1,s2);
    cout<<"AB: ";
    s4.PrintSet();
    LinkSet<int> s5=Difference(s1,s2);
    cout<<"A-B: ";
    s5.PrintSet();
}








