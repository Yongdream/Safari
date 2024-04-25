#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 500 + 7;

int n, m, t;
int a[N][N];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            res += abs(a[i][j] - a[j][i]);
        }
    }
    cout << res;
    return 0;
}
