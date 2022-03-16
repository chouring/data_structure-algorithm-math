# 约数相关
```
//试除法求约数
vector<int> get_divisors(int x) {
    vector<int> res;
    for (int i = 1; i <= x; i++) {
        if (x % i) {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i); //不是平方数就把俩数都加进来
        }
    }
    sort(res.begin(), res.end());
    return res;
}

//求约数个数
//如果 N = p1 ^ c1 * p2 ^ c2 * ... * pk ^ ck , 则约数个数为 (c1 + 1) * (c2 + 1) * ... * (ck + 1)


//求约数之和
//如果 N = p1 ^ c1 * p2 ^ c2 * p3 ^ c3 * ... * pk ^ck, 则约数之和为(p1 ^ 0 + p1 ^ 2 + ... + p1 ^ c1) * ... * (pk ^ 0 + pk ^ 1 + ... + pk ^ k);

//求最大公约数
typedef long long ll;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;};

```


