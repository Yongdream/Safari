#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool canCompleteRace(int L, int m, int b, const vector<int>& obstacles) {
    // 将障碍物的整数部分存入集合中，方便快速查找
    unordered_set<int> obstacleSet;
    for (int a : obstacles) {
        obstacleSet.insert(a);
    }

    int currentPos = 0; // 从起点 0 开始
    for (int i = 0; i < m; i++) {
        currentPos += b; // 每次跳跃 b 的距离

        // 检查跳跃是否会碰到障碍物（障碍物为 a_i + 0.5，跳跃只能在整数位置）
        if (obstacleSet.count(currentPos - 1) > 0 || obstacleSet.count(currentPos) > 0) {
            return false; // 如果当前位置在障碍物范围内，返回不可行
        }

        // 如果最后一次跳跃超过了终点，直接返回不可行
        if (currentPos > L) {
            return false;
        }
    }

    // 检查是否正好到达终点 L
    return currentPos == L;
}

int main() {
    int T;
    cin >> T; // 输入测试数据的组数
    while (T--) {
        int n, L, m, b;
        cin >> n >> L >> m >> b; // 输入 n, L, m, b
        vector<int> obstacles(n);
        for (int i = 0; i < n; i++) {
            cin >> obstacles[i]; // 输入每个障碍物的整数坐标
        }

        if (canCompleteRace(L, m, b, obstacles)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }

    return 0;
}
