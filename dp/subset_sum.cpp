#include <iostream>
#include <vector>

using namespace std;

bool subset_sum(const vector<int> &a, int S)
{
    int n = a.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(S + 1, false));
    dp[0][0] = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= S; j++)
        {
            if (dp[i][j])
            {
                dp[i + 1][j] = true;
                if (j + a[i] <= S)
                    dp[i + 1][j + a[i]] = true;
            }
        }
    return dp[n][S];
}

int main()
{
    vector<int> a = {3, 21, 4, 13, 5, 1, 2};
    int S = 9;
    cout << (subset_sum(a, S) ? "Yes" : "No") << endl;
}