#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

class Map{
private:
    int m[9][9];

public:
    void init();
    int get(int n);
    int get(int x,int y);
    void set(int n,int value);
    void set(int x,int y,int value);
    void show();
};

class Sudoku{
private:
    /* 定义地图 */
    Map m;
    /* 保存状态 */
    stack<Map> s;
    /* 判断在(x,y)点放value是否冲突 */
    bool conflict(const int x,const int y,const int value);
    /* 不冲突的个数 */
    int numOfNoConflict(const int x,const int y);
    /* 不冲突的值是几 */
    int valueOfNoConflict(const int x,const int y);
    /* 保存当前图状态 */
    void save();
    /* 恢复图状态 */
    void restore();
    /* 标识成功 */
    bool success();
    /* 一定失败 */
    bool wrong();    
    /* 基于数独定义的填表 */
    bool strategy1();
    bool strategy2();
    /* 假定某个点的值,并继续填表,如果出现错误,则回退到一正确状态 */
    bool strategy3();
    
    /* 该row行能放value的位置数 */
    int numOfThisRowCanPutValue(int value,int row);
    /* 配合上个函数,在row行放置value */
    void putValueOnThisRow(int value,int row);
    
    /* 该列能放value的位置数 */
    int numOfThisColCanPutValue(int value,int col);
    /* 在col列放置value */
    void putValueOnThisCol(int value,int col);

    /* 该块能放value的位置数 */
    int numOfThisBlockCanPutValue(int value,int block);
    /* 在block放置value */
    void putValueOnThisBlock(int value,int block);

    /* 返回一个高效的广度优先搜索的遍历次序 */
    vector<int> sortedValues();
    /* 获取value可填写的所有位置 */
    queue<pair<int,int> > allLocateOfValues(int value);

public:
    void init();
    void show();
    void solve();
};

int main(){
    Sudoku sudoku;
    sudoku.init();
    sudoku.solve();
    sudoku.show();
}

void Sudoku::init(){
    m.init();
}

bool Sudoku::conflict(const int x,const int y,const int value){
    if(m.get(x,y)>0){
        return true;
    }

    for(int i=0;i<9;i++){
        if(m.get(x,i)==value||m.get(i,y)==value){
            return true;
        }
    }

    for(int i=3*(x/3);i<3*(x/3)+3;i++){
        for(int j=3*(y/3);j<3*(y/3)+3;j++){
            if(m.get(i,j)==value){
                return true;
            }
        }
    }
    return false;
}

int Sudoku::numOfNoConflict(const int x,const int y){
    int num=0;
    for(int i=1;i<=9;i++){
        if(!conflict(x,y,i)){
            num++;
        }
    }
    return num;
}

int Sudoku::valueOfNoConflict(const int x,const int y){
    for(int i=1;i<=9;i++){
        if(!conflict(x,y,i)){
            return i;
        }
    }
    return -1;
}

void Sudoku::show(){
    m.show();
}


int Sudoku::numOfThisRowCanPutValue(int value,int row){
    int cnt=0;
    for(int col=0;col<9;col++){
        if(!conflict(row,col,value)){
            cnt++;
        }
    }
    return cnt;
}

int Sudoku::numOfThisColCanPutValue(int value,int col){
    int cnt=0;
    for(int row=0;row<9;row++){
        if(!conflict(row,col,value)){
            cnt++;
        }
    }
    return cnt;
}

int Sudoku::numOfThisBlockCanPutValue(int value,int block){
    int cnt=0;
    int x=3*(block/3);
    int y=3*(block%3);

    for(int row=x;row<x+3;row++){
        for(int col=y;col<y+3;col++){
            if(!conflict(row,col,value)){
                cnt++;
            }
        }
    }
    return cnt;
}

void Sudoku::putValueOnThisRow(int value,int row){
    for(int col=0;col<9;col++){
        if(!conflict(row,col,value)){
            m.set(row,col,value);
        }
    }
}

void Sudoku::putValueOnThisCol(int value,int col){
    for(int row=0;row<9;row++){
        if(!conflict(row,col,value)){
            m.set(row,col,value);
        }
    }
}

void Sudoku::putValueOnThisBlock(int value,int block){
    
    int x=3*(block/3);
    int y=3*(block%3);

    for(int row=x;row<x+3;row++){
        for(int col=y;col<y+3;col++){
            if(!conflict(row,col,value)){
                m.set(row,col,value);
            }
        }
    }
}

bool Sudoku::strategy1(){
    bool change=false;
    int flag=1;
    while(flag){
        flag=0;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(numOfNoConflict(i,j)==1){
                    flag=1;
                    change=true;
                    m.set(i,j,valueOfNoConflict(i,j));
                    continue;
                }
            }
        }
    }
    return change;
}

bool Sudoku::strategy2(){
    bool change=false;
    int flag=1;
    while(flag){
        flag=0;
        for(int value=1;value<=9;value++){
            for(int row=0;row<9;row++){
                if(numOfThisRowCanPutValue(value,row)==1){
                    flag=1;
                    change=true;
                    putValueOnThisRow(value,row);
                }
            }
            for(int col=0;col<9;col++){
                if(numOfThisColCanPutValue(value,col)==1){
                    flag=1;
                    change=true;
                    putValueOnThisCol(value,col);
                }
            }
            for(int block=0;block<9;block++){
                if(numOfThisBlockCanPutValue(value,block)==1){
                    flag=1;
                    change=true;
                    putValueOnThisBlock(value,block);
                }
            }
        }
    }
    return change;
}

bool Sudoku::strategy3(){
    vector<int> values=sortedValues();
    if(values.size()==0) return true;
    queue<pair<int,int> > q = allLocateOfValues(values[0]);

    while(!q.empty()){ 
        pair<int,int> p=q.front();
        q.pop();
        save();
        m.set(p.first,p.second,values[0]);
        while(strategy1()||strategy2());
        if(success()){
            return true;
        }else if(wrong()){
            restore();
        }else{
            bool state=strategy3();
            if(!state){
                restore();
            }
        }
    }
    return false;
}

struct PAIR{
    int first;
    int second;
    PAIR(int first,int second){
        this->first=first;
        this->second=second;
    }
};

bool cmp(const PAIR p1,const PAIR p2){
    return p1.second>p2.second;
}


vector<int> Sudoku::sortedValues(){
    vector<int> ret;
    map<int,int> t;

    for(int i=0;i<81;i++){
        t[m.get(i)]++;
    }

    vector<PAIR> v;
    for(map<int,int>::iterator it=t.begin();it!=t.end();it++){
        v.push_back(PAIR((*it).first,(*it).second));
    }
    sort(v.begin(),v.end(),cmp);

    for(vector<PAIR>::iterator it=v.begin();it!=v.end();it++){
        if((*it).second==9||(*it).first==0){
            continue;
        }
        ret.push_back((*it).first);
    }
    return ret;
}

queue<pair<int,int> > Sudoku::allLocateOfValues(int value){
    queue<pair<int,int> > v;
    pair<int,int> p;
    for(int i=0;i<81;i++){
        if(!conflict(i/9,i%9,value)){
            p.first=i/9;
            p.second=i%9;
            v.push(p);
        } 
    }
    return v;
}

void Sudoku::save(){
    Map t;
    for(int i=0;i<81;i++){
        t.set(i,m.get(i));
    }
    s.push(t);
}

void Sudoku::restore(){
    Map t=s.top();
    for(int i=0;i<81;i++){
        m.set(i,t.get(i));
    }
    s.pop();
}

bool Sudoku::success(){
    int sum=0;
    for(int i=0;i<81;i++){
        sum+=m.get(i);
    }
    if(sum==450){
        return true;
    }else{
        return false;
    }

}

bool Sudoku::wrong(){
    for(int i=0;i<81;i++){
        int x=i/9;
        int y=i%9;
        if(!(m.get(i)||numOfNoConflict(x,y))){
            return true;
        }
    }
    return false;
}

void Sudoku::solve(){
    while(strategy1()||strategy2());
    strategy3();
}

int Map::get(int n){
    int x=n/9;
    int y=n%9;
    return m[x][y];
}

int Map::get(int x,int y){
    return m[x][y];
}

void Map::set(int n,int value){
    int x=n/9;
    int y=n%9;
    m[x][y]=value;
}

void Map::set(int x,int y,int value){
    m[x][y]=value;
}

void Map::init(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>m[i][j];
        }
    }
}

void Map::show(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(get(i,j)){
                cout<<get(i,j)<<" ";
            }else{
                cout<<"  ";
            }
            if(j!=8&&j%3==2){
                cout<<"|";
            }
        }
        cout<<endl;
        if(i!=8&&i%3==2){
            cout<<"--------------------"<<endl;
        }
    }
}

