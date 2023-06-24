#include <bits/stdc++.h>
using namespace std;

vector<int> distinctDifferenceArray(vector<int> &nums)
{
    constexpr int kMax = 50;
    vector<int> ans;
    vector<int> prefixCount(kMax + 1);
    vector<int> suffixCount(kMax + 1);
    int distinctPrefix = 0;
    int distinctSuffix = 0;

    for (const int num : nums)
    {
        cout << suffixCount[num] << " ";
        if (++suffixCount[num] == 1)
        {
            ++distinctSuffix;
        }
    }

    for (const int num : nums)
    {
        if (++prefixCount[num] == 1)
            ++distinctPrefix;
        if (--suffixCount[num] == 0)
            --distinctSuffix;
        ans.push_back(distinctPrefix - distinctSuffix);
    }

    return ans;
}

int main()
{
    vector<int> nums = {3, 2, 3, 4, 2};
    vector<int> ans = distinctDifferenceArray(nums);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}