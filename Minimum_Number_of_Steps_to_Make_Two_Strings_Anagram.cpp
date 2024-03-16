#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(string s, string t)
    {
        int n = s.length();
        vector<int> countArray1(n, 0);
        vector<int> countArray2(n, 0);
        for (auto it : s)
            countArray1[it - 'a']++;

        for (auto it : t)
            countArray2[it - 'a']++;

        int ans = 0;
        for (int i = 0; i < 26; i++)
        {
            if (countArray12[i] < countArray1[i])
                ans += abs(countArray1[i] - countArray2[i]);
        }

        return ans;
    }
};

int main()
{

    return 0;
}