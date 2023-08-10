#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        // TLE
        //  deque<int> dq;
        //  for (int i = 0; i < k; i++)
        //      dq.push_back(nums[i]);
        //  double avg = accumulate(dq.begin(), dq.end(), 0) / (double)k;
        //  for (int i = k; i < nums.size(); i++)
        //  {
        //      dq.pop_front();
        //      dq.push_back(nums[i]);
        //      double sum = accumulate(dq.begin(), dq.end(), 0);
        //      avg = max(avg, sum / (double)k);
        //      cout << avg << " ";
        //  }
        //  return avg;

        double sum = accumulate(nums.begin(), nums.begin() + k, 0);
        double ans = sum;
        for (int i = k; i < nums.size(); i++)
        {
            sum += nums[i] - nums[i - k];
            ans = max(ans, sum);
        }
        return ans / k;
    }
};

int main()
{
    vector<int> arr = {0, 1, 1, 3, 3};
    Solution s;
    s.findMaxAverage(arr, 4);
    return 0;
}