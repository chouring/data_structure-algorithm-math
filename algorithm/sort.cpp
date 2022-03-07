#include<iostream>
#include<vector>
using namespace std;
const int N = 1e3+10;

void quick_sort(int a[], int l, int r) {
    if (l >= r) return;
    int i = l - 1, j = r + 1, target = a[l + r >> 1];
    while (i < j) {
        do i++; while (a[i] < target);
        do j--; while (a[j] > target);
        if (i < j) swap(a[i], a[j]);
    }
    quick_sort(a, l, j), quick_sort(a, j + 1, r);
    return;
}

void merge_sort(int a[], int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(a, l, mid), merge_sort(a, mid + 1, r);
    int i = l, j = mid + 1;
    vector<int> b;
    int dex = 0;
    while (i <= mid && j <= r) {
        if (a[i] > a[j]) b[dex++] = a[j++];
        else b[dex++] = a[i++];
    }
    while (i <= mid) b[dex++] = a[i++];
    while (j <= r) b[dex++] = a[j++];
    return;
}



int main() {
    int n,m,a[N];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    quick_sort(a, 0, n - 1);
    //merge_sort(a, 0, n - 1);
    return 0;
}
