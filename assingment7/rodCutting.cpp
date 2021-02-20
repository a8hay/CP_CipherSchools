#include <bits/stdc++.h>
using namespace std;

int rodCutting(vector<int> &prices)
{
	int l = prices.size();
	vector<int> dp(L, 0);
	for (int i = 0; i < l; i++)
	{
		dp[l] = prices[l];
		for (int j = 0; j < i; j++)
		{
			dp[i] = max(dp[i], dp[j] + dp[i-j-1]);
		}
	}
	return dp[dp.size()-1][dp[0].size()-1];
}

int main()
{
	vector<int> prices = {3, 3, 3, 5, 1, 4, 2};
	cout << countWays(prices);
	return 0;
}