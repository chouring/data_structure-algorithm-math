# Splay

## 概念

## 功能

## 模板
```cpp
/*
the core of splay is that we swing the node to the root whenever we insert or query. splay(x, k) is to swing x to the behind of k. And other operations are based on splay function.
*/
#include<iostream>
using namespace std;

struct Node {
    int s[2], p, v; //sons and father
    int size; // the size of subtree.
    int flag; //if inversed.
    void init(int _v, int _p) {
        v = _v, p = _p;
        size = 1;
    }
}tr[N];
int root, idx;
void pushup(int x) {
    tr[x].size = tr[tr[x].s[0]].size + tr[tr[u].s[1]].size + 1;
}
void pushdown(int x) {
    if (tr[x].flag) {
        swap(tr[x].s[0], tr[x].s[1]);
        tr[tr[x].s[0]].flag ^= 1;
        tr[tr[x].s[1]].flag ^= 1;
        tr[x].flag = 0;
    }
}
void rotate(int x) {
    int y = tr[x].p;
    int z = tr[y].p;
    int k = tr[y].s[1] == x;
    tr[z].s[tr[z].s[1] == y] = x, tr[x].p = z;
    tr[y].s[k] = tr[x].s[k ^ 1], tr[tr[x].s[k ^ 1]].p = y;
    tr[x].s[k ^ 1] = y, tr[y].p = x;
    pushup(y), pushup(x);
}
void splay(int x, int k) {
    while (tr[x].p != x) {
        int y = tr[x].p, z = tr[y].p;
        if (z != k) {
            if ((tr[y].s[1] == x) ^ (tr[z].s[1] == y)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if (!k) root = x;
}
void insert(int x) {
   int u = root, p = 0;
   while (u) p = u, u = tr[u].s[v > tr[u].v];
   u = ++idx;
   if (p) tr[p].s[v > tr[p].v] = u;
   tr[u].init(v, p);
   splay(u, 0);
}

int get_k(int k) {
    int u = root;
    while (1) {
        pushdown(u);
        if (tr[tr[u].s[0]].size >= k) u = tr[u].s[0];
        else if (tr[tr[u].s[0]].size + 1 == k) return u;
        else k -= tr[tr[u].s[0]] + 1, u = tr[u].s[1];
    }
    return -1;
}
void output(int u) { 
    pushdown(u);
    if (tr[u].s[0]) output(tr[u].s[0]);
    if (tr[u].v >= 1 && tr[u] <= n) printf("%d ", tr[u].v);
    if (tr[u].s[1]) output(tr[u].s[1]);
}

int main() {
    return 0;
}

```
