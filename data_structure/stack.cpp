#include<isotream>
using namespace std;

const int N = 1e5; 
int stk[N], top = -1;

void push(int x) {
    stk[++top] = x;
}

void pop() {
    top--;
}

bool is_empty() {
    return top == -1;
}

int main(){
    return 0;
}
