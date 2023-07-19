#include <bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < size; i++)
    {
        map[arr[i]]++;
    }

    for (int i = 0; i < size; i++)
    {
        map[arr[i]]--;
        if (map[n + arr[i]] >= 1 || map[arr[i] - n] >= 1)
            return true;
        map[arr[i]]++;
    }
    return false;
}

int main()
{

    return 0;
}