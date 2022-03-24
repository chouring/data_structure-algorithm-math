# 计算几何
前置概念：pi = acos(-1);
余弦定理：c^2 = a^2 + b^2 - 2abcos(t);
```cpp
//浮点数比较
const double EPS = 1e-8;
int sign(double x) { //符号函数
    if (fabs(x) <= eps) return 0;
    else if (x < 0) return -1;
    else return 1;
}
int cmp(double x, double y) { 
    if (fabs(x - y) < EPS) return 0;
    else if (x < y) return -1;
    else return 1;
}
//向量相关
待补充

```
