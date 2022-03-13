/*
There are two ordinary ways to store a graph.
The first one is "adjacency table", another is "adjacency matrix".
*/

#include<iostream>
using namespace std;
const int N = 1e3; // the number of point
const int M = 1e5; // the number of edge
int h[N], e[M], ne[M], idx; //if u don't know what it means, please turn to "../list"
void add(int a, int b) { //add an edge which from a to b
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
//initialize
void init() {
    idx = 0;
    memset(h, -1, sizeof h);
}

int main(){
    return 0;
}

//the above is "adjacency table". Because "adjacency matrix" is so easy, I don't implement it here right now.
