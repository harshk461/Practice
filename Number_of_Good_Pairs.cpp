#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int brute(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] == nums[j])
                    ans++;
        }
        return ans;
    }

    int opti(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (auto it : nums)
            map[it]++;

        int ans=0;

        for(auto it:map){
            int n=it.second;
            ans+=(n*(n-1))/2;
        }

        return ans;
    }

public:
    int numIdenticalPairs(vector<int> &nums)
    {
        return brute(nums);
    }
};

int main()
{

    return 0;
}