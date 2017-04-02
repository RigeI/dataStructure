#include<iostream>
using namespace std;

//操作同顺序表
//实现同链表实现的集合
const int MaxSize=5;
template<class DataType>
class SeqSet{
private:
    DataType data[MaxSize];
    int length;
public:
    SeqSet(){length=0;}
    ~SeqSet(){}
    int Length(){return length;}
    DataType Get(int i){return data[i];}
    bool IsInSet(DataType x);//判断元素是否在集合中
    void Insert(DataType x);
    void Delete(DataType x);
    SeqSet<DataType> Union(SeqSet seqset);//传入集合,返回并集
    SeqSet<DataType> Intersection(SeqSet seqset);//传入集合,返回交集
    SeqSet<DataType> Difference(SeqSet seqset);//差集
    void PrintSet();
};


template<class DataType>
bool SeqSet<DataType>::IsInSet(DataType x){
    for(int i=0;i<length;i++){
        if(data[i]==x)  return true;
    }
    return false;
}

template<class DataType>
void SeqSet<DataType>::Insert(DataType x){
    if(IsInSet(x)){
        //cout<<x<<"已存在"<<endl;
        return;
    }
    if(length==MaxSize){
        //cout<<"集合满"<<endl;
        return;
    }
    data[length++] = x;
}

template<class DataType>
void SeqSet<DataType>::Delete(DataType x){
    int flag=0;
    for(int i=0;i<length;i++){
        if(data[i]==x) flag=1;
        if(flag) data[i]=data[i+1];
    }
    if(flag) length--;
}

template<class DataType>
void SeqSet<DataType>::PrintSet(){
    for(int i=0;i<length;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
}


template<class DataType>
SeqSet<DataType> SeqSet<DataType>::Union(SeqSet OtherSet){
    SeqSet<DataType> resultSeqSet;
    for(int i=0;i<length;i++){
        resultSeqSet.Insert(data[i]);
    }
    for(int i=0;i<OtherSet.Length();i++){
        resultSeqSet.Insert(OtherSet.Get(i));
    }
    return resultSeqSet;
}

template<class DataType>
SeqSet<DataType> SeqSet<DataType>::Intersection(SeqSet OtherSet){
    SeqSet<DataType> resultSeqSet;
    for(int i=0;i<length;i++){
        if(OtherSet.IsInSet(data[i]))
            resultSeqSet.Insert(data[i]);
    }
    return resultSeqSet;
}


template<class DataType>
SeqSet<DataType> SeqSet<DataType>::Difference(SeqSet OtherSet){
    SeqSet<DataType> resultSeqSet;
    for(int i=0;i<length;i++){
        if(!OtherSet.IsInSet(data[i]))
            resultSeqSet.Insert(data[i]);
    }
    return resultSeqSet;
}





int main(){
    /* 集合插入删除操作
    SeqSet<int> seqset;
    seqset.Insert(1);
    seqset.Insert(2);
    seqset.Insert(3);
    seqset.Insert(4);
    seqset.Insert(5);
    seqset.PrintSet();
    seqset.Delete(5);
    seqset.Delete(1);
    seqset.PrintSet();
    */
    

    SeqSet<int> s1;
    SeqSet<int> s2;

    s1.Insert(1);
    s1.Insert(2);
    s1.Insert(3);
    s2.Insert(2);
    s2.Insert(4);
    s2.Insert(5);
    
    cout<<"集合A: ";
    s1.PrintSet();
    cout<<"集合B: ";
    s2.PrintSet();
    
    cout<<"A+B: ";
    SeqSet<int> s3 = s1.Union(s2);
    s3.PrintSet();
    
    cout<<"AB: ";
    SeqSet<int> s4 = s1.Intersection(s2);
    s4.PrintSet();
    
    cout<<"A-B: ";
    SeqSet<int> s5 = s1.Difference(s2);
    s5.PrintSet();
}
