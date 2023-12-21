#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        stack<char> st;
        int i = 0;

        while (i < s.length())
        {
            if (!st.empty() && s[i] == '*')
                st.pop();
            else
                st.push(s[i]);
            i++;
        }
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{

    return 0;
}