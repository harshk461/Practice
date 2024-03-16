#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(string &a, int l, int r, vector<string> &ans)
    {
        if (l == r)
            ans.push_back(a);
        else
        {
            for (int i = l; i <= r; i++)
            {
                swap(a[l], a[i]);
                solve(a, l + 1, r, ans);
                swap(a[l], a[i]);
            }
        }
    }

public:
    string getPermutation(int n, int k)
    {
        string s = "";
        for (int i = 1; i <= n; i++)
            s += to_string(i);
        vector<string> ans;
        solve(s, 0, n - 1, ans);
        cout << ans[k] << endl;
        return ans[k];
    }
};

int main()
{
    Solution s;
    s.getPermutation(3, 3);
    return 0;
}