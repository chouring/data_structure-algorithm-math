# 求强连通分量

## 概念
    连通分量：对于一个有向图的子图的u, v,既能从u->v,也能从v->u,则称该子图为原图的一个连通分量。
    强连通分量：极大连通分量.
    tarjan算法对于每个点定义两个时间戳：dfn[u]是遍历到u的时间戳，low[u]是从u开始走的子树能遍历到的最小时间戳。 
    （此定义下满足，dfn[u] == low[u] 等价于 u是强连通分量的“最高点”。）
## 功能
    将 有向图 转化为 有向无环图。
    方式是：1. tarjan 2. 缩点。 3. 有向无环图的好处是求最短路可以直接递推，并且其他很多问题在拓扑图上很好做。
## 模板
```cpp
/*
tarjan
1. 分配时间戳
2. 
*/

void tarjan(int u)
{
    dfn[u] = low[u] = ++ timestamp;   
    stk[ ++ top] = u, in_stk[u] = true;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
    }

    if (dfn[u] == low[u])
    {
        ++ scc_cnt;
        int y;
        do {
            y = stk[top -- ];
            in_stk[y] = false;
            id[y] = scc_cnt;
            Size[scc_cnt] ++ ;
        } while (y != u);
    }
}

```
