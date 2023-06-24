#include <bits/stdc++.h>
using namespace std;

bool isFascinating(int n)
{
    unordered_map<int, int> map;
    int n1 = n;
    while (n1 > 0)
    {
        int rem = n1 % 10;
        map[rem]++;
        n1 /= 10;
    }
    int n2 = 2 * n;
    while (n2 > 0)
    {
        int rem = n2 % 10;
        map[rem]++;
        n2 /= 10;
    }
    int n3 = 3 * n;
    while (n3 > 0)
    {
        int rem = n3 % 10;
        map[rem]++;
        n3 /= 10;
    }

    for (auto i : map)
    {
        if (i.first == 0 || i.second != 1)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << isFascinating(267);
    return 0;
}