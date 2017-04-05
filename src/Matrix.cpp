#include<iostream>
#include"Arrays.cpp"

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
        Matrix(Arrays<DataType> &arr);
        ~Matrix();
        DataType getData(int x,int y);
        void Show();
};


template<class DataType>

Matrix<DataType>::Matrix(Arrays<DataType> &arr)
{
    int i,j;
    const int Max=max(arr.getLength(),arr.getWidth());
    Node<DataType> *h[Max],*p,*q,*r;
    mh = new Node<DataType>;
    
    //矩阵头指针保存行列数
    mh->row=arr.getLength();    
    mh->col=arr.getWidth();
    r=mh;

    for(i=0;i<Max;i++)
    {
        h[i]=new Node<DataType>;
        h[i]->down=h[i]->right=h[i];
        r->link=h[i];
        r=h[i];
    }
    r->link=mh;

    for(i=0;i<(mh->row);i++)
    {
        for(j=0;j<(mh->col);j++)
        {
            if(arr.get(i,j))
            {
                p=new Node<DataType>;
                p->row=i;
                p->col=j;
                p->data=arr.get(i,j);

                q=h[i];
                while(q->right!=h[i]&&(q->right->col)<j)
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

Matrix<DataType>::~Matrix()
{
    cout<<"Matrix析构:"<<endl;
    Node<DataType>  *p,*q,*r;
    p=mh->link;
    while(p!=mh)
    {
        r=p;
        p=p->down;
        while(p!=r)
        {
            q=p;
            p=p->down;
            cout<<"q:"<<q<<endl;
            delete q;
        }
        
        p=r->link;
        cout<<"r:"<<r<<endl;
        delete r;
    }
    cout<<"h:"<<mh<<endl;
    delete mh;

}


template<class DataType>

DataType Matrix<DataType>::getData(int x,int y)
{
    Node<DataType> *p=mh->link;
    Node<DataType> *q;
    
    //右移
    for(int i=0;i<y;i++)
    {
        p=p->link;
    }

    //下移
    q=p;
    p=p->down;
    for(int j=0;j<x;j++)
    {
        if((p->down->row<=x)&&(p->down!=q))
        {
            p=p->down;
        }
    }
    

    //cout<<"("<<p->row<<","<<p->col<<") : "<<p->data<<endl;
    if(p->row==x && p->col==y)
        return p->data;
    else
        return (DataType)0;
}


template<class DataType>

void Matrix<DataType>::Show()
{
    Node<DataType> *p,*q;
    cout<<mh->row<<"行"<<mh->col<<"列:\n"<<endl;
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
    int a[]={1,2,3,4,5,6};
    Arrays<int> arr(3,2,a);
    Matrix<int> m(arr);
    cout<<"Arrays的print方法:"<<endl;
    arr.print();
    cout<<"--------------------------"<<endl;
    cout<<"Matrix的getData循环输出:"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<m.getData(i,j)<<" ";
        }
    cout<<endl;
    }
    cout<<"--------------------------"<<endl;
    cout<<"Matrix的Show方法:"<<endl;
    m.Show();
    cout<<"--------------------------"<<endl;
    

    
  
    
}

