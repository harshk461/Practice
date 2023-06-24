#include <bits/stdc++.h>
using namespace std;

string largestNumber(vector<int> &nums)
{
    sort(nums.begin(), nums.end(), [&](int &a, int &b)
         {
            string s1=to_string(a)+to_string(b);
            string s2=to_string(b)+to_string(a);
            return s1>s2; });
    string ans = "";
    for (int i : nums)
    {
        ans += to_string(i);
    }

    if (ans[0] == '0')
    {
        return "0";
    }
    return ans;
}

int main()
{

    return 0;
}
