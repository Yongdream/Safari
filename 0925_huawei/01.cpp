//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <unordered_set>
//
//using namespace std;
//
//const int MAX_CON = 1000;
//vector<int> graph[1001];
//unordered_set<int> visited[1001];
//queue<pair<int, int>> que;
//
//
//int bfs(int N, int M, int K, vector<pair<int, int>> conn) {
//	for (const auto& otherUser : conn) {
//		graph[otherUser.first].push_back(otherUser.second);
//		graph[otherUser.second].push_back(otherUser.first);
//	}
//
//	int infl = 0;
//	que.push({ M, 0 });
//
//	while (!que.empty()) {
//		auto& fronte = que.front();
//		auto [current_node, depth] = fronte;
//		que.pop();
//		if (visited->count(current_node)) {
//
//		}
//
//	}
//
//
//}
//
//
//int main() {
//	int N, M, K;
//	cin >> N >> M >> K;
//	vector<pair<int, int>> conn(N);
//
//	for (int i = 0; i < N; ++i) {
//		cin >> conn[i].first >> conn[i].second;
//	}
//
//	cout << bfs(N, M, K, conn) << endl;
//
//	return 0;
//}