# low bit算法
## 概念

## 功能
    求一个数的二进制表示中的最后一个1
## 模板
```cpp
#include<iostream>

using namespace std;


//返回x的二进制表示的第k位是0 or 1
int get_k(int x, int k) {
    return x >> k & 1;
}

//x的二进制表示下的第一位1对应数
int lobit(int x) {
    return x & -x;
}

//返回x二进制表示中1的个数
int cnt1(int x) {
    int res = 0;
    while (x) {
        x -= lowbit(x);
        res++;
    }
    return res;
}

int main() {
    return 0;
}
```
