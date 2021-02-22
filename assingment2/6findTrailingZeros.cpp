#include <bits/stdc++.h>
using namespace std;

// trailing zeros is equal to 
// number of 5 in sequence
int countTrailingZeros(int n)
{
	int count = 0;

	for(int i = 5; n/i >= 1 ;i *= 5)
	{
		count += n/i;
	}

	return count;
}

int main()
{
	int n = 100;
	cout << countTrailingZeros(n) << endl;
	return 0;
}