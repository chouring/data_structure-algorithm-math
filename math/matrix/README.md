# 高斯消元
## 概念
    一种解矩阵方程的算法
    
## 功能
    解矩阵方程/解异或方程
## 模板
```cpp
//高斯消元
int a[N][N]; //增广矩阵
int gauss() {
    int c, r;
    for (c = 0, r = 0; c < n; c++) {
        int t = r;
        for (int i = r; i < n; i++) { //找绝对值最大的那个
            if (fabs(a[i][c]) > fabs(a[t][c])) t= i;
        }
        if (fabs(a[t][c]) < EPS) continue; // == 0
        for (int i = c; i <= n; i++) swap(a[t][i], a[r][i]); //最大行交换
        for (int i = n; i >= c; i--) a[r][i] /= a[r][c]; //顶部行变成1
        for (int i = r + 1; i < n; i++) {
            if (fabs(a[i][c]) > EPS) {
                for (int j = n; j >= c; j--) {
                    a[i][j] -= a[r][j] * a[i][c];
                }
            }
        }
        r++;
    }
    if (r < n) {
        for (int i = r; i < n; i++) {
            if (fabs(a[i][n]) > EPS) return -1; //无解
        }
        return 2; //无穷多组解
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            a[i][n] -= a[i][j] * a[j][n];
        }
    }
    return 1; // 有唯一解

}
```
