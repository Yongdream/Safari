#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool canCompleteRace(int L, int m, int b, const vector<int>& obstacles) {
    // ���ϰ�����������ִ��뼯���У�������ٲ���
    unordered_set<int> obstacleSet;
    for (int a : obstacles) {
        obstacleSet.insert(a);
    }

    int currentPos = 0; // ����� 0 ��ʼ
    for (int i = 0; i < m; i++) {
        currentPos += b; // ÿ����Ծ b �ľ���

        // �����Ծ�Ƿ�������ϰ���ϰ���Ϊ a_i + 0.5����Ծֻ��������λ�ã�
        if (obstacleSet.count(currentPos - 1) > 0 || obstacleSet.count(currentPos) > 0) {
            return false; // �����ǰλ�����ϰ��ﷶΧ�ڣ����ز�����
        }

        // ������һ����Ծ�������յ㣬ֱ�ӷ��ز�����
        if (currentPos > L) {
            return false;
        }
    }

    // ����Ƿ����õ����յ� L
    return currentPos == L;
}

int main() {
    int T;
    cin >> T; // ����������ݵ�����
    while (T--) {
        int n, L, m, b;
        cin >> n >> L >> m >> b; // ���� n, L, m, b
        vector<int> obstacles(n);
        for (int i = 0; i < n; i++) {
            cin >> obstacles[i]; // ����ÿ���ϰ������������
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
