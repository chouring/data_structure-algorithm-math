# AC自动机
## 概念
    AC自动机 = Trie + KMP，当串用string存储的话，就用KMP去匹配，但是串用Trie存的话，就用AC自动机去匹配。
    KMP和AC自动机是一维和多维的区别。
    AC自动机每一条从根节点到叶节点的链，都类似于KMP的字符串。AC自动机对每条链的后缀，都从所有前缀中，找到一个最长的，记录下节点
## 功能
   一个s串，多个p串，做字符串匹配
## 模板
```cpp
void insert()
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int t = str[i] - 'a';
        if (!tr[p][t]) tr[p][t] = ++ idx;
        p = tr[p][t];
    }
   // 做处理
}

void build()
{
    int hh = 0, tt = -1;
    for (int i = 0; i < 26; i ++ )
        if (tr[0][i])
            q[ ++ tt] = tr[0][i];

    while (hh <= tt)
    {
        int t = q[hh ++ ];
        for (int i = 0; i < 26; i ++ )
        {
            int p = tr[t][i];
            if (!p) tr[t][i] = tr[ne[t]][i];
            else
            {
                ne[p] = tr[ne[t]][i];
                q[ ++ tt] = p;
            }
        }
    }
}
```
