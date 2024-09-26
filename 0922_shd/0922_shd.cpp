#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int count_strictly_decreasing_subsequences(int n, vector<int>& arr) {
    vector<int> dp(n, 1);  // 每个元素自己构成一个长度为1的严格递减子序列
    long long result = 0;

    // 动态规划计算dp数组
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[i]) {  // 找到比 arr[i] 大的 arr[j]
                dp[i] = (dp[i] + dp[j]) % MOD;  // 更新 dp[i]
            }
        }
    }

    // 所有 dp[i] 的和就是答案
    for (int i = 0; i < n; i++) {
        result = (result + dp[i]) % MOD;
    }

    return result;
}

int main() {
    int n;
    cin >> n;  // 输入数组的长度
    vector<int> arr(n);

    // 输入数组的元素
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 输出结果
    cout << count_strictly_decreasing_subsequences(n, arr) << endl;

    return 0;
}
