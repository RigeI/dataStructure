#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class TreeNode{
    public:
        int val;
        TreeNode *left,*right;
        TreeNode(int val){
            this->val=val;
            this->left=this->right=NULL;
        }
};

class BST{
    private:
        TreeNode *root;
        TreeNode *sortedArrayToBST(vector<int> &A);
        void InOrder(TreeNode *);
        void PreOrder(TreeNode *);
        TreeNode* Insert(TreeNode*,int);
    public:
        BST(vector<int> &A){root=sortedArrayToBST(A);}
        void InOrder (){InOrder(root);}
        void PreOrder(){PreOrder(root);}
        void LeverOrder();
        void Insert(int x){Insert(root,x);}
};

TreeNode* BST::sortedArrayToBST(vector<int> &A){
    if(!A.size()) return NULL;
    int mid=A.size()/2;
    TreeNode *s=new TreeNode(A[mid]) ;
    if(mid>0){
        vector<int> left(A.begin(),A.begin()+mid);
        s->left=sortedArrayToBST(left);
    }
    if(mid+1<A.size()){
        vector<int> right(A.begin()+mid+1,A.end());
        s->right=sortedArrayToBST(right);
    }
    return s;
}

TreeNode* BST::Insert(TreeNode *root,int x)
{
    if(!root) root = new TreeNode(x);
    else if(root->val>x) root->left=Insert(root->left,x);
    else root->right=Insert(root->right,x);
    return root;

}

void BST::InOrder(TreeNode *root){
    if(!root) return;
    else{
        InOrder(root->left);
        cout<<root->val<<" ";
        InOrder(root->right);
    }
}

void BST::PreOrder(TreeNode *root){
    if(!root) return;
    else{
        cout<<root->val<<" ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void BST::LeverOrder(){
    if(!root) return;
    queue< TreeNode * > q;
    TreeNode *temp;
    q.push(root);
    while(!q.empty()){
        temp=q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}




int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    BST bst(v);
    bst.InOrder();
    cout<<endl;
    bst.LeverOrder();
    cout<<endl;
    
    bst.Insert(3);
    bst.Insert(0);
    bst.Insert(4);
    
    bst.InOrder();
    cout<<endl;
    bst.LeverOrder();
    cout<<endl;

}
