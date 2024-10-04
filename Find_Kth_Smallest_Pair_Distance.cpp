#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int brute(vector<int> &nums, int k)
    {
        vector<pair<int, int>> arr;
        int n = nums.size();
        vector<int> diff;

        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                diff.push_back(abs(nums[i] - nums[j]));

        // for (auto it : arr)
        // {
        //     diff.push_back(abs(it.first - it.second));
        // }
        sort(diff.begin(), diff.end());
        return diff[k - 1];
    }

    int countPairsAtMid(vector<int> &nums, int mid)
    {
        // array is sorted so it is easy to compute the number of pairs with distance less than mid

        int count = 0;
        int n = nums.size();
        int left = 0;
        for (int i = 1; i < n; i++)
        {
            // while we can extend left having difference less than mid we will extend it
            while (nums[i] - nums[left] > mid)
                left++;

            // when we came out of loop we see that after left index difference is more than mid so elements between i and left can form pairs
            count += (i - left);
        }

        return count;
    }

public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0;
        int high = nums[n - 1] - nums[0];

        while (low <= high)
        {
            int mid = (low + high) / 2;
            int count = countPairsAtMid(nums, mid);
            // when count is less than k it means that we have to increase the low
            // if count is less than k we increase low
            // if it is greater than k we have to decrease high
            // at the end of loop we are standing at low with number of pairs = k
            if (count < k)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return low;
    }
};

int main()
{

    return 0;
}