#include <bits/stdc++.h>
using namespace std;

int countWays(int sum, vector<int> &coins, int n)
{
	if (sum < 0 || n == 0)
		return 0;

	if (sum == 0)
		return 1;

	return countWays(sum-coins[n-1], coins, n-1) + 
		   countWays(sum, coins, n-1);
}

int main()
{
	vector<int> coins = {1, 5, 10};
	int sum = 15;
	int n = coins.size();
	cout << countWays(sum, coins, n);
	return 0;
}