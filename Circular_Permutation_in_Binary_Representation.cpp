// gray code sequence+array rotation
class Solution
{
private:
    vector<int> solve(int n, int start)
    {
        int len = 1 << n;
        vector<int> ans(len);
        for (int i = 0; i < len; i++)
            ans[i] = (start ^ (i ^ (i >> 1)));
        return ans;
    }

public:
    vector<int> circularPermutation(int n, int start)
    {
        int len = 1 << n;
        vector<int> ans(len);
        for (int i = 1; i < (1 << n); i++)
            ans[i] = i ^ (i >> 1);

        int idx = 0;
        for (int i = 0; i < len; i++)
        {
            if (ans[i] == start)
                idx = i;
        }
        // for (auto it : ans)
        //     cout << it << " ";
        vector<int> v1(ans.begin() + idx, ans.end());
        for (int i = 0; i < idx; i++)
            v1.push_back(ans[i]);

        return solve(n, start);
    }
};