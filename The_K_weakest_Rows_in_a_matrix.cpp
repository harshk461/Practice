#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int countOne(vector<int> arr)
    {
        int count = 0;
        for (auto it : arr)
            if (it == 1)
                count++;
        return count;
    }

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<pair<int, int>> ans;
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++)
        {
            int sum = accumulate(mat[i].begin(), mat[i].end());
            ans.push_back({sum, i});
        }

        sort(ans.begin(), ans.end());
        vector<int> res;
        for (int i = 0; i < k; i++)
            res.push_back(ans[i].second);
        return res;
    }
};

int main()
{

    return 0;
}