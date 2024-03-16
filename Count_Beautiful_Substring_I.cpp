#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // generate all substring and check them
    int brute(string s, int k)
    {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int v = 0, c = 0;
            for (int j = i; j < n; j++)
            {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                    v++;
                else
                    c++;

                if (v == c && (c * v) % k == 0)
                    ans++;
            }
        }
        return ans;
    }

public:
    int beautifulSubstrings(string s, int k)
    {
        return brute(s, k);
    }
};

int main()
{

    return 0;
}