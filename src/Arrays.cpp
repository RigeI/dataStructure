#include<iostream>
using namespace std;

template<class DataType>
class Arrays
{
    private:
        int length,width;
        DataType *arr;
    public:
        Arrays(int length,int width,const DataType *arr);
        ~Arrays();
        DataType get(int x,int y);
        int getLength(){return length;}
        int getWidth(){return width;}
        void set(int x,int y,DataType data);
        void print();
};


template<class DataType>

Arrays<DataType>::Arrays(int length,int width,const DataType *arr)
{
    this->length=length;
    this->width=width;
    this->arr = new DataType[length*width];
    for(int i=0;i<length*width;i++)
    {   
        *(this->arr+i)=*(arr+i);
    }
}

template<class DataType>

Arrays<DataType>::~Arrays()
{
    cout<<"Arrays析构:"<<endl
        <<"数组:\t"<<arr<<endl;

    delete arr;
}


template<class DataType>

DataType Arrays<DataType>::get(int x,int y)
{
    return *(arr+x*width+y);
}


template<class DataType>

void Arrays<DataType>::set(int x,int y,DataType data)
{
    *(arr+x*y+y)=data;
}


template<class DataType>

void Arrays<DataType>::print()
{   
    for(int i=0;i<length*width;i++)
    {
        cout<<*(arr+i)<<" ";
        if((i+1)%width==0)
            cout<<endl;
    }
}


/*
   int main()
   {
   int a[]={1,2,3,4,5,6};
   Arrays<int> b(3,2,a);
   b.print();
   }
   */
