# 差分
## 概念
    对于序列a, b[i] = a[i] - a[i - 1], 则序列b称为序列a的差分序列
## 功能
    差分序列可以在O(1)内标记对原序列的修改，最后再用O(n)时间对差分序列求前缀和，可以得到修改后的原序列
## 模板
```cpp
#include<iostream>

using namespace std;
/*
一维差分
int a[N], b[N];
for (int i = 1; i <= n; i++) b[i] = a[i] - a[i - 1];
b[r + 1] -= c, b[l] += c;
for (int i = 1; i <= n; i++) a[i] = a[i - 1] + b[i];
*/

/*
int g[N][N], b[N][N];
void modify(int x1, int y1, int x2, int y2, int c) {
    b[x1][y1] += c;
    b[x2 + 1][y2 + 1] += c;
    b[x1][y2 + 1] -= c;
    b[x2 + 1][y1] -= c;
}
modify(x1, y1, x2, y2, c);
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        g[i][j] = b[i][j] + g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
*/
```
