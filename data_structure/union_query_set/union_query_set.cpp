#include<iostream>
using namespace std;

int p[N]; //store the father node of erery node.
int size[N]; //store a kind of characteristic of the set.
int d[N]; //store every node's distance to the grandfather.

void init()
{
    for (int i = 1; i <= n; i++){
        p[i] = i; //init the set, and erery node point to itself.
        size[i] = 1;
    }
}

int find(int x) //query the grandfather node of node x.
{
    return x == p[x] ? x : p[x] = find(p[x]);
    //if you use array d, you should implemente the function like this.
    /*if (p[x] != x)
    {
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
    */
}

int join(int a, int b) // join the two set;
{
    p[find(a)] = find(b);
    // p[find(a)] = find(a) is also ok.
    
    d[find(a)] = distance; //accordding to problem situation.
}
int main() {
    return 0;
}
