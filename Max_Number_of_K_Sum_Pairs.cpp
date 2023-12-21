#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            int x = k - nums[i];
            if (map.find(x) != map.end())
            {
                count++;
                map[x]--;
                if (map[x] == 0)
                    map.erase(x);
            }
            else
                map[nums[i]]++;
        }

        return count;
    }
};

int main()
{
    vector<int> arr = {4, 4, 1, 3, 1, 3, 2, 2, 5, 5, 1, 5, 2, 1, 2, 3, 5, 4};
    Solution s;
    s.maxOperations(arr, 2);
    return 0;
}