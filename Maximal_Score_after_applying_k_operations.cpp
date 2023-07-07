#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int> maxHeap;
        int ans = 0;
        for (auto num : nums)
        {
            maxHeap.push(num);
        }

        while (k > 0 && !maxHeap.empty())
        {
            int top = maxHeap.top();
            maxHeap.pop();
            ans += top;
            maxHeap.push(ceil((double)top / 3));
            k--;
        }
        return ans;
    }
};

int main()
{
    vector<int> arr = {1, 10, 3, 3, 3};
    Solution s;
    s.maxKelements(arr, 3);
    return 0;
}