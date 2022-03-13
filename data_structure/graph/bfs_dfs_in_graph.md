# bfs in adjacency table

```
const int N = 1e3; // the number of point
bool st[N];
void dfs(int u) {
    st[u] = true;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}
```

```
void bfs(){
    queue<int> q;
    st[1] = true; // the first node inqueue
    q.push(1);
    while (q.size()) {
        int t = q.front();
        q.pop();
        for (int i = h[t]; ~i; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                st[j] = true;
                q.push(j);
            }
        }
    }
}
```
