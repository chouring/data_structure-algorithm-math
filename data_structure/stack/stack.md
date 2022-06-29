# 栈

## 概念
    一种先进后出的线性结构
## 功能
    First in, last out
## 模板
```cpp
#include<isotream>
using namespace std;

const int N = 1e5; 
int stk[N], top = -1;

void push(int x) {
    stk[++top] = x;
}

void pop() {
    top--;
}

bool is_empty() {
    return top == -1;
}

/*
//the increasing or decreasing stack,a common apply situation is that query which number in an array is larger than and closest to this number in the left of the number. Same as the smaller,or in the right...
int top = -1;
for (int i = 1; i <= n; i++)
{
    while (top != -1 && check[stk[top], i)) top--;
    stk[++top] = i;
}
*/
int main(){
    return 0;
}
```
