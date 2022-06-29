# 堆
## 概念
    堆中某个结点的值总是不大于或不小于其父结点的值；堆总是一棵完全二叉树。
## 功能
    动态维护最值
## 模板
```cpp
#include<iostream>
using namespace std;
int h[N]; //store the value, h[1] is the top of the heap, the left kid of h[i] is h[2 * i], and the right kid of h[i] is h[2 * i + 1].
int ph[N], hp[N]; //a pair of mapping. ph[k] means the location in the heap of the node which is k-th insert.And the hp[k] means the inverse.
int size;

void heap_swap(int a, int b)
{
    swap(ph[hp[a]], ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}
void down(int u) //function down
{
    int t = u;
    if (u * 2 <= size && h[2 * u] < h[t]) t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t) {
        heap_swap(u, t);
        down(t);
    }
}
void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

int main()
{
    for (int i = n / 2; i; i--) down(i); // use O(n) time to init the heap.
    return 0;
}
```
