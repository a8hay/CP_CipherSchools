// https://www.geeksforgeeks.org/check-if-two-people-starting-from-different-points-ever-meet/

#include <bits/stdc++.h>
using namespace std;

bool everMeet(int x1, int x2, int v1, int v2)
{

    if (x1 < x2 && v1 <= v2)
        return false;
    if (x1 > x2 && v1 >= v2)
        return false;

    if (x1 < x2)
    {
        swap(x1, x2);
        swap(v1, v2);
    }

    while (x1 >= x2)
    {
        if (x1 == x2)
            return true;

        x1 = x1 + v1;

        x2 = x2 + v2;
    }

    return false;
}

int main()
{
    int x1 = 5, v1 = 8, x2 = 4, v2 = 7;
    if (everMeet(x1, x2, v1, v2))
        printf("Yes");
    else
        printf("No");
    return 0;
}
