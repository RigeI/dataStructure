#include<iostream>
#include<queue>
#include<vector>
#include<string>

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
        void PreOrderLeaf(BiNode<DataType> *bt);
        void PreOrder(BiNode<DataType> *bt);
        void InOrder(BiNode<DataType> *bt);
        void PostOrder(BiNode<DataType> *bt);
        void Invert(BiNode<DataType> *bt);
        vector<string> TreePaths(BiNode<DataType> *bt);
    public:
        BiTree(){root=Create(root);}
        ~BiTree(){Release(root);}
        BiNode<DataType>* Root(){return root;}
        void PreOrder(){PreOrder(root);}
        void PreOrderLeaf(){PreOrderLeaf(root);}
        void InOrder(){InOrder(root);}
        void PostOrder(){PostOrder(root);}
        void LeverOrder();
        void Invert(){Invert(root);}
        int NodeCount();
        vector<string> TreePaths(){return TreePaths(root);}
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

void BiTree<DataType>::PreOrderLeaf(BiNode<DataType> *bt)
{
    if(!bt) return;
    else
    {
        if(bt->lchild==NULL && bt->rchild==NULL) cout<<bt->data<<" ";
        PreOrderLeaf(bt->lchild);
        PreOrderLeaf(bt->rchild);
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

template<class DataType>

int BiTree<DataType>::NodeCount()
{
  
    if(!root) return 0 ;
    queue< BiNode<DataType> * > q;
    int count=0;
    BiNode<DataType> *temp;
    q.push(root);
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        count++;
        if(temp->lchild) q.push(temp->lchild);
        if(temp->rchild) q.push(temp->rchild);
    }  
    return count;
}





template<class DataType>

bool IsEqual(BiNode<DataType> *a,BiNode<DataType> *b)
{   
    if(a==NULL&&b==NULL){
        return true;
    }else if(a==NULL^b==NULL){
        return false;
    }else if(a->data!=b->data){
        return false;
    }else{
        return IsEqual(a->lchild,b->lchild)
            &&IsEqual(a->rchild,b->rchild);
    }
}


template<class DataType>

bool IsChild(BiNode<DataType> *a,BiNode<DataType> *b)
{
    if(!b) return true;
    else if(!a) return false;
    else if(IsEqual(a,b)) return true;
    else if(IsChild(a->lchild,b)) return true;
    else if(IsChild(a->rchild,b)) return true;
    else return false;
}


template<class DataType>

void BiTree<DataType>::Invert(BiNode<DataType> *bt)
{
    if(bt==NULL) return;
    else{
        BiNode<DataType> *temp;
        temp = bt->lchild;
        bt->lchild = bt->rchild;
        bt->rchild = temp;
    }
    Invert(bt->lchild);
    Invert(bt->rchild);
}

template<class DataType>

vector<string> BiTree<DataType>::TreePaths(BiNode<DataType> *bt)
{
    string ts="";
    vector<string> ans;
    if(!bt) return ans;
    queue<string> qs;
    queue<BiNode<DataType> *> q;
    BiNode<DataType> *temp;
    q.push(bt);
    qs.push(ts+bt->data);
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        ts = qs.front();
        qs.pop();
        if(temp->lchild==NULL&&temp->rchild==NULL)
        {
            //cout<<ts<<endl;
            ans.push_back(ts);
        }
        if(temp->lchild)
        {
            q.push(temp->lchild);
            qs.push(ts+"->"+(temp->lchild->data));
        }
        if(temp->rchild)
        {
            q.push(temp->rchild);
            qs.push(ts+"->"+(temp->rchild->data));
        }
    }
    return ans;
}



int main()
{
    BiTree<char> a;

    vector<string> v = a.TreePaths();
    for(string n : v) 
    {
        cout << n << '\n';
    }
    a.PreOrderLeaf();
    cout<<endl;
    cout<<a.NodeCount()<<endl;
}


