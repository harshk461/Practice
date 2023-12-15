#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string solve(string str)
    {
        int i = str.length() - 1;
        for (; i >= 0; i--)
        {
            if ((str[i] - '0') % 2 != 0)
                break;
        }

        string ans = "";
        for (int j = 0; j <= i; j++)
            ans += str[j];

        return ans;
    }

public:
    string largestOddNumber(string num)
    {
        vector<string> arr;
        for (int i = 0; i < num.length(); i++)
        {
            string temp;
            for (int j = i; j < num.length(); j++)
            {
                temp += num[j];
                arr.push_back(temp);
            }
        }

        string ans = "";
        int maxi = INT_MIN;
        for (auto it : arr)
            if (stoi(it) % 2 != 0)
                maxi = max(stoi(it), maxi);

        if (maxi == INT_MIN)
            return "";

        return to_string(maxi);
    }
};

int main()
{

    Solution s;
    s.largestOddNumber("52");
    return 0;
}