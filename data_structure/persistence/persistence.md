# 数据结构持久化

## 概念
    数据结构持久化：维护数据结构的多个版本
    可持久化前提：数据结构的拓扑结构在整个操作过程中不变
    例如：trie可持久化，线段树的可持久化——主席树，堆也可以持久化。
          但是平衡树通过自旋改变了数据结构中节点之间的拓扑序，一般不可以持久化
## 功能
    对数据结构常见的操作有修改和查询，持久化可以在修改数据结构时维护多版本，适合对历史版本有要求的场景。（例如支持回滚操作等等）
    做法：不是记录每个版本的所有信息，只记录当前版本和前一个版本不一样的地方。
## 模板
```cpp
// 可持久化Trie
```

```cpp
// 主席树例题：求[l, r]的第k小数
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 100010, M = 10010;

int n, m;
int a[N];
vector<int> nums;

struct Node
{
    int l, r;
    int cnt;
}tr[N * 4 + N * 17];

int root[N], idx;

int find(int x)
{
    return lower_bound(nums.begin(), nums.end(), x) - nums.begin();
}

int build(int l, int r)
{
    int p = ++ idx;
    if (l == r) return p;
    int mid = l + r >> 1;
    tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
    return p;
}

int insert(int p, int l, int r, int x)
{
    int q = ++ idx;
    tr[q] = tr[p];
    if (l == r)
    {
        tr[q].cnt ++ ;
        return q;
    }
    int mid = l + r >> 1;
    if (x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
    else tr[q].r = insert(tr[p].r, mid + 1, r, x);
    tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
    return q;
}

int query(int q, int p, int l, int r, int k)
{
    if (l == r) return r;
    int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
    int mid = l + r >> 1;
    if (k <= cnt) return query(tr[q].l, tr[p].l, l, mid, k);
    else return query(tr[q].r, tr[p].r, mid + 1, r, k - cnt);
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i ++ )
    {
        scanf("%d", &a[i]);
        nums.push_back(a[i]);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    root[0] = build(0, nums.size() - 1);

    for (int i = 1; i <= n; i ++ )
        root[i] = insert(root[i - 1], 0, nums.size() - 1, find(a[i]));

    while (m -- )
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", nums[query(root[r], root[l - 1], 0, nums.size() - 1, k)]);
    }

    return 0;
}
```

