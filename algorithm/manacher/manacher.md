# manacher算法
## 概念

## 功能
    求最长回文串
    
## 模板
```cpp
//query the longest palindromic substring.

#include<iostream>
using namespace std;

int p[N];
char a[N], b[N];
int n;
void init()
{
    int k = 0;
    b[k++] = '$', b[k++] = '#';
    for (int i = 0; i < n; i++) b[k++] = a[i], b[k++] = '#';
    b[k++] = '^';
    n = k;
}
void manacher()
{
    int mr = 0, mid;
    for (int i = 1; i < n; i++) 
    {
        if (i < mr) p[i] = min(p[mid * 2 - i], mr - i);
        else p[i] = 1;
        while (b[i - p[i]] == b[i + p[i]]) p[i]++;
        if (i + p[i] > mr)
        {
            mr = i + p[i];
            mid = i;
        }
    }
}
int main(){
    //first, handle the input.
    init();
    n = strlen(a);
    manacher();
    return 0;
}
```
