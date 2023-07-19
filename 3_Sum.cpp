#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     set<vector<int>> s;
//     unordered_map<int, int> m;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         m[nums[i]]++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         m[nums[i]]--;
//         for (int j = i + 1; j < n; j++)
//         {
//             m[nums[j]]--;
//             int c = -1 * (nums[i] + nums[j]);
//             if (m.find(c) != m.end() && m[c] > 0)
//             {
//                 vector<int> v(3);
//                 v[0] = nums[i], v[1] = nums[j], v[2] = c;
//                 sort(v.begin(), v.end());
//                 s.insert(v);
//             }
//             m[nums[j]]++;
//         }
//         m[nums[i]]++;
//     }
//     vector<vector<int>> v;
//     for (auto i : s)
//     {
//         v.push_back(i);
//     }
//     return v;
// }

// vector<vector<int>> threeSum(vector<int> &nums)
// {
//     set<vector<int>> s; // to get unique triplets
//     sort(nums.begin(), nums.end());
//     int n = nums.size();
//     vector<int> temp;
//     temp.resize(3);
//     for (int i = 0; i < n; i++)
//         for (int j = i + 1; j < n; j++)
//         {
//             if (binary_search(nums.begin() + j + 1, nums.end(), -nums[i] - nums[j]))
//             {
//                 temp[0] = nums[i], temp[1] = nums[j], temp[2] = -nums[i] - nums[j];
//                 sort(temp.begin(), temp.end());
//                 // to get triplet in an order, will be easy to check if
//                 // duplicate exists or not
//                 s.insert(temp);
//             }
//         }
//     vector<vector<int>> ans;
//     for (auto triplet : s)
//         ans.push_back(triplet);
//     return ans;
// }

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return {};

        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i + 2 < nums.size(); ++i)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r)
            {
                const int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[l++], nums[r--]});
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                    while (l < r && nums[r] == nums[r + 1])
                        --r;
                }
                else if (sum < 0)
                {
                    ++l;
                }
                else
                {
                    --r;
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums = {
        -1,
        0,
        1,
        2,
        -1, 4};
    vector<vector<int>> ans = threeSum(nums);
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}