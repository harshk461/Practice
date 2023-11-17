#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(string s)
    {
        int res = 0;
        vector<int> first(26, INT_MAX);
        vector<int> last(26);

        for (int i = 0; i < s.length(); i++)
        {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = i;
        }

        for (int i = 0; i < 26; i++)
            if (first[i] < last[i])
                res += unordered_set<char>(s.begin() + first[i] + 1, s.begin() + last[i]).size();
        return res;
    }

public:
    int countPalindromicSubsequence(string s)
    {
        unordered_set<char> letters;
        for (auto c : s)
            letters.insert(c);

        int ans = 0;
        for (auto letter : letters)
        {
            int i = -1;
            int j = 0;

            for (int k = 0; k < s.size(); k++)
            {
                if (s[k] == letter)
                {
                    if (i == -1)
                        i = k;
                    j = k;
                }
            }

            unordered_set<char> between;
            for (int k = i + 1; k < j; k++)
                between.insert(s[k]);
            ans += between.size();
        }
        return ans;
    }
};

int main()
{

    return 0;
}