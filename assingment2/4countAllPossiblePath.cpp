#include <bits/stdc++.h>
using namespace std;

int countPath(int m, int n)
{
	if (m == 0 || n == 0)
		return 0;
	return countPath(m-1, n) + countPath(m, n-1);
}

int main()
{
	cout << countPath(3, 3) << endl;
	return 0;
}