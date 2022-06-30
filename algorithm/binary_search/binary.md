# 二分
## 概念
  
## 功能
    当某个变量随另一个变量单调变化时，可以在O(logn)时间内找到“性质的边界”
## 模板
```cpp
#include<iostream>
using namespace std;


bool check(int bound){
    //验证逻辑
};
int binary_search(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1; // mid = l + r + 1 >> 1;
        if (check(mid)) r = mid; // l = mid;
        else l = mid + 1; //r = mid - 1;
    }
    return l;
}
const double EPS = 1e-7; //比要求精度至少多2位
double binary_search(double l, double r) {
    while (r - l > EPS) {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid; l = mid; 看逻辑而定
        else l = mid; //r = mid;
    }
    return l;
}

int main() {
    //an example
    int a[10] = {1, 4, 7, 9, 10, 22, 42, 55, 76, 88};
    int res;
    res = binary_search(0, 9);
    return 0;
}
```
