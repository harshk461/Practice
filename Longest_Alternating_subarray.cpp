#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int alternatingSubarray(vector<int> &nums)
    {
        int i = 1;
        int maxi = 1;
        int seq = 1;
        while (i < nums.size())
        {
            if ((seq % 2 != 0 && nums[i] == nums[i - 1] + 1) ||
                (seq % 2 == 0 && nums[i] == (nums[i - 1] - 1)))
                seq++;
            else
            {
                maxi = max(maxi, seq);
                seq = nums[i] != nums[i - 1] + 1 ? 1 : 2;
            }
            i++;
        }
        if (maxi == 1 && seq == 1)
            return -1;
        return max(maxi, seq);
    }
};

int main()
{
    vector<int> arr = {4, 5, 6};
    Solution s;
    cout << s.alternatingSubarray(arr);
    return 0;
}