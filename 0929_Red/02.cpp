#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

bool isgg(long long a, long long b, long long c) {
	return a * a + b * b == c * c;
}

long long sumTr(const vector<long long>& vec) {
	return vec[0] + vec[1] + vec[2];
}




int main() {
	int q;
	cin >> q;
	vector<vector<int>> triples;

	/*for (int a = 1; a <= 10000; ++a) {
		for (int b = a + 1; b < 10000; ++b) {
			int c = sqrt(a * a + b * b);
			if (isgg(a, b, c)) {
				triples.push_back({ a, b, c });
			}
		}
	}

	sort(triples.begin(), triples.end());*/

	while (q--) {
		int k;
		cin >> k;
		vector<long long> trip(3, 10000);
		long long tar = sumTr(trip);

		for (long long a = 1; a < tar; ++a) {
			tar = sumTr(trip);
			for (long long b = a + 1; b < tar; ++b) {
				long long c = sqrt(a * a + b * b);
				if (isgg(a, b, c) && (a + b + c >= k)) {
					if (a + b + c <= tar) {
						trip = { a, b ,c };
					}
				}
			}
		}
		cout << trip[0] << " " << trip[1] << " " << trip[2] << endl;
	}
	return 0;
}