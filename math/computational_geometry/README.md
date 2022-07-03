# 计算几何
## 概念
    计算几何就是用计算的方式去处理几何问题，相当于把几何用代数的方法处理了。
## 功能
    对几何进行建模计算。计算几何内容广泛，涉及到很多几何元素。
## 模板
```cpp
/*
前置概念：pi = acos(-1);
余弦定理：c^2 = a^2 + b^2 - 2abcos(t);
*/
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
