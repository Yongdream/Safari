#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAXN = 100;
const int INF = 1e9;

struct State {
    int x, y, steps;
    int value;
    State(int x, int y, int steps, int value) : x(x), y(y), steps(steps), value(value) {}
};

int n, m, k;
vector<vector<int>> a(MAXN, vector<int>(MAXN));
vector<vector<vector<int>>> maxValue(MAXN, vector<vector<int>>(MAXN, vector<int>(MAXN, -INF)));

int getValue(int i, int j) {
    return j + i * m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        cin >> n >> m >> k;

        // Initialize grid and maxValue array
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                a[i][j] = getValue(i, j);
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                fill(maxValue[i][j].begin(), maxValue[i][j].end(), -INF);
            }
        }

        queue<State> q;
        q.push(State(0, 0, 0, a[0][0]));
        maxValue[0][0][0] = a[0][0];

        int directions[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

        while (!q.empty()) {
            State cur = q.front();
            q.pop();

            int x = cur.x, y = cur.y, steps = cur.steps, value = cur.value;

            if (steps >= k) continue;

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    int newValue = value + a[nx][ny];
                    if (newValue > maxValue[nx][ny][steps + 1]) {
                        maxValue[nx][ny][steps + 1] = newValue;
                        q.push(State(nx, ny, steps + 1, newValue));
                    }
                }
            }
        }

        int result = -INF;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int step = 0; step <= k; ++step) {
                    result = max(result, maxValue[i][j][step]);
                }
            }
        }
        cout << result << endl;
    }

    return 0;
}
