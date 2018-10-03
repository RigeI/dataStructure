#include <iostream>
using namespace std;

//同单链表
template <class DataType>
struct Node {
    DataType data;
    Node<DataType>* next;
};

template <class DataType>
class LinkSet {
private:
    Node<DataType>* first;

public:
    LinkSet();
    ~LinkSet();
    bool IsInSet(DataType x); //判断元素是否在集合中
    void Insert(DataType x);
    void Delete(DataType x);
    Node<DataType>* GetFirst() { return first; }
    LinkSet<DataType> Union(LinkSet& linkset);        //传入集合的引用,返回并集
    LinkSet<DataType> Intersection(LinkSet& linkset); //传入集合的引用,返回交集
    LinkSet<DataType> Difference(LinkSet& linkset);   //差集的引用
    void PrintSet();
};

//同单链表
template <class DataType>
LinkSet<DataType>::LinkSet()
{
    Node<DataType>* s = new Node<DataType>;
    s->next = NULL;
    first = s;
}

//同单链表
template <class DataType>
LinkSet<DataType>::~LinkSet()
{
    Node<DataType>* q;
    while (first) {
        q = first->next;
        delete first;
        first = q;
    }
}

//判断某个元素是否在集合中
template <class DataType>
bool LinkSet<DataType>::IsInSet(DataType x)
{
    //遍历整个链表,如果在集合中返回真
    Node<DataType>* p = first->next;
    while (p) {
        if (p->data == x)
            return true;
        p = p->next;
    }
    //否则返回假
    return false;
}

//集合无序,元素不重复,插入时只需要考虑是否已经存在
template <class DataType>
void LinkSet<DataType>::Insert(DataType x)
{
    //如果已经存在直接返回.不进行插入操作
    if (IsInSet(x))
        return;

    //直接在头节点后插入元素(无序性),时间复杂度最低
    Node<DataType>* s = new Node<DataType>;
    s->data = x;
    s->next = first->next;
    first->next = s;
}

//同单链表
template <class DataType>
void LinkSet<DataType>::Delete(DataType x)
{
    Node<DataType>*p = first, *q;
    while (p->next) {
        if (p->next->data == x) {
            q = p->next;
            p->next = q->next;
            delete q;
            return;
        }
        p = p->next;
    }
}

//同单链表
template <class DataType>
void LinkSet<DataType>::PrintSet()
{
    Node<DataType>* p = first;
    while (p->next) {
        cout << p->next->data << " ";
        p = p->next;
    }
    cout << endl;
}

//集合的并
template <class DataType>
LinkSet<DataType> LinkSet<DataType>::Union(LinkSet& OtherSet)
{
    //创建一个新的集合
    LinkSet<DataType> resultLinkSet;

    //遍历两个集合,直接插入新的集合,
    //因为插入操作需要判断是否已经存在,所以此处不需要做判断
    Node<DataType>* p;
    for (p = first->next; p; p = p->next) {
        resultLinkSet.Insert(p->data);
    }

    for (p = OtherSet.GetFirst()->next; p; p = p->next) {
        resultLinkSet.Insert(p->data);
    }
    return resultLinkSet;
}

//集合的交
template <class DataType>
LinkSet<DataType> LinkSet<DataType>::Intersection(LinkSet& OtherSet)
{
    LinkSet<DataType> resultLinkSet;
    Node<DataType>* p;

    //取出当前集合的元素,并且判断此元素是否在另一个集合中,
    //如果存在则插入结果集合中
    for (p = first->next; p; p = p->next) {
        if (OtherSet.IsInSet(p->data))
            resultLinkSet.Insert(p->data);
    }
    return resultLinkSet;
}

//集合的差
template <class DataType>
LinkSet<DataType> LinkSet<DataType>::Difference(LinkSet& OtherSet)
{
    LinkSet<DataType> resultLinkSet;
    Node<DataType>* p;

    //类似集合的交
    //取出当前集合的元素,如果该元素不在另一个集合中
    //插入该元素
    for (p = first->next; p; p = p->next) {
        if (!OtherSet.IsInSet(p->data))
            resultLinkSet.Insert(p->data);
    }
    return resultLinkSet;
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

    LinkSet<int> s1;
    s1.Insert(1);
    s1.Insert(2);
    s1.Insert(3);
    cout << "集合A: ";
    s1.PrintSet();

    LinkSet<int> s2;
    s2.Insert(3);
    s2.Insert(4);
    s2.Insert(5);
    cout << "集合B: ";
    s2.PrintSet();

    LinkSet<int> s3 = s1.Union(s2);
    cout << "A+B: ";
    s3.PrintSet();

    LinkSet<int> s4 = s1.Intersection(s2);
    cout << "AB: ";
    s4.PrintSet();
    LinkSet<int> s5 = s1.Difference(s2);
    cout << "A-B: ";
    s5.PrintSet();
}
