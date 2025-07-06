#include <iostream>
#include <vector>

using namespace std;

int knapsack(int W, const vector<int> &w, const vector<int> &v)
{
    int n = w.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= W; j++)
            dp[i + 1][j] = j < w[i] ? dp[i][j] : max(dp[i][j], dp[i][j - w[i]] + v[i]);
    return dp[n][W];
}

int main()
{
    vector<int> w{2, 2, 3, 1}, v{3, 2, 4, 2};
    cout << knapsack(5, w, v) << endl;
}
