#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool brute(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    if (nums[i] < nums[k] && nums[k] < nums[j])
                        return true;
        return false;
    }

    bool betterBrute(vector<int> &nums)
    {
        int n = nums.size();
        int min_i = INT_MAX;
        for (long j = 0; j < n - 1; j++)
        {
            min_i = min(min_i, nums[j]);
            for (long k = j + 1; k < n; k++)
                if (nums[k] < nums[j] && min_i < nums[k])
                    return true;
        }
        return false;
    }

    bool opti(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> s;
        int k = INT_MIN;

        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < k)
                return true;
            while (!s.empty() && s.top() < nums[i])
                k = s.top(), s.pop();
            s.push(nums[i]);
        }
        return false;
    }

public:
    bool find132pattern(vector<int> &nums)
    {
    }
};

int main()
{

    return 0;
}