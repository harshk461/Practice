#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // vector<int> ans;
        // deque<int> dq;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     while (!dq.empty() && dq.back() < nums[i])
        //         dq.pop_back();

        //     dq.push_back(nums[i]);
        //     if (i >= k && nums[i - k] == dq.front())
        //         dq.pop_front();
        //     if (i >= k - 1)
        //         ans.push_back(dq.front());
        // }
        // return ans;

        // using vector TLE
        vector<int> ans;
        for (int i = 0; i + 2 < nums.size(); i++)
        {
            vector<int> temp;
            for (int j = 0; j < 3; j++)
            {
                temp.push_back(nums[i + j]);
            }
            for (auto i : temp)
                cout << i << " ";
            cout << endl;
            ans.push_back(*max_element(temp.begin(), temp.end()));
        }
        return ans;
    }

    vector<int> maxSlidingWindow2(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < k; i++)
        {
            dq.push_back(nums[i]);
        }
        ans.push_back(*max_element(dq.begin(), dq.end()));
        for (int i = 3; i < nums.size(); i++)
        {
            dq.pop_front();
            dq.push_back(nums[i]);
            ans.push_back(*max_element(dq.begin(), dq.end()));
        }
        for (auto i : ans)
            cout << i << " ";
        return ans;
    }
};

int main()
{
    vector<int> arr = {1};
    Solution s;
    s.maxSlidingWindow2(arr, 1);
    deque<int> dq;
    return 0;
}