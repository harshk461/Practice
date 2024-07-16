#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
class Solution
{
private:
    vector<vector<int>> brute(vector<int> &nums, int target)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> temp_ans;
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                for (int k = j + 1; k < n - 1; k++)
                {
                    for (int l = k + 1; l < n; l++)
                    {
                        if ((ll)nums[i] + (ll)nums[j] + (ll)nums[k] + (ll)nums[l] == target)

                            temp_ans.insert({nums[i], nums[j], nums[k], nums[l]});
                    }
                }
            }
        }

        for (auto it : temp_ans)
            ans.push_back(it);

        return ans;
    }

    vector<vector<int>> solve(vector<int> &nums, int target)
    {
        int n = nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = i + 1; j < n - 2; j++)
            {
                ll new_target = (ll)target - (ll)nums[i] - (ll)nums[j];
                int low = j + 1;
                int high = n - 1;

                while (low < high)
                {
                    if (nums[low] + nums[high] < new_target)
                        low++;

                    else if (nums[low] + nums[high] > new_target)
                        high--;
                    else
                    {
                        st.insert({nums[i], nums[j], nums[low], nums[high]});
                        low++, high--;
                    }
                }
            }
        }

        for (auto it : st)
            ans.push_back(it);

        return ans;
    }

public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        return solve(nums, target);
    }
};

int main()
{
    return 0;
}