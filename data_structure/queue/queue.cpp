//the content of notes is the loop queue.


#include<iostream>
using namespace std;

int q[N], front = 0, back = -1;
void push(int x)
{
    q[++back] = x;
    //if (back == N) back = 0;
}
void pop()
{
    front++;
    //if (front == N) front = 0;
}
void get_front()
{
    return q[front];
}
bool empty()
{
    return front <= back; //return front == back;
}
int main()
{
    return 0;
}
