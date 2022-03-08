#include<iostream>
using namespace std;

const int N = 1e5;
/*
一维前缀和
int a[N], s[N];
for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
for (int i = 1; i <= n; i++) a[i] += a[i - 1];

int query(int l, int r) {
    return s[r] - s[l - 1];
}
*/



/*
二维前缀和
int g[N][N], s[N][N];
for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= m; j++) {
        s[i][j] = g[i][j] + s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1];
    }

for (int i = 1; i <= n; i++) 
    for (int j = 1; j <= m; j++) {
        g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
    }

int query(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}
*/

