#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

int maxgcd(int x, int b) {
	while (b != 0)
	{
		int temp = b;
		b = x % b;
		x = temp;
	}
	return x;
}

int main() {
	int n, k;
	int res = -1;
	
	cin >> n >> k;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int l = 0; l < n; ++l) {
		long long sum = 0;
		int curr = 0;

		for (int r = l; r < n; ++r) {
			sum += a[r];
			curr = maxgcd(curr, a[r]);
			if (sum > k) break;
			if (r - l + 1 < 1) {
				res = max(res, curr);
			}
		}
	}
	cout << res << endl;
	return 0;
}