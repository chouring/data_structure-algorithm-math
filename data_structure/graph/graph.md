# 图的数据结构
    图的常见存储方式：邻接表，邻接矩阵。
```cpp
#include<iostream>
using namespace std;
const int N = 1e3; 
const int M = 1e5; 
int h[N], e[M], ne[M], idx; 
void add(int a, int b) { 
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

void init() {
    idx = 0;
    memset(h, -1, sizeof h);
}

int main(){
    return 0;
}

```
