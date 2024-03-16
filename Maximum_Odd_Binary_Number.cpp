#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string maximumOddBinaryNumber(string s)
    {
        int oneCount = 0;
        for (auto it : s)
            if (it == '1')
                oneCount++;

        string ans = "";
        int n = s.length();
        for (int i = 0; i < n; i++)
            ans += '0';

        ans[n - 1] = '1';
        oneCount -= 1;
        int i = 0;
        while (oneCount > 0)
        {
            ans[i++] = '1';
            oneCount--;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.maximumOddBinaryNumber("0101");
    return 0;
}