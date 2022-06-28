# 最短路
## 概念
    最短路：某条路径的边权之和最小
    单源最短路：从一个给定点到另一个给定点的最短路
    多源汇最短路：一群点中的任意一个点到另一个人任意点的最短路。
## 功能
    求最短/最长路，关键在于建模，如何抽象出点和边。
    常见的最短路算法有dijkstra 朴素/堆优化版，bellman-ford，spfa(优化版bellman-ford)，floyd
    
## 模板
```cpp
#include<iostream>
using namespace std;

//the simple dijkstra, which is based on greedy algorithm
//O(n^2 + m) time, is often used in compact graph, we use adjacency matrix to represent.
int g[N][N];
int dist[N]; //the shortest distance from 1 to i;
bool st[N]; 

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1) || dist[t] > dist[j]) t = j;
        }
        for (int j = 1; j <= n; j++) 
            dist[j] = min(dist[j], dist[t] + g[t][j];
        st[t] = true;
    }
    if (dist[n] == 0x3f3f3f3f) return -1; // from 1 to n, there is no shortest path.
    else return dist[n];
}

//dijksra promoted by heap. O(mlogn) time, is often used in sparse graph, so we use adajency table to store it.
typedef pair<int, int> pii;
int n;
int h[N], w[N], e[N], ne[N];
int dist[N]; //distance array
bool st[N];
int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, 1});
    while (heap.size()) {
        pii t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > distance + w[i]) {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f) return -1;
    else return dist[n];
}

//bellman-ford algorithm, which is O(nm) time, is based on dynamic programming. We can directly use sturct to store it.
int n, m;
int dist[N];
struct Edge {
    int a, b, w;
}edges[M];
int bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if (dist[b] > dist[a] + w) dist[b] = dist[a] + w;
        }
    }
    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}

//spfa, which is seemed as the promoting version of bellman_ford algorithm, Using average O(n), worst O(n*m) time. We use adjacency table.
int n;
int h[N], ne[N], e[N], w[N], idx;
int dist[N];
bool st[N];

int spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;
    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

//We can use spfa to judge if a graph has a circle whose sum of nodes is negative.
int n;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
int cnt[N]; 
bool st[N];
int spfa[N];

bool spfa() {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        st[i] = true;
    }
    while (q.size()) {
        auto t = q.front();
        q.pop();
        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[t] + w[i]) {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true;
                if (!st[j]) {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

//floyd algorithm, based on dynamic programming, use O(n^3) time
const int INF = 1e9;
void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
}

void floyd() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
}


int main() {
    return 0;
}
```
