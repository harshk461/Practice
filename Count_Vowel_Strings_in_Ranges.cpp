#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    bool isVowel(char ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }

public:
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        int m = queries.size();
        int n = words.size();
        vector<int> ans(m, 0);
        vector<int> prefix(n, 0);

        prefix[0] = (isVowel(words[0][0]) && isVowel(words[0][words[0].length() - 1])) ? 1 : 0;

        for (int i = 1; i < n; i++)
        {
            if ((isVowel(words[i][0]) && isVowel(words[i][words[i].length() - 1])))
            {
                prefix[i] = 1 + prefix[i - 1];
            }
            else
            {
                prefix[i] = prefix[i - 1];
            }
        }
        for (auto it : prefix)
            cout << it << " ";
        for (int i = 0; i < m; i++)
        {
            int l = queries[i][0];
            int r = queries[i][1];
            if (l == 0)
                ans[i] = prefix[r];
            else
                ans[i] = (prefix[r] - prefix[l - 1]);
        }

        return ans;
    }
};

int main()
{

    return 0;
}