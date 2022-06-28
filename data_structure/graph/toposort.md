# 拓扑排序

## 概念
    拓扑序：在有向图按照有向边的顺序对点进行排序，得到拓扑序，可以理解为一种依赖关系的依赖顺序。
    
## 功能
    求一个图的拓扑序列。
    每次更新出度为0的点。

## 模板
```cpp
#include<iostream>
using namespace std;

int q[N], front = 0, back = -1; //the queue
int d[N]; //the in-degree of every node

bool toposort() {
    for (int i = 1; i <= n; i++) { // push the 0 in-degree nodes in queue
        if (!d[i]) q[++back] = i;
    }
    while (front <= back) {
        int t = q[front++];
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (--d[i] == 0) q[++back] = j;
        }
    }
    return back == n - 1; // if all nodes from 0 to n - 1 is inqueue, the graph has tpo sequence, or it don't.
}

int main() {
    return 0;
}
```
