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
        void setData(int x,int y,DataType data);
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
    int h=0;
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
            cout<<q->data<<":\t"<<q<<"\tright:\t"<<q->right<<"\tdown:\t"<<q->down<<endl;
            delete q;
        }

        p=r->link;
        cout<<"h["<<h++<<"]:\t"<<r<<"\tright:\t"<<r->right<<"\tdown:\t"<<r->down<<endl;
        delete r;
    }
    cout<<"头节点:\t"<<mh<<endl;
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

void Matrix<DataType>::setData(int x,int y,DataType data)
{  

    Node<DataType> *p=mh->link;
    Node<DataType> *q,*r;

    //右移
    for(int i=0;i<y;i++)
    {
        p=p->link;
    }

    //下移
    q=p;
    for(int j=0;j<=x;j++)
    {
        if((p->down->row<x)&&(p->down!=q))
        {
            p=p->down;
        }
    }

    if(p->down->row==x && p->down->col==y)
    {
        p->down->data=data;
        if(!data)
        {
            r=p->down;
            p->down=r->down;

            p=mh->link;
            //下移
            for(int i=0;i<x;i++)
            {
                p=p->link;
            } 
            //右移
            q=p;
            for(int j=0;j<y;j++)
            {
                if((p->right->row<y)&&(p->right!=q))
                {
                    p=p->down;
                }
            }
            p->right=r->right;


            delete r;
        }
    }
    else
    {
        Node<DataType> *s = new Node<DataType>;
        s->data=data;
        s->row=x;
        s->col=y;
        s->down=p->down;
        p->down=s;

        p=mh->link;
        //下移
        for(int i=0;i<x;i++)
        {
            p=p->link;
        } 
        //右移
        q=p;
        for(int j=0;j<y;j++)
        {
            if((p->right->row<x)&&(p->right!=q))
            {
                p=p->down;
            }
        }

        s->right=p->right;
        p->right=s;
    }
}



template<class DataType>

void Matrix<DataType>::Show()
{
    Node<DataType> *p,*q;
    p=mh->link;
    while(p!=mh)
    {
        q=p->right;
        while(p!=q)
        {
            cout<<"("<<q->row<<","<<q->col<<") "<<q->data<<endl;
            q=q->right;
        }
        p=p->link;
    }
}


int main()
{
    int a[]={0,2,0,0,0,6,7,0,0};
    Arrays<int> arr(3,3,a);
    Matrix<int> m(arr);
    m.setData(0,0,1);
    m.setData(0,1,0);
    cout<<"Arrays的print方法:"<<endl;
    arr.print();
    cout<<"--------------------------"<<endl;
    cout<<"Matrix的getData循环输出:"<<endl;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
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
