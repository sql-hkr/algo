#include <iostream>
using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size(), dp[1001][1001] = {};
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dp[i + 1][j + 1] = s[i] == t[j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
    cout << dp[n][m] << endl;
}
