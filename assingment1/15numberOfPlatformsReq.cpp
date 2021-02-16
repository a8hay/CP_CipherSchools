#include <bits/stdc++.h>
using namespace std;

int minimumNoOfPlatform(vector<int> arrival, vector<int> departure)
{
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int platform_needed = 1, result = 1;
    int i = 1, j = 0;
    while (i < arrival.size() && j < departure.size())
    {
        if (arrival[i] <= departure[j])
        {
            platform_needed++;
            i++;
        }
        else
        {
            platform_needed--;
            j++;
        }
        result = max(result, platform_needed);
    }
    return result;
}

int main()
{
    vector<int> arrival = {900, 940, 950, 1100, 1500, 1800};
    vector<int> departure = {9100, 1200, 1120, 1130, 1900, 2000};
    cout << minimumNoOfPlatform(arrival, departure) << endl;
    return 0;
}