# 差分约束
## 概念
    定义：形如Xi <= Xj + C 的不等式，称为 简单不等式。
    对于任意的简单不等式，我们可以将其视为从Xj到Xi，权值为C的一条边，这样就构建起了差分约束和最短路的一一映射。最终把差分约束问题转化为最短路问题。
    不等式链：Xi <= Xj + C1 <= Xk + C2 + C1 .... <= X0 + ∑Ck = ∑Ck, 一条不等式链就对应了一条从X0到Xi的路径。
## 功能
    1. 求简单不等式组的可行解
        1）将Xi <= Xj + C, 转化为 从Xj到Xi的一条边权为C的边；将 Xi <= C 转化为 Xi <= 0 + C, 转化为从 0（一个超级源点） 到 Xi 的边
        2）找一个源点：该源点可以到达所有的点
        3）做一遍最短路/最长路（如果存在负环 等价于 不等式组无解；如果不存在负环，则得到原不等式的一组可行解）
    2. 求简单不等式组的最优解（每个变量的 最大值 or 最小值）
        如果求最小值，则用最长路；如果求最大值，则用最短路。最长路对应>=符号，最短路对应<=符号。
        以求Xi的最大值为例：和Xi相关的所有不等式链，最终Xi_max = min(所有上界)
## 模板
```cpp
// 往往是把题目条件转化为不等式组约束，然后用差分约束。
#include<bits/stdc++.h>
using namespace std;
const int N = 100010, M = 300010;

typedef long long ll;

int n, m;
int h[N], e[M], ne[M], w[M], idx; // 邻接表存储
int dist[N];
int q[N], cnt[N]; // 求正环
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c;
    ne[idx] = h[a], h[a] = idx++;
}

// 判环，是差分约束中的一个重要步骤
bool spfa() {
    int front = 0, back = 1;
    memset(dist, -0x3f, sizeof dist);
    dist[0] = 0;
    q[0] = 0;
    st[0] = true;
    while (front != back) {
        int t = q[--back];
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



int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    while (m--) {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1) add(a, b, 0), add(b, a, 0);  // 不同条件的不等式，根据具体题目处理输入输出
        else if (x == 2) add(a, b, 1);
        else if (x == 3) add(b, a, 0);
        else if (x == 4) add(b, a, 1);
        else add(a, b, 0);
    }
    for (int i = 1; i <= n; i++) add(0, i, 1);
    if (!spfa()) puts("-1");
    else {
        ll res = 0;
        for (int i = 1; i <= n; i++) res += dist[i];  // 每个dist[i]都是最小值，res是最小值的和
        cout << res << endl;
    }
    return 0;
}
```
