#include <iostream>
#include <set>
#include <vector>
using namespace std;

int max_toys(int n, long long m, vector<int>& owned_toys) {
    set<int> owned_set(owned_toys.begin(), owned_toys.end());  // 将已有的玩具编号存入集合
    long long money_left = m;  // 剩余的钱
    int count = 0;  // 能购买的玩具数量

    // 从价格1开始，尝试购买玩具
    for (int price = 1; price <= 1e9; ++price) {
        if (owned_set.count(price)) {
            continue;  // 跳过已有的玩具
        }
        if (money_left < price) {
            break;  // 如果剩余的钱不够买这个玩具，退出循环
        }
        money_left -= price;  // 扣除购买的玩具价格
        ++count;  // 增加购买的玩具数量
    }

    return count;
}

//int main() {
//    int n;
//    long long m;
//
//    cin >> n >> m;
//    vector<int> owned_toys(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> owned_toys[i];
//    }
//
//    // 计算并输出结果
//    cout << max_toys(n, m, owned_toys) << endl;
//
//    return 0;
//}
