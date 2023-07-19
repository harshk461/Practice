#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> ans;
        for (int i = 0; i < nums.size(); i++)
        {

            int begin = nums[i];
            while (i + 1 < nums.size() && nums[i] == nums[i + 1] - 1)
                i++;
            int end = nums[i];
            if (begin == end)
                ans.push_back(to_string(begin));
            else
                ans.push_back(to_string(begin) + "->" + to_string(end));
        }
        return ans;
    }
};

int main()
{

    return 0;
}