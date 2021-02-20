#include <iostream>
using namespace std;

int main()
{
	string input;
	cin >> input;
	if (input.size() < 1)
		return 0;

	int freq_small[26];
	int freq_capital[26];
	for (int i=0; i<26; i++)
	{
		freq_small[i] = 0;
		freq_capital[i] = 0;
	}

	int ascii;
	for (int i=0; i<input.size(); i++)
	{
		ascii = int(input[i]);
		if (ascii >= int('A') && ascii <= int('Z'))
		{
			freq_capital[ascii - int('A')] += 1;
		}
		else if (ascii >= int('a') && ascii <= int('z'))
		{
			freq_small[ascii - int('a')] += 1;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	char arr[input.size()+1];
	int unique_characters = 1;
	arr[0] = input[0];
	for (int i=1; i<input.size(); i++)
	{
		if (arr[unique_characters-1] != input[i])
		{
			arr[unique_characters] = input[i];
			unique_characters++;
		}
	}

	// for (int i=0; i<unique_characters; i++)
	// 	cout << arr[i];

	for(int i=0; i<unique_characters; i++)
	{
		ascii = int(arr[i]);
		if (ascii >= int('A') && ascii <= int('Z'))
		{
			cout << arr[i] << freq_capital[ascii - int('A')];
		}
		else if (ascii >= int('a') && ascii <= int('z'))
		{
			cout << arr[i] << freq_small[ascii - int('a')];
		}
	}

	return 0;
}