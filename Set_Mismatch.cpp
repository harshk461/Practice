#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> solve(vector<int> &nums)
    {
        int n = nums.size();
        int duplicate = -1, missing = -1;
        for (int i = 1; i <= n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
                if (nums[j] == i)
                    count++;

            if (count == 2)
                duplicate = i;
            else if (count == 0)
                missing = i;
        }

        return {duplicate, missing};
    }

public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        set<int> st(nums.begin(), nums.end());
        unordered_map<int, int> map;
        for (auto it : nums)
            map[it]++;

        for (auto it : map)
            if (it.second == 2)
                ans.push_back(it.first);

        for (int i = 1; i <= n; i++)
            if (st.find(i) == st.end())
                ans.push_back(i);
        return ans;
    }
};

int main()
{

    return 0;
}