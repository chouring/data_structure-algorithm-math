# 链表

## 概念
    链式存储的线性结构
## 功能
    适合频繁修改操作的线性结构
## 模板
```cpp
#include<iostream>
using namespace std;

//the single list
int head, e[N], ne[N], idx;
void init()
{
    head = -1, idx = 0;
}
void insert()
{
    e[idx] = x, ne[idx] = head, head = idx++;
}
void remove()
{
    head = ne[head];
}

//two-way list
int e[N], l[N], r[N], idx;
void init()
{
    r[0] = 1, l[1] = 0, idx = 2;
}
void insert(int a, int x) //insert a node whose value is x at the right of node a
{
    e[idx] = x;
    l[idx] = a;
    r[idx] = r[a];
    l[r[idx]] = idx, r[a] = idx++;
}
void remove(int a) //remove node a
{
    l[r[a]] = l[a];
    r[l[a]] = r[a];
}
int main()
{
    return 0;
}
```
