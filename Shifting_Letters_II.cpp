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
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        int n = s.length();
        vector<int> prefix(n + 1, 0);

        for (auto &it : shifts)
        {
            int u = it[0];
            int v = it[1];
            int dirn = it[2];

            if (dirn == 1)
            {
                prefix[u] += 1;
                if (v + 1 < n)
                    prefix[v + 1] -= 1;
            }
            else
            {
                prefix[u] -= 1;
                if (v + 1 < n)
                    prefix[v + 1] += 1;
            }
        }

        for (int i = 1; i < n; i++)
        {
            prefix[i] += prefix[i - 1];
        }

        for (int i = 0; i < n; i++)
        {
            int shift = prefix[i] % 26;
            if (shift < 0)
                shift += 26;
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};

int main()
{

    return 0;
}