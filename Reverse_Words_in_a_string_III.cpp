#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> arr;
        string temp = "";
        for (int i = 0; i <= s.length(); i++)
        {
            if (s[i] == ' ' || i == s.length())
            {
                arr.push_back(temp);
                temp = "";
            }
            else
                temp += s[i];
        }

        string ans = "";
        for (int i = 0; i < arr.size(); i++)
        {
            if (i == arr.size() - 1)
            {
                reverse(arr[i].begin(), arr[i].end());
                ans += arr[i];
            }
            else
            {
                reverse(arr[i].begin(), arr[i].end());
                ans += arr[i] + " ";
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;
    s.reverseWords("Let's take LeetCode contest");
    return 0;
}