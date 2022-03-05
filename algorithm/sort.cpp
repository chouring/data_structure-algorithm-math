#include<iostream>
using namespace std;
const int N = 1e3+10;

void quick_sort(int a[], int l, int r) {
    
}




int main() {
    int n,m,a[N];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    quick_sort(a, 0, n - 1);
    //merge_sort(a, 0, n - 1);
    return 0;
}
