#include <iostream>
using namespace std;

long long ack[10][100000] = {0}; //設定 m,n 計算過程的上限

long long akm (int m, int n) {
    if(ack[m][n] != 0) {
        return ack[m][n];   //如果(m, n)計算過的話回傳結果
    }

    if(m == 0) ack[m][n]=n+1;   //阿克曼函數的計算
    else if(n == 0) ack[m][n]=akm(m-1, 1);
    else ack[m][n]=akm(m-1,akm(m, n-1));
    cout << ack[m][n] << endl;
    return ack[m][n];
}

int main(int argc, char const *argv[])
{
    int m, n;
    cin >> m >> n;
    cout << akm(m, n);
    return 0;
}
