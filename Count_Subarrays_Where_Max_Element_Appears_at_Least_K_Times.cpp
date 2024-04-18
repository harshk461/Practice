#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        long long maxi = *max_element(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0;
        int ans = 0;
        int j = 0;
        while (i < j)
        {
            if (nums[j] == maxi)
                k--;
            while (k > 0)
            {
                if (nums[i] == maxi)
                    k++;
                i++;
            }
            ans += i;
            j++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}