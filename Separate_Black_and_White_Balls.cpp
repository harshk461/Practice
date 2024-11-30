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
    long long minimumSteps(string s)
    {
        int left = 0;
        int right = s.size();

        int count = 0;

        while (l < r)
        {
            if (s[left] == '1' && s[right] == '0')
            {
                count += (right - left);
                left++;
                right--;
            }
            else if (s[left] == '1' && s[right] == '1')
                right--;
            else if (s[left] == '0' && s[right] == '0')
                left++;
            else
            {
                right--;
                left++;
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}