#include <iostream>
#include <cstring>
using namespace std;

//遞歸函數生成冪集
void powerset(char set[], string current, int index, int setSize) {
    if (index == setSize) {  //處理完所有元素，列印當前子集
        cout << "{" << current << "}" << endl;
        return;
    }
    //結果1. 不把元素放入子集，處理下一個
    powerset(set, current, index + 1, setSize);

    //結果2. 把當前元素放入子集，處理下一個
    if (!current.empty()) {
        current += ", ";
    }
    current += set[index];  //加入當前元素
    powerset(set, current, index + 1, setSize);
}

int main() {
    cout << "input S element total: ";
    int n;cin >> n;

    char s[n];
    for(int i = 0;i < n;i++) cin >> s[i];

    cout << "powerset:" << endl;
    powerset(s, "", 0, n);

    return 0;
}