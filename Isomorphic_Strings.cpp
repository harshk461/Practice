#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        vector<int> map1(128);
        vector<int> map2(128);

        for (int i = 0; i < s.length(); i++)
        {
            if (map1[s[i]] != map2[t[i]])
                return false;
            map1[s[i]] = i + 1;
            map2[t[i]] = i + 1;
        }
        return true;
    }
};

int main()
{

    return 0;
}