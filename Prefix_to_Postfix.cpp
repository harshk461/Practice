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
    string preToPost(string pre_exp)
    {
        stack<string> st;
        int i = pre_exp.length() - 1;
        while (i >= 0)
        {
            char ch = pre_exp[i];
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

                string temp = s1 + s2 + ch;
                st.push(temp);
            }
            i--;
        }

        return st.top();
    }
};

int main()
{

    return 0;
}