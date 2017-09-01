# 哈密顿回路问题

# 判断是否满足哈密顿回路
def is_connected(_list,city_map):
    
    for i in range(len(_list)-1):
        if city_map[_list[i]][_list[i+1]] == 0:
            return False
    
    if city_map[_list[len(_list)-1]][0] == 0:
        return False
    
    return True

# 全排列算法
def perm(_list, k, m, city_name,city_map):
    # 只输出满足哈密顿回路的排列
    if k==m and is_connected(_list,city_map):
        for i in _list:
            print(city_name[i],end=" ")
        print()
    for i in range(k,m):
        _list[k],_list[i]=_list[i],_list[k]
        perm(_list, k+1, m,city_name,city_map)
        _list[k],_list[i]=_list[i],_list[k]


# 哈密顿回路,化简调用
def hamilton(city_name,city_map):
    perm(list(range(len(city_name))),1,len(city_name),city_name,city_map)
 

# 城市名 
city_name = ['1','2','3','4','5']

# 临界矩阵表示图
city_map = [
    [0,1,1,1,0],
    [1,0,1,0,1],
    [1,1,0,1,0],
    [1,0,1,0,1],
    [0,1,0,1,0]
    ]


hamilton(city_name,city_map)
