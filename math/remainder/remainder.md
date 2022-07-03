# 余数相关

## 概念
    中国剩余定理/孙子定理：形如 x 同余 ak (mod mk)  1 <= k <= n, 且mi和mj两两互质。
                         如果令M = m1 * m2 * ... * mn, Mi = M / mi, ti = Mi关于M的逆元。
                         则，x = 从1到n∑ai * Mi * ti
## 功能
    和同余方程相关
    
      
## 模板
```cpp
// 孙子定理
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 10;

int n;
int A[N], B[N];

// 扩展欧几里得求逆元
void exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b) x = 1, y = 0;
    else
    {
        exgcd(b, a % b, y, x);
        y -= a / b * x;
    }
}

int main()
{
    scanf("%d", &n);

    LL M = 1;
    for (int i = 0; i < n; i ++ )
    {
        scanf("%d%d", &A[i], &B[i]);
        M *= A[i];
    }

    LL res = 0;
    for (int i = 0; i < n; i ++ )
    {
        LL Mi = M / A[i];
        LL ti, x;
        exgcd(Mi, A[i], ti, x);
        res += B[i] * Mi * ti;
    }

    cout << (res % M + M) % M << endl;

    return 0;
}
```
