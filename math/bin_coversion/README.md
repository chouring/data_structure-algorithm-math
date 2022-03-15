# 进制转换
```
int get(string s, int b) { //b based to Decimal 
    int res = 0;
    for (auto c : s) res = res * b + c - '0';
    //return to_string(res);
    return res;
}

string get(string s, int b) //Decimal to b-base
{
    string res;
    int n = atoi(s);
    while (n) {
        if (cur >= 10) res += cur - 10 + 'A';
        else res += cur - '0';
        n /= b;
    }
    reverse(res.begin(), res.end());
    return res;
}
```
