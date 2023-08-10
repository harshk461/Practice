#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPalindrome(string s, int start, int end)
    {
        while (start < end)
        {
            if (s[start] != s[end])
                return false;
            start++, end--;
        }

        return true;
    }
    void solve(int index, string &s, vector<vector<string>> &ans, vector<string> &curr)
    {
        if (index >= s.length())
        {
            ans.push_back(curr);
            return;
        }

        for (int i = index; i < s.length(); i++)
        {
            if (isPalindrome(s, index, i))
            {
                curr.push_back(s.substr(index, index + i - 1));
                solve(index + 1, s, ans, curr);
                curr.pop_back(); // backtrack
            }
        }

        return;
    }

public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, ans, curr);
        return ans;
    }
};

int main()
{

    return 0;
}