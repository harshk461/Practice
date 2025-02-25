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
    vector<vector<int>> ans;
    bool isPalindrome(string a, string b)
    {
        if (a.length() != b.length())
            return false;
        int i = 0;
        int j = a.length() - 1;

        while (i <= j)
        {
            if (a[i] != b[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
    void brute(vector<string> &words)
    {
        set<vector<int>> vis;

        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words.size(); j++)
            {
                if (i != j && isPalindrome(words[i], words[j]) && !vis.count({i, j}) && !vis.count({j, i}))
                {
                    vis.insert({i, j});
                }
            }
        }
    }

public:
    vector<vector<int>> palindromePairs(vector<string> &words)
    {
        brute(words);
        return ans;
    }
};

int main()
{

    return 0;
}