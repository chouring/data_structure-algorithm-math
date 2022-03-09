# 离散化 
当只用到某个大区间上的一个小区间，例如[-1e8, 1e8]上我们确定只有1e4个数时，可以离散化


有两种映射方式，第一种：自己实现
```cpp
vector<int> alls; //所有待离散化的值，在操作，查询中的各个位置涉及到的数都算进去
sort(alls.begin(), alls.end()); //排序
alls.erase(unique(alls.begin(), alls.end()), alls.end()); //去重

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1;//映射到1,2,3...
    //return r; 映射到0,1,2...
}
```
第二种：利用map实现
```cpp
//map可以帮我们维护一个有序映射
```
