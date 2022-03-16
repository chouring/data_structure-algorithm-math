# 欧拉函数

```
//求欧拉函数
//1.定义法
int phi(int x) {
    int res = x;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) res = res / x * (x - 1);
    return res;
}

//2.筛法
int primes[N], cnt;
bool st[N]; // 附带线性筛法
int phi[N];
void get_eulers(int n) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] * i <= n; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = primes[j] * phi[i];
                break;
            }
        }
        phi[primes[j] * i] = phi[i] * (primes[j] - 1);
    }
}

```
