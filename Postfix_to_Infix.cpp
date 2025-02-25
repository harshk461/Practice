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
    string postToInfix(string exp)
    {
        stack<string> st;
        int i = 0;
        while (i < exp.length())
        {
            char ch = exp[i];
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
            {
                string s = string(1, ch);
                st.push(s);
            }
            // Operator
            else
            {
                string s1 = st.top();
                st.pop();

                string s2 = st.top();
                st.pop();

                string temp = "(" + s2 + ch + s1 + ")";
                st.push(temp);
            }
            i++;
        }

        return st.top();
    }
};

int main()
{

    return 0;
}