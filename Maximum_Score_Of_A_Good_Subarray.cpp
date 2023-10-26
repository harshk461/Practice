#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &nums, int k)
    {
        int left = k, right = k;
        int min_val = nums[k];
        int max_score = min_val;

        while (left > 0 || right < nums.size() - 1)
        {
            if (left == 0 || (right < nums.size() - 1 && nums[right + 1] > nums[left - 1]))
                right++;
            else
                left--;

            min_val = min(min_val, min(nums[left], nums[right]));
            max_score = max(max_score, min_val * (right - left + 1));
        }
        return max_score;
    }

public:
    int maximumScore(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> st;

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.back()] > nums[i])
            {
                left[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }

        vector<int> right(n, n);
        st.clear();

        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.back()] > nums[i])
            {
                right[st.back()] = i;
                st.pop_back();
            }
            st.push_back(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (left[i] < k && right[i] > k)
                ans = max(ans, nums[i] * (right[i] - left[i] - 1));
        }

        return ans;
    }
};

int main()
{

    return 0;
}