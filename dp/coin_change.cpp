#include <iostream>
#include <vector>

using namespace std;

int count(vector<int> &c, int n, int s)
{
    vector<vector<int>> dp(n + 1, vector<int>(s + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= c[i - 1])
                dp[i][j] += dp[i][j - c[i - 1]];
        }
    return dp[n][s];
}

int main()
{
    vector<int> coins{1, 2, 3};
    cout << count(coins, coins.size(), 5) << endl;
}
