#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 定义一个结构体来存储每个队员的信息
struct Player {
    int id; // 队员编号
    int goals; // 进球总数
    int maxConsecutive; // 最多连续进球数
    vector<int> shots; // 射门记录
    vector<int> missIndices; // 射失的索引列表

    // 自定义比较函数，用于排序
    bool operator<(const Player& other) const {
        if (goals != other.goals)
            return goals > other.goals;
        if (maxConsecutive != other.maxConsecutive)
            return maxConsecutive > other.maxConsecutive;
        // 比较射失的顺序
        for (size_t i = 0; i < min(missIndices.size(), other.missIndices.size()); ++i) {
            if (missIndices[i] != other.missIndices[i])
                return missIndices[i] > other.missIndices[i];
        }
        // 如果射失次数相同，则射失次数更多的队员更强
        if (missIndices.size() != other.missIndices.size())
            return missIndices.size() > other.missIndices.size();
        // 如果以上都相同，则编号小的队员更强
        return id < other.id;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Player> players(n);

    // 读取每个队员的射门记录
    for (int i = 0; i < n; ++i) {
        string shots;
        cin >> shots;
        players[i].id = i + 1;
        players[i].shots.resize(m);
        for (int j = 0; j < m; ++j) {
            players[i].shots[j] = shots[j] - '0';
            if (players[i].shots[j] == 0) {
                players[i].missIndices.push_back(j);
            }
        }
        // 计算进球总数
        players[i].goals = count(players[i].shots.begin(), players[i].shots.end(), 1);
        // 计算最多连续进球数
        int currentStreak = 0, maxStreak = 0;
        for (int j = 0; j < m; ++j) {
            if (players[i].shots[j]) {
                currentStreak++;
                maxStreak = max(maxStreak, currentStreak);
            }
            else {
                currentStreak = 0;
            }
        }
        players[i].maxConsecutive = maxStreak;
    }

    // 对队员进行排序
    sort(players.begin(), players.end());

    // 输出排序后的结果
    for (const auto& player : players) {
        cout << player.id << " ";
    }
    cout << endl;

    return 0;
}