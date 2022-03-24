# 自适应辛普森积分
取两端点和横坐标中间点这三个点去搞一条抛物线去拟合原抛物线，积分算面积公式：s[a, b] = f(a) + 4 * f((a+b)/2) + f(b) * (b - a) / 6
自适应：根据精度EPS要求自适应地去递归
精度有点玄学，可能需要调

```cpp
const double EPS = 1e-12;
double f(double x) {}
double simpson(double l, double r) {
    auto mid = (l + r) / 2;
    return (r - l) * (f(l) + 4 * f(mid) + f(r)) / 6;
}
double asr(double l, double r, double s) {
    auto mid = (l + r) / 2;
    auto left = simpson(l, mid), right = simpson(mid, r);
    if (fabs(left + right - s) < EPS) return left + right;
    else return asr(l, mid, left) + asr(mid, r, right);
}
ans = asr(l, r, simpson(l, r));
```
