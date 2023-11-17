#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int solve(string s)
    {
        int ans = 0;
        int curr = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (i == 0 || s[i] == s[i - 1])
                curr++;
            else
                curr = 1;

            ans = (ans + curr) % MOD;
        }

        return ans;
    }

public:
    int countHomogenous(string s)
    {
        int ans = 0;
        unordered_map<string, int> map;

        int i = 0;
        while (i < s.size())
        {
            string temp = string(1, s[i]);
            while (i + 1 < s.size() && s[i] == s[i + 1])
                temp += s[i];

            map[temp]++;
            i++;
        }

        for (auto it : map)
        {
            int size = it.first.size();
            int count = it.second;
            int val = size * (size + 1) / 2;
            val *= count;
            ans = ((ans % MOD) + (val % MOD)) % MOD;
        }
        return ans;
    }
};

int main()
{

    return 0;
}