#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string thousandSeparator(int n)
    {
        if (n <= 999)
            return to_string(n);

        int count = 0;
        string ans = "";
        while (n > 0)
        {
            int rem = n % 10;
            if (count == 3)
            {
                count = 1;
                ans += ".";
                ans += to_string(rem);
            }
            else
            {
                count++;
                ans += to_string(rem);
            }
            n /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.thousandSeparator(1234567);
    return 0;
}