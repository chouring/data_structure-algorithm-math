# 搜索算法

```cpp
//1. dfs
void dfs(/*状态参数*/) {
    //终点条件
    //剪枝
    //维护条件
    /*扩展*/ {
        if (/*符合条件*/) dfs(/*下一个状态*/)
    }
    //回溯条件
}

//2. bfs
void bfs() {
    //队列，判重数组
    //初始点入队
    //当队列不空时循环，取队头扩展元素，符合条件的放入队列并标记
}

//3. 模拟退火
const double DELTA = 0.95; //调参
void simulate_anneal() {
    for (double t = 1e6; t >= 1e-6; t *= DELTA) {
        //1.找个新状态
        //2.计算新状态下的答案，经常需要写calc函数
        //3.dt = new_ans - old_ans;
        //4.判断，常用exp(-dt / t) > (double)rand();
    }
}
for (int i = 1; i <= 100; i++) simulate_anneal();

```
