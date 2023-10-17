#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // brute force TC-O(N^3)
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int sum = 0;
                for (int k = i; k <= j; k++)
                {
                    sum += nums[k];
                }
                maxi = max(sum, maxi);
            }
        }
        return maxi;
    }

    // better soln TC-O(N^2)
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            for (int j = i; j < n; j++)
            {

                sum += nums[j];
            }
            maxi = max(sum, maxi);
        }
        return maxi;
    }

    // Kadane Algo TC-O(N) SC-O(1)
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        long long sum = 0, maxi = LONG_MIN;
        int ansS = -1, ansE = -1;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum == 0)
                start = i;
            sum += nums[i];

            if (sum > maxi)
            {
                ansS = start, ansE = i;
                maxi = sum;
            }

            if (sum < 0)
            {
                sum = 0;
            }
        }

        for (int i = ansS; i < ansE; i++)
        {
            cout << nums[i] << " ";
        }
        return maxi;
    }
};

int main()
{

    return 0;
}