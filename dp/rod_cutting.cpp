#include <iostream>
#include <vector>

using namespace std;

int cutRod(vector<int> &p, int n)
{
    vector<int> dp(n + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            dp[i] = max(dp[i], p[j] + dp[i - j - 1]);
    return dp[n];
}

int main()
{
    vector<int> prices = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << cutRod(prices, prices.size()) << endl;
}
