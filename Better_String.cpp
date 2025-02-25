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
    void generate(int i, string s, string curr, set<string> &ans)
    {
        if (i >= s.length())
        {
            ans.insert(curr);
            return;
        }

        curr.push_back(s[i]);
        generate(i + 1, s, curr, ans);
        curr.pop_back();

        generate(i + 1, s, curr, ans);
    }

public:
    string betterString(string str1, string str2)
    {
        set<string> sub1;
        set<string> sub2;

        string curr1 = "";
        string curr2 = "";
        generate(0, str1, curr1, sub1);
        generate(0, str2, curr2, sub2);

        if (sub1.size() > sub2.size())
            return str1;
        else if (sub1.size() < sub2.size())
            return str2;
        else
            return str1;
    }
};

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
    const int MOD = 1e9 + 7;

    int countUniqueSubsequences(string s)
    {
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        unordered_map<char, int> last;

        dp[0] = 1; // Empty subsequence

        for (int i = 1; i <= n; ++i)
        {
            dp[i] = (2 * dp[i - 1]) % MOD;

            // If the current character was seen before, subtract duplicates
            if (last.find(s[i - 1]) != last.end())
            {
                dp[i] = (dp[i] - dp[last[s[i - 1]] - 1] + MOD) % MOD;
            }

            // Update the last occurrence of the current character
            last[s[i - 1]] = i;
        }

        // Total unique subsequences (excluding the empty one)
        return (dp[n] - 1 + MOD) % MOD;
    }

public:
    string betterString(string str1, string str2)
    {
        int count1 = countUniqueSubsequences(str1);
        int count2 = countUniqueSubsequences(str2);

        if (count1 > count2)
            return str1;
        else if (count1 < count2)
            return str2;
        else
            return str1; // If equal, return str1 as per the problem statement
    }
};

int main()
{

    return 0;
}