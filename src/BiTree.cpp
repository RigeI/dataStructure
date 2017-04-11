#include<iostream>
#include<queue>

using namespace std;

template<class DataType>
struct BiNode
{
    DataType data;
    BiNode<DataType> *lchild,*rchild;
};


template<class DataType>
class BiTree
{
    private:
        BiNode<DataType> *root;
        BiNode<DataType> *Create(BiNode<DataType> *bt);
        void Release(BiNode<DataType> *bt);
        void PreOrder(BiNode<DataType> *bt);
        void InOrder(BiNode<DataType> *bt);
        void PostOrder(BiNode<DataType> *bt);

    public:
        BiTree(){root=Create(root);}
        ~BiTree(){Release(root);}
        void PreOrder(){PreOrder(root);}
        void InOrder(){InOrder(root);}
        void PostOrder(){PostOrder(root);}
        void LeverOrder();
};



template<class DataType>

BiNode<DataType> *BiTree<DataType>::Create(BiNode<DataType> *bt)
{
    static DataType ch;
    cin>>ch;
    if(ch=='#') 
    {
        bt=NULL;
    }
    else
    {
        bt=new BiNode<DataType>;
        bt->data=ch;
        bt->lchild=Create(bt->lchild);
        bt->rchild=Create(bt->rchild);
    }

    return bt;
}


template<class DataType>

void BiTree<DataType>::Release(BiNode<DataType> *bt)
{
    if(bt)
    {
        Release(bt->lchild);
        Release(bt->rchild);
        delete bt;
    }
}

template<class DataType>

void BiTree<DataType>::PreOrder(BiNode<DataType> *bt)
{
    if(!bt) return;
    else
    {
        cout<<bt->data;
        PreOrder(bt->lchild);
        PreOrder(bt->rchild);
    }
}



template<class DataType>

void BiTree<DataType>::InOrder(BiNode<DataType> *bt)
{
    if(!bt) return;
    else
    {
        InOrder(bt->lchild);
        cout<<bt->data;
        InOrder(bt->rchild);
    }
}



template<class DataType>

void BiTree<DataType>::PostOrder(BiNode<DataType> *bt)
{
    if(!bt) return;
    else
    {
        PostOrder(bt->lchild);
        PostOrder(bt->rchild);
        cout<<bt->data;
    }
}

template<class DataType>
void BiTree<DataType>::LeverOrder()
{
    if(!root) return;
    queue< BiNode<DataType> * > q;
    BiNode<DataType> *temp;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        cout<<temp->data;
        if(temp->lchild) q.push(temp->lchild);
        if(temp->rchild) q.push(temp->rchild);
    }
}


int main()
{
    BiTree<char> b;
    b.PreOrder();
    cout<<endl;
    b.InOrder();
    cout<<endl;
    b.PostOrder();
    cout<<endl;
    b.LeverOrder();
    cout<<endl;
}



















