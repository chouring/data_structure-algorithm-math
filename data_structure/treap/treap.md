# Treap
## 概念
    Treap是一种平衡树，是满足堆性质的BST，Treap = tree + heap
## 功能
    高效维护一个数据集，提供增删改查接口
## 模板
```cpp
/*
Binary search tree is simply called "BST"
It is defined that every value of left subtree node is less than every value of right subtree node. 
It has one character, it's inorder traversal is monotonic increasing.
It's usage is to dynamically maintain ordered sequence.
And there are some basic operations about this data structure.
The first one is to insert a node, the second one is to delete a node, the third one is to find the node who has the largest or smallest value, the third one is to find the precursor and successor of a node. These four operations are also included in "set", who has the "insert, earse, begin, end , ++ , --" and so on.
There are four more operations.
The first one is to find the rank of a node's value.
The second one is to find the number that ranks k-th.
The third one is to find the largest number during the number below a node value.
The last ont is to find the smallest number during the number above a node value.
But, the treap is including the BST, so This code directly implements the treap.
*/

#include<iostream>
using namespace std;

struct Node {
    int l, r; //two kids
    int key; //as a BST
    int val; // as a heap
    int cnt; //counting the appearing time
    int size; //counting the number of node
}tr[N];
int root; //root node
int idx; //allocate node index

void pushup(int p)
{
    tr[p].size = tr[tr[p].l].size + tr[tr[p].r].size + tr[p].cnt;
}

int get_node(int key) //create a new node
{
    tr[++idx].key = key;
    tr[idx].val = rand();
    tr[idx].cnt = tr[idx].size = 1;
    return idx;
}

void build() //create the treap
{
    get_node(-INF), get_node(INF);
    root = 1, tr[1].r = 2;
}

void zig (int &p) //dextral
{
    int q = tr[p].l;
    tr[p].l = tr[q].r;
    tr[q].r = p;
    p = q;
    pushup(tr[p].r);
    pushup(p);
}

void zag(int &p)
{
    int q = tr[p].r;
    tr[p].r = tr[q].l;
    tr[q].l = p;
    p = q;
    pushup(p);
    pushup(tr[p].l);
}

void insert(int &p, int key)
{
    if (!p) p = get_node(key);
    else if (tr[p].key == key) tr[p].cnt++;
    else if (tr[p].key > key) {
        insert(tr[p].l, key);
        if (tr[tr[p].l].val > tr[p].val) zig(p);
    }
    else {
        insert(tr[p].r, key);
        if (tr[tr[p].r].val > tr[p].val) zag(p);
    }
    pushup(p);
}

void remove(int &p, int key)
{
    if (!p) return;
    else if (tr[p].key == key)
    {
        if (tr[p].cnt > 1) tr[p].cnt--;
        else if (tr[p].l || tr[p].r) {
            if (!tr[p].r || tr[tr[p].l].val > tr[tr[p].r].val) {
                zig(p);
                remove(tr[p].r, key);
            }
            else {
                zag(p);
                remove(tr[p].l, key);
            }
        }
        else p = 0;
    }
    else if (tr[p].key > key) remove(tr[p].l, key);
    else remove(tr[p].r, key);
    pushup(p);
}

int get_rank_by_key(int &p, int key) {
    if (!p) return 0;
    if (tr[p].key == key) return tr[tr[p].l].size + 1;
    if (tr[p].key > key) return get_rank_by_key(tr[p].l, key);
    else return get_rank_by_key(tr[p].r, key) + tr[tr[p].l].size + tr[p].cnt;
}

int get_key_by_rank(int &p, int rank) {
    if (!p) return INF;
    if (tr[tr[p].l].size >= rank) return get_key_by_rank(tr[p].l, rank);
    if (tr[tr[p].l].size + tr[p].cnt >= rank) return tr[p].key;
    else return get_key_by_rank(tr[p].r, rank - tr[tr[p].l].size -tr[p].cnt;
}

int get_prev(int &p, int key) {
    if (!p) return -INF;
    if (tr[p].key >= key) return get_prev(tr[p].l, key);
    return max(tr[p].key, get_perv(tr[p].r, key));
}

int get_next(int &p, int key) {
    if (!p) return INF;
    if (tr[p].key <= key) return get_next(tr[p].r, key);
    return min(tr[p].key, get_next(tr[p].l, key));
}

int main() {
    return 0;
}


```
