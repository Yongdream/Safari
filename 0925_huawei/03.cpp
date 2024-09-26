//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//const int MAX_CON = 1000;
//vector<int> graph[1001];
//bool visited[1001];
//int social_inf[1001];
//
//void bfs(int beg, int k) {
//	queue<pair<int, int>> que;
//	que.push({ beg, 0 });
//	visited[beg] = true;
//	social_inf[beg] = 1;
//
//	while (!que.empty() && que.front().second <= k) {
//		int cur = que.front().first;
//		int lev = que.front().second;
//		que.pop();
//
//		for (int otherUser : graph[cur]) {
//			if (!visited[otherUser]) {
//				visited[otherUser] = true;
//				social_inf[otherUser] = 1;
//				que.push({ otherUser, lev + 1 });
//				if (lev + 1 <= k) {
//					social_inf[beg] += 1;
//				}
//			}
//		}
//	}
//
//
//}
//
//
//int main() {
//	int N, M, K;
//	cin >> N >> M >> K;
//
//	for (int i = 0; i < N; ++i) {
//		int X, Y;
//		cin >> X >> Y;
//		graph[X].push_back(Y);
//		graph[Y].push_back(X);
//	}
//
//	for (int i = 0; i <= MAX_CON; ++i) {
//		visited[i] = false;
//		social_inf[i] = 0;
//	}
//
//	bfs(M, K);
//	cout << social_inf[M] - 1 << endl;
//
//	return 0;
//}