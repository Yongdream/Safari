#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canAchieve(const vector<int>& a, int n, int k, int l, int mid) {
    vector<int> increments(n, 0); // 存储需要的增加量
    vector<int> delta(n + 1, 0); // 差分数组，用于计算区间增量
    int current_increase = 0; // 当前窗口内的总增量
    int trains_used = 0; // 记录训练次数

    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            current_increase += delta[i]; // 加上之前增量
        }
        if (a[i] + current_increase < mid) {
            int increase_needed = mid - (a[i] + current_increase);
            if (i + l <= n) {
                delta[i] += increase_needed;
                delta[i + l] -= increase_needed;
                current_increase += increase_needed;
                ++trains_used;
                if (trains_used > k) return false;
            }
        }
    }
    return true;
}

//int main() {
//    int n, k, l;
//    cin >> n >> k >> l;
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//
//    int left = *min_element(a.begin(), a.end());
//    int right = *max_element(a.begin(), a.end()) + 1;
//    int result = left;
//
//    while (left < right) {
//        int mid = left + (right - left) / 2;
//        if (canAchieve(a, n, k, l, mid)) {
//            result = mid;
//            left = mid + 1;
//        }
//        else {
//            right = mid;
//        }
//    }
//
//    cout << result - 1 << endl;
//    return 0;
//}
