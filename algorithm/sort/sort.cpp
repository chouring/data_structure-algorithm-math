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

int quick_search_Kth(int a[], int l, int r, int k)
{
    if (l == r) return a[l];
    int x = a[l + r >> 1], i = l - 1, j = r + 1;
    while (i < j) {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if (i < j) swap(a[i], a[j]);
    }
    
   if (k <= j - l + 1) return quick_search_Kth(a, l, j, k);
   else return quick_search_Kth(a, j + 1, r, k - (j - l + 1));
}


void merge_sort(int a[], int l, int r) {
    if (l >= r) return;
    int mid = l + r >> 1;
    merge_sort(a, l, mid), merge_sort(a, mid + 1, r);
    int i = l, j = mid + 1;
    vector<int> b;
    int dex = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) b[dex++] = a[i++];
        else {
            //res += mid - i + 1; //求逆序对
            b[dex++] = a[j++];
        }
    }
    while (i <= mid) b[dex++] = a[i++];
    while (j <= r) b[dex++] = a[j++];
    //return res;
}



int main() {
    int n,m,a[N];
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    quick_sort(a, 0, n - 1);
    //merge_sort(a, 0, n - 1);
    return 0;
}
