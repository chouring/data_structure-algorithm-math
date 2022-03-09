# 区间合并
把一堆离散区间合并为几个大区间
做法是按照左端点排序，然后顺序遍历的同时维护一个当前区间。当无交集时开始维护下一个区间。

```cpp
typedef pair<int, int> pii;

void merge_segs(vector<pii>& segs) {
    vector<pii> res;
    sort(segs.begin(), segs.end()); //默认按照左端点排序
    int l = -2e9, r = -2e9;//所维护的区间
    for(auto seg : segs) {
        int curl = seg.first, curr = seg.second;
        if (l < curl) { //无交集
            res.push_back(seg);
            l = curl, r = curr;
        }
        else r = max(r, curr);
    }
    if (l != -2e9) res.push_back({l, r}); //最后一个
    segs = res; //引用参数带回调用处
}
```
