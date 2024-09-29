#include <iostream>
#include <string>
using namespace std;

int minModifications(int n, const string& s) {
    int modifications = 0;  // 记录需要修改的次数
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {  // 如果相邻字符相同
            ++modifications;     // 修改其中一个字符
            ++i;  // 跳过下一个字符，避免冗余修改
        }
    }
    return modifications;
}

int main() {
    int n;
    string s;

    // 读取输入
    cin >> n >> s;

    // 输出最少的修改次数
    cout << minModifications(n, s) << endl;

    return 0;
}
