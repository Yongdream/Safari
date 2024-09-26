#include <iostream>
#include <vector>

using namespace std;

int elsBlock(int x, int y, vector<vector<int>>& grid) {
	int n = grid.size();
	if (x + 1 < n && y + 1 < n && grid[x][y] == 0 && grid[x][y+1] == 0 && grid[x+1][y] == 0 && grid[x + 1][y + 1] == 0) {
		return true;
	}
	return false;
}


int main() {
	int n, k;
	int res = 0;
	cin >> n >> k;
	vector<pair<int, int>> block(k);
	vector<vector<int>> grid(n, vector<int>(n, 0));

	for (int i = 0; i < k; ++i) {
		int x, y;
		cin >> y >> x;
		grid[y][x] = 1;
	}

	for(int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			if (elsBlock(x, y, grid)) {
				grid[x][y] = 1;
				grid[x][y + 1] = 1;
				grid[x + 1][y] = 1;
				grid[x + 1][y + 1] = 1;
				res++;
			}
		}
	}
	cout << res << endl;

	return 0;
}