# KMP算法
## 概念
    kmp算法是一个字符串匹配算法
## 功能
    对线性存储的字符串进行匹配，O(n)时间复杂度
## 模板
```cpp
#include<iostream>
using namespace std;

string s, p;
int n , m;
int ne[N];//the next array
void get_next()
{
    for(int i = 2, j = 0; i <= m; i++)
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j++;
        ne[i] = j;
    }
}

void kmp(string s, string p)
{
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j++;
        if (j == m)
        {
            j = ne[j];
            //succeed, do what you want.
        }
    }
}
int main()
{
    cin >> s >> p;
    s = " " + s, p = " " + p; //index begins from 1 is easier for kmp algorithm.
    n = s.size(), m = p.size();
    kmp(s, p);
    return 0;
}
```
