#include <iostream>
using namespace std;

const int MAX_STACK_SIZE = 100000;  //設定stack最大容量

int akm(int m, int n) {
    int stackM[MAX_STACK_SIZE];  //分別存取m, n 的stack
    int stackN[MAX_STACK_SIZE];
    
    int top = -1;  //堆疊指標初始化 -1
    
    top++;  //將 m and n 存入
    stackM[top] = m;
    stackN[top] = n;

    while (top >= 0) {  //阿克曼函數的計算
        m = stackM[top];
        n = stackN[top];
        top--;  //彈出頂端的 m and n

        if (m == 0) {
            n = n + 1;
        } else if (n == 0) {
            top++;
            stackM[top] = m - 1;
            stackN[top] = 1;
        } else {
            top++;
            stackM[top] = m - 1;
            stackN[top] = -1;

            top++;
            stackM[top] = m;
            stackN[top] = n - 1;
        }

        if (top >= 0 && stackN[top] == -1) {  //指標 == 0 and n ==-1。結束
            stackN[top] = n;  //用 n 更新結果
        }
    }
    return n;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << akm(m, n) << endl;
    return 0;
}