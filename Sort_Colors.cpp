#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    unordered_map<int, int> map;
    for (auto i : nums)
        map[i]++;
    int i = 0;
    while (map[0] > 0)
    {
        nums[i] = 0;
        i++;
        map[0]--;
    }
    while (map[1] > 0)
    {
        nums[i] = 1;
        i++;
        map[1]--;
    }
    while (map[2] > 0)
    {
        nums[i] = 2;
        i++;
        map[2]--;
    }
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};
    sortColors(arr);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}