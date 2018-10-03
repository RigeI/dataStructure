//带头节点的循环链表
//请先自行了解约瑟夫患

#include <iostream>
using namespace std;

//节点声明跟其他的相同
//一个数据
//一个指向下个数据的指针
template <class DataType>
struct Node {
    DataType data;
    Node<DataType>* next;
};

template <class DataType>
class CircularLinkedList {
private:
    Node<DataType>* first; //循环单链表需要头指针
public:
    CircularLinkedList();
    CircularLinkedList(DataType arr[], int n); //用尾插法的构造函数
    ~CircularLinkedList();
    int Length();
    void Kill(int num); // 输出约瑟夫环出链表的顺序
    void PrintList();
};

//同单链表
template <class DataType>
CircularLinkedList<DataType>::CircularLinkedList()
{
    first = new Node<DataType>;
    first->next = first;
}

//同单链表
template <class DataType>
CircularLinkedList<DataType>::CircularLinkedList(DataType arr[], int n)
{
    first = new Node<DataType>;
    first->next = first;
    Node<DataType>* r = first;
    for (int t = 0; t < n; t++) {
        Node<DataType>* s = new Node<DataType>;
        s->data = arr[t];
        s->next = r->next;
        r->next = s;
        r = s;
    }
}

//同单链表
template <class DataType>
CircularLinkedList<DataType>::~CircularLinkedList()
{
    Node<DataType>* p = first->next;
    Node<DataType>* q;
    while (p != first) {
        q = p;
        p = p->next;
        delete q;
    }
    delete first;
}

//同单链表
template <class DataType>
void CircularLinkedList<DataType>::PrintList()
{
    Node<DataType>* p = first->next;
    while (p != first) {
        cout << p->data << endl;
        p = p->next;
    }
}

//同单链表
template <class DataType>
int CircularLinkedList<DataType>::Length()
{
    Node<DataType>* p = first;
    int t = 0;
    while (p->next != p)
        t++;
    return t;
}

/**
 * 约瑟夫环
 */
template <class DataType>
void CircularLinkedList<DataType>::Kill(int num)
{

    //首先假设num为7

    Node<DataType>* p = first; //工作指针,p->next将被删除
    Node<DataType>* q;         //在p->next被删除之前保存p->next->next;
    int t = 1;                 //注意,t从１开始

    //循环条件，如果p->next==p,则循环链表中只剩一个节点，且是头节点,在这种情况下退出循环
    while (p != p->next) {
        //循环开始之前,p被初始化为头节点,那么头节点的下一个元素是第一个有值的节点
        p = p->next;

        //因为循环链表里有头节点,所以每次遇到头节点都要跳过,否则影响num计数的次数
        //此处当前指针指向头节点
        if (p == first) {
            p = p->next;
        }

        //指针每次移动,移动次数+1,但移动次数里不包含头节点的移动
        t++;

        //每次是num的倍数时,也可以是每次是num时,进入if
        //因为每次t都从1开始,所以到7的时候指针移动6次(不包指向头节点时指针的移动)
        //也就是说指针指向要被删除的元素的前一个元素
        if (t % num == 0) {
            //同要需要排除头节点的干扰
            //这次的情况是,当前指针指向的"下一个"元素是头节点,与上面不同
            //如果直接删除,就会删除掉头节点,所以需要跳过
            if (p->next == first) {
                p = p->next;
            }

            //让q指向被删除元素的下一个元素
            //p是被删除元素的前一个元素
            q = p->next->next;
            //输出被删除元素的值
            cout << p->next->data << endl;
            //释放被删除元素占用的空间
            delete p->next;
            //链接p和q
            p->next = q;
            //t重置为1,继续循环
            t = 1;
        }
    }
}

int main()
{
    if (true) {
        //构造数组
        int n = 40;
        int arr[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        //根据数组创建循环链表
        CircularLinkedList<int> cll(arr, n);
        //约瑟夫环,每7个杀死一个人
        cll.Kill(7);
    }
}
