# 最小生成树
## 概念
    首先，最小生成树是针对无向图而言的。
    连通图：任意两点都可达的无向图。
    极小连通图：一个图的所有连通图中，边权和最小的那一个。
    最小生成树：对于一个连通图，在包含所有节点的一个极小连通图。
## 功能
    求把所有节点都连通的最小花费的场景
## 模板
```cpp
// Prim算法
int n, m;
int g[N][N];
int dist[N];
bool st[N];


int prim()
{
    memset(dist, 0x3f, sizeof dist);

    int res = 0;
    for (int i = 0; i < n; i ++ )
    {
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == INF) return INF;

        if (i) res += dist[t];
        st[t] = true;

        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
    }

    return res;
}
```

```cpp
// kruskal算法
int n, m;
int p[N];

struct Edge
{
    int a, b, w;

    bool operator< (const Edge &W)const
    {
        return w < W.w;
    }
}edges[M];

int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal()
{
    sort(edges, edges + m);

    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集

    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ )
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

        a = find(a), b = find(b);
        if (a != b)
        {
            p[a] = b;
            res += w;
            cnt ++ ;
        }
    }

    if (cnt < n - 1) return INF;
    return res;
}
```
```cpp
/*
返回值为INF, 则无最小生成树；否则返回值为最小生成树的权值和
*/
```
