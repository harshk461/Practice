#include <bits/stdc++.h>
using namespace std;

struct T
{
    int i;
    int j;
    int sum; // nums1[i] + nums2[j]
    T(int i, int j, int sum) : i(i), j(j), sum(sum) {}
};

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2,
                                       int k)
    {
        vector<vector<int>> ans;
        auto compare = [&](const T &a, const T &b)
        { return a.sum > b.sum; };
        priority_queue<T, vector<T>, decltype(compare)> minHeap(compare);

        for (int i = 0; i < k && i < nums1.size(); ++i)
            minHeap.emplace(i, 0, nums1[i] + nums2[0]);

        while (!minHeap.empty() && ans.size() < k)
        {
            const auto [i, j, _] = minHeap.top();
            minHeap.pop();
            ans.push_back({nums1[i], nums2[j]});
            if (j + 1 < nums2.size())
                minHeap.emplace(i, j + 1, nums1[i] + nums2[j + 1]);
        }

        return ans;
    }
};

int main()
{
    vector<int> v1 = {1, 7, 11};
    vector<int> v2 = {2, 4, 6};
    Solution s;
    vector<vector<int>> ans = s.kSmallestPairs(v1, v2, 3);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}