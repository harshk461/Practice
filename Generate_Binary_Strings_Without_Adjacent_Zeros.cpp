#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void solve(int n, string curr, vector<string> &ans)
    {
        if (curr.length() == n)
        {
            ans.push_back(curr);
            return;
        }

        // if back of curr is 1 it means that 1 and 0 can come after it
        if (curr.length() == 0 || curr.back() == '1')
        {
            solve(n, curr + '1', ans);
            solve(n, curr + '0', ans);
        }

        // if it is 0 means we have to push 1 because there should be no consecutive 0s
        else if (curr.back() == '0')
            solve(n, curr + '1', ans);
    }

public:
    vector<string> validStrings(int n)
    {
        vector<string> ans;
        solve(n, "", ans);
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> ans = s.validStrings(3);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}