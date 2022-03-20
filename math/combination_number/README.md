# 求组合数
```cpp
//方法1 递推
int C[a][b];
for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
        if (!j) C[i][j] = 1;
        else C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
    }
}

//方法2 预处理逆元法
int qmi(int a, int b, int p) {
    int res = 1 % p;
    while (b) {
        res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
long long fact[N], infact[N];
fact[0] = infact[0] = 1;
for(int i = 1; i < N; i++) {
    fact[i] = (long long)fact[i - 1] * i % MOD;
    infact[i] = (long long)infact[i - 1] * qmi(i, MOD - 2, MOD) % MOD;
}

//方法3 Lucas定理
//若p为素数，则对于任意的整数 1 <= m <= n , 有 C(n, m) = C(n % p, m % p) * C(n / p, m / p) (mod p)
int qmi(int a, int b, int p) //同上
int C(int a, int b, int p) {
    if (a <= b) return 0;
    long long x = 1, y = 1; // 分子x分母y
    for (int i = a, j = 1; j <= b; j++) {
        x = (long long)x * i % p;
        y = (long long)y * j % p;
    }
    return x * (long long)qmi(y, p - 2, p) % p;
}
int lucas(long long a, long long b, int p) {
    if (a < b && b < p) return C(a, b, p);
    else return (long long)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}

//方法4 分解质因数法
//当我们需要求组合数真实值而非取模时，这种方法好用。做法是1.筛法求出范围内所有素数。 2.通过C(a, b) = a! / b! / (a - b)! 求出每个质因子的次数。已知 n!中p的次数为 n / p + n / p^2 + ... 。 3.用高精度方法把所有质因子相乘
int primes[N], cnt;
bool st[N]; //我们用线性筛
int sum[N]; //每个素数出现的次数
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
int get(int n, int p) {
    int res = 0;
    while (n) {
        res += n / p;
        n /= p;
    }
    return res;
}
vector<int> mul(vector<int> a, int b) {
    vector<int> c;
    int t = 0;
    for (int i = 0; i < a.size(); i++) {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t) {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}
get_primes(a); //预处理所有素数
for (int i = 0; i < cnt; i++) { //求每个素数出现的次数
    int p = primes[i];
    sum[i] = get(a, p) - get(b, p) - get(a - b, p);
}
vector<int> res;
res.push_back(1);
for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < sum[i]; j++) {
        res = mul(res, primes[i]);
    }
}
```
```cpp
//常见的组合数及其求法
//斐波那契数 f[i] = f[i - 1] + f[i - 2] (i >= 3) f[1] = f[2] = 1;

//卡特兰数
//给定n个0和n个1，他们按照某种顺序排成长度为2n的序列，满足任意前缀中0的个数都不少于1的个数的序列的数量为： Cat(n) = C(2n, n) / (n + 1);

//斯特林数
/*
第一类斯特林数: s(n, m):表示选n个不同元素中的m个来构成圆排列的方案数(无符号第一类斯特林数) s[n][m] = s[n - 1][m - 1] + (n - 1) * s[n - 1][m];
s[0][0] = 1;
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        s[i][j] = (s[i - 1][j - 1] + (long long)(i - 1) * s[i - 1][j]) % MOD;
第一类斯特林数的很多性质 待补充
*/
/*
第二类斯特林数: S(n, m):表示将n个不同的元素分成m个集合的方案数 S[n][m] = S[n - 1][m - 1] + k * S[n - 1][m];
S[0][0] = 1;
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        S[i][j] = (S[i - 1][j - 1] + (long long)j * S[i - 1][j]) % MOD;

 */
```
