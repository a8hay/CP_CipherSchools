#include <bits/stdc++.h>
using namespace std;

int factorialTail(int x, int res)
{
	if (x == 0)
		return res

	return factorialTail(x-1, x*res)
}

int fibonnaciTail(int n, int a, int b)
{
	if (n == 0)
		return a;

	if (n == 1)
		return b;

	return fibonnaciTail(n-1, b, a+b);
}

int factorial(int x)
{
	if (x <= 1)
		return 1
	return x * factorial(x-1);
}

int fibonnaci(int n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	return fibonnaci(n-1) + fibonnaci(n-2);
}

int main()
{
	return 0;
}