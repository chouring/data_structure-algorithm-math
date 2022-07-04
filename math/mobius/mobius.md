# 莫比乌斯


## 概念
    莫比乌斯函数
![图片](https://user-images.githubusercontent.com/75822806/177068412-ee72a1bc-46b8-4603-a136-fe759bd780f7.png)
    
    
## 功能
    求和n互质的数的个数
    
## 模板
```cpp
// 线性筛求莫比乌斯函数
void getMobius(int n) {
    mobius[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])
        {
            primes[cnt ++ ] = i;
            mobius[i] = -1;
        }
        for (int j = 0; primes[j] * i <= n; j ++ )
        {
            int t = primes[j] * i;
            st[t] = true;
            if (i % primes[j] == 0)
            {
                mobius[t] = 0;
                break;
            }
            mobius[t] = mobius[i] * -1;
        }
    }
}
```
