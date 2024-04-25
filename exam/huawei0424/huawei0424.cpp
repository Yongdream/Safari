#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ����һ���ṹ�����洢ÿ����Ա����Ϣ
struct Player {
    int id; // ��Ա���
    int goals; // ��������
    int maxConsecutive; // �������������
    vector<int> shots; // ���ż�¼
    vector<int> missIndices; // ��ʧ�������б�

    // �Զ���ȽϺ�������������
    bool operator<(const Player& other) const {
        if (goals != other.goals)
            return goals > other.goals;
        if (maxConsecutive != other.maxConsecutive)
            return maxConsecutive > other.maxConsecutive;
        // �Ƚ���ʧ��˳��
        for (size_t i = 0; i < min(missIndices.size(), other.missIndices.size()); ++i) {
            if (missIndices[i] != other.missIndices[i])
                return missIndices[i] > other.missIndices[i];
        }
        // �����ʧ������ͬ������ʧ��������Ķ�Ա��ǿ
        if (missIndices.size() != other.missIndices.size())
            return missIndices.size() > other.missIndices.size();
        // ������϶���ͬ������С�Ķ�Ա��ǿ
        return id < other.id;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Player> players(n);

    // ��ȡÿ����Ա�����ż�¼
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
        // �����������
        players[i].goals = count(players[i].shots.begin(), players[i].shots.end(), 1);
        // �����������������
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

    // �Զ�Ա��������
    sort(players.begin(), players.end());

    // ��������Ľ��
    for (const auto& player : players) {
        cout << player.id << " ";
    }
    cout << endl;

    return 0;
}