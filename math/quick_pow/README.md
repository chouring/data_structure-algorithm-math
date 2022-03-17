# 快速幂相关

```cpp
//quick_pow 快速幂 O(logb)时间求 a ^ b % p
int qmi(int a, int b, int p) {
    int res = 1 % p;
    while (b) {
        if (b & 1) res = (long long)res * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }
    return res;
}

//slow_multiple 龟速乘 用于处理快速幂中乘法溢出问题
int smul(int a, int b, int p) {
    int res = 0;
    while (b) {
        if (b & 1) res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}

//matrix quick pow 矩阵快速幂
//把快速幂中的乘法展开写成矩阵乘法
//一道例题：斐波那契数列 求Sn % m;
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3;
int n,m;
void mul(ll c[],ll a[],ll b[][N]){
    ll temp[N]={0};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            temp[i]=(temp[i]+a[j]*b[j][i])%m;
        }
    }
    memcpy(c,temp,sizeof temp);
}
void mul(ll c[][N],ll a[][N],ll b[][N]){
    ll temp[N][N]={0};
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                temp[i][j]=(temp[i][j]+a[i][k]*b[k][j])%m;
            }
        }
    }
    memcpy(c,temp,sizeof temp);
}
int main(){
    cin>>n>>m;
    ll f1[N]={1,1,1};
    ll a[N][N]={
        {0,1,0},
        {1,1,1},
        {0,0,1}
    };
    n--;
    while(n){
        if(n&1) mul(f1,f1,a);
        mul(a,a,a);
        n>>=1;
    }
    cout<<f1[2]<<endl;
    return 0;
}

```
