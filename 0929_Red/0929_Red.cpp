#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

long long power(long long base, long long exp, long long mod) {
	long long res = 1;

	while (exp > 0) {
		if (exp % 2 == 1) {
			res = (res * base) % mod;
		}
		base = (base * base) % mod;
		exp /= 2;
	}
	return res;
}


int redpwd(int n, const string& pwd) {
	int minpwd = 9;
	int maxpwd = 0;
	for (char c : pwd) {
		int cur = c - '0';
		minpwd = min(minpwd, cur);
		maxpwd = max(maxpwd, cur);
	}
	if (maxpwd == 9 || minpwd == 0) return 0;
	if (maxpwd == minpwd) return 0;

	long long tol = power(10, n, MOD);
	long long red1 = power(maxpwd + 1, n, MOD);
	long long red2 = power(10 - minpwd, n, MOD);

	long long red12 = power(maxpwd - minpwd + 1, n, MOD);
	long long red = (tol - red1 - red2 + red12 + MOD) % MOD;
	return red;

}

//int main() {
//	int T;
//	cin >> T;
//	while (T--)
//	{
//		int n;
//		string pwd;
//		cin >> n >> pwd;
//		cout << redpwd(n, pwd) << endl;
//	}
//	return 0;
//}