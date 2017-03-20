#include<iostream>
using namespace std;


const int MaxSize=5;
template<class DataType>

//顺序表
//封装数组和数组的操作
class SeqList
{
private:
	DataType data[MaxSize];
	int length;
public:
	SeqList(){length=0;}
	SeqList(DataType a[],int n);
	~SeqList(){}
	int Length(){return length;}
	DataType Get(int i);
	int Locate(DataType x);
	void Insert(int i,DataType x);
	DataType Delete(int i);
	void PrintList();
};

template<class DataType>
SeqList<DataType>::SeqList(DataType a[],int n)
{
	if(n>MaxSize) 
	{
		cout<< "非法参数"<<endl;
	}
	for(int t=0;t<n;t++)
	{
		data[t]=a[t];
	}
	length=n;
}

template<class DataType>
DataType SeqList<DataType>::Get(int i)
{	
	if(i<1||i>length)
	{
		cout<<"查找位置非法"<<endl;

	}
	return data[i-1];
}
template<class DataType>
int SeqList<DataType>::Locate(DataType x)
{	
	for(int t=0;t<length;t++)
	{
		if(data[t]==x) return t+1;
	}
	return 0;
}

template<class DataType>
void SeqList<DataType>::Insert(int i,DataType x)
{
	if(i>MaxSize)
	{
	cout<<"上溢"<<endl;
	}
	if(i<1||i>length+1)	
	{
		cout<<"插入位置错误"<<endl;
	}
	for(int t=length;t>i-1;t--)
	{
		data[t]=data[t-1];
	}
	data[i-1]=x;
	length++;
	
}

template<class DataType>
DataType SeqList<DataType>::Delete(int i)
{
	if(i==0)
	{
	    cout<<"下溢"<<endl;
	}
	if(i<1||i>length)	
	{
		cout<<"删除位置错误"<<endl;
	}
	DataType x=data[i-1];
	for(int t=i-1;t<length;t++)
	{
		data[t]=data[t+1];
	}
	length--;
	return x;
	
}

template<class DataType>
void SeqList<DataType>::PrintList()
{
	for(int t=0;t<length;t++)
	{
		cout<<data[t]<<endl;
	}
}



int main (int argc, char *argv[])
{
    //测试顺序表
    if(true)
    {
    	SeqList<int> s;
		//s.Insert(1,1);
		//s.Insert(2,2);
		//s.Insert(3,3);
		//s.Insert(4,4);
		//s.Insert(5,5);
		s.Insert(1,5);
		s.Insert(1,3);
		s.Insert(2,4);
		s.Insert(1,1);
		s.Insert(2,2);
		//s.PrintList();
		//cout<<s.Length()<<endl;
		//cout<<s.Delete(5)<<endl;
		//cout<<s.Delete(1)<<endl;
		//cout<<s.Delete(2)<<endl;
		//s.PrintList();
		//cout<<s.Locate(1)<<endl;
		//cout<<s.Locate(3)<<endl;
		//cout<<s.Locate(5)<<endl;
		//cout<<s.Get(1)<<endl;
		//cout<<s.Get(3)<<endl;
		//cout<<s.Get(5)<<endl;
		
		int arr[5]={1,2,3,4,5};
		SeqList<int> t(arr,5);
		t.PrintList();
    }	
}	
