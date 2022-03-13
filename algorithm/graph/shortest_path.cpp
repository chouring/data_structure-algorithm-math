#include<iostream>
using namespace std;

//the simple dijkstra, which is based on greedy algorithm
//O(n^2 + m) time, is often used in compact graph, we use adjacency matrix to represent.
int g[N][N];
int dist[N]; //the shortest distance from 1 to i;
bool st[N]; 

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1) || dist[t] > dist[j]) t = j;
        }
        for (int j = 1; j <= n; j++) 
            dist[j] = min(dist[j], dist[t] + g[t][j];
        st[t] = true;
    }
    if (dist[n] == 0x3f3f3f3f) return -1; // from 1 to n, there is no shortest path.
    else return dist[n];
}












int main() {
    return 0;
}
