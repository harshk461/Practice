#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;
        int n = nums.size();
        set<int> s(nums.begin(), nums.end());
        for (int i = 1; i <= n; i++)
            if (s.find(i) != s.end())
                continue;
            else
                ans.push_back(i);
        return ans;
    }
};

int main()
{

    return 0;
}