# 字典树
## 概念
    
## 功能
    提供(key:string, val:)的映射，也可以视为一种对字符串增删改查的高效数据结构。
## 模板
```cpp
#include<iostream>
using namespace std;

int son[N][26], cnt[N], idx; //son[i][j] represent the j-th son node of the node i; cnt[i] represent the number of the word which is end with node i;

void insert(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
    }
    cnt[p]++;
}

int query(string s)
{
    int p = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int u = s[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
int main()
{
    //logical work
    return 0;
}
```
