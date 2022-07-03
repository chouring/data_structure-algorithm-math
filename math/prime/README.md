# 质数
## 概念
    质数：因数只有1和本身的数
## 功能
    质数处理相关的算法
## 模板
```cpp
// 试除法 判断质数，时间复杂度O(sqrt(n))
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
```


```cpp
// 暴力求所有质数及其次数
void divide(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int s = 0;
            while (x % i == 0) x /= i, s++;
            //cout << "the prime " << i << "counts " << s << endl;
        }
    }
    if (x > 1) cout << "the prime " << i << "counts " << 1 << endl;
}
```

```cpp
// 筛法求质数 
int primes[N], cnt;
bool st[N];
void get_primes(int n) {  //brute-force
    for (int i = 2; i <= n; i++) {
        if (st[i]) continue;
        primes[cnt++] = i;
        for (int j = i + 1; j <= n; j++) {
            st[j] = true;
        }
    }
}

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
```


