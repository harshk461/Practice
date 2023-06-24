#include <bits/stdc++.h>
using namespace std;

string kthDistinct(vector<string> &arr, int k)
{
    map<char, int> map;
    for (auto i : arr)
    {
        map[i]++;
    }
    for (auto i : arr)
    {
        if (map[i] == 1 && --k == 0)
        {
            return i;
        }
    }
    return "";
}

int main()
{
    vector<string> arr = {"d", "b", "c", "b", "c", "a"};
    kthDistinct(arr, 2);
    return 0;
}