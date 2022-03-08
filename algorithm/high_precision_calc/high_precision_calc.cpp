#include<iostream>
#include<vector>

using namespace std;

string A, B;
vector<int> a, b, c;

void init();
vector<int> add(vector<int>& a, vector<int>& b);
vector<int> sub(vector<int>& a, vector<int>& b);
vector<int> mul(vector<int>& a, vector<int>& b);
vector<int> div(vector<int>& a, vector<int>& b);

int main() {
    init();
    c = add(a, b);
    c = sub(a, b);
    c = mul(a, b);
    int r;
    c = div(a, b, r);
    return 0;
}

void init() {
    for (int i = A.size() - 1; i >= 0; i--) {
        a.push_back(A[i] - '0');
    }
    for (int i = B.size() - 1; i >= 0; i--) {
        b.push_back(B[i] - '0');
    }
}

vector<int> add(vector<int>& a, vector<int>& b) {
    int t = 0;
    vector<int> res;
    for (int i = 0; i < a.size() || i < b.size(); i++) {
        if (i < a.size()) t += a[i];
        if (i < b.size()) t += b[i];
        res.push_back(t % 10);
        t /= 10;
    }
    if (t) c.push_back(t);
    return res;
}

vector<int> sub(vector<int>& a, vector<int>& b) {
    if (check(a, b)) return sub(b, a);
    int t = 0;
    vector<int> res;
    for (int i = 0; i < a.size(); i++) {
        t += a[i];
        if (i < b.size()) t -= b[i];
        c.push_back((t + 10) % 10);
        if(t < 0) t = 1;
        else t = 0;
    }
    while (c.size() > 1 && c.back() == 0) c.pop_back();
    return res;
}

vector<int> mul(vector<int>& a, vector<int>& b) {
    int t = 0;
    vector<int> res;
    for (int i = 0; i < a.size(); i++) {
        t += a[i] * b;
        c.push_back(t % 10);
        t /= 10;
    }
    while (t) c.push_back(t % 10), t /= 10;
    return res;
}

vector<int> div(vector<int>& a, int b, int& r) {
    vector<int> res;
    r = 0;
    for (int i = a.size() - 1; i >= 0; i--) {
        r = r * 10 + a[i];
        res.push_back(r / b);
        r %= b;
    }
    reverse(res.begin(), res.end());
    while (res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

