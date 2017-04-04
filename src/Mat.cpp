#include<iostream>
#define M 3
#define N 3
#define Max ((M)>(N)?(N):(N))

using namespace std;

template<class DataType>
struct Node
{
    int row;
    int col;
    DataType data;
    Node<DataType> *right,*down;
    Node<DataType> *link;//头指针之间用link
};

template<class DataType>
class Matrix
{
    private:    
        Node<DataType> *mh; //matrix head
    public:
        Matrix(DataType arr[M][N]);
        void Show();
};

    template<class DataType>
Matrix<DataType>::Matrix(DataType arr[M][N])
{
    int i,j;
    Node<DataType> *h[Max],*p,*q,*r;
    mh = new Node<DataType>;
    mh->row=M;//矩阵头指针保存行列数
    mh->col=N;
    r=mh;

    for(i=0;i<Max;i++)
    {
        h[i]=new Node<DataType>;
        h[i]->down=h[i]->right=h[i];//循环链表的头
        r->link=h[i];//用link链接循环链表
        r=h[i];
    }
    r->link=mh;//链接一堆循环链表的循环链表的头指针

    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            if(arr[i][j])
            {
                p=new Node<DataType>;
                p->row=i;
                p->col=j;
                p->data=arr[i][j];

                q=h[i];
                while(q->right!=h[i]&&q->right->col<j)
                {
                    q=q->right;
                }
                p->right=q->right;
                q->right=p;

                q=h[j];
                while(q->down!=h[j]&&q->down->row<i)
                {   
                    q=q->down;
                }
                p->down=q->down;
                q->down=p;
            }
        }
    }
}

template<class DataType>
void Matrix<DataType>::Show()
{
    Node<DataType> *p,*q;
    cout<<mh->row<<"行"<<mh->col<<"列"<<endl;
    p=mh->link;
    while(p!=mh)
    {
        q=p->right;
        while(p!=q)
        {
            cout<<q->row<<" "<<q->col<<" "<<q->data<<endl;
            q=q->right;
        }
        p=p->link;
    }
}


int main()
{
    int arr[M][N]={1,2,3,4,5,6,7,8,9};
    Matrix<int> m(arr);
    m.Show();
}

