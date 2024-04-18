#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')' && !st.empty())
                st.pop();
            else if (s[i] == ')')
                s[i] = '*'; // value to remove
        }

        while (!st.empty())
        {
            s[st.top()] = '*';
            st.pop();
        }
        string ans = "";
        for (auto it : s)
        {
            if (s[i] != '*')
                ans += it;
        }
        return ans;
    }
};

int main()
{

    return 0;
}