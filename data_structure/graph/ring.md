# 判环
    环在图论中是个特殊的存在形式，分析很多问题时必须考虑特殊情况，存在环就是一种常见的特殊情况。
## 概念
    正/负环：环的边权和为正数/负数的环，称为正/负环。
## 功能
    顾名思义，判断是否存在负环/正环，常用spfa算法
## 模板
```cpp
#include<bits/stdc++.h>
using namespace std;
const int N = 100010, M = 300010;

typedef long long ll;

int n, m;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
int q[N], cnt[N]; // 求正环
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c;
    ne[idx] = h[a], h[a] = idx++;
}

// 存在负环返回false, 不存在返回true
bool spfa() { 
    int front = 0, back = 1;
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;
    q[0] = 0;
    st[0] = true;
    while (front != back) {
        int t = q[--back];   // 可以用栈，也可以循环队列。
        //if (front == N) front = 0;
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] < dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n + 1) return false;
                if (!st[j]) {
                    q[back++] = j;
                   // if (back == N) back = 0;
                    st[j] = true;
                }
            }
        }
    }
    return true;
}
```
