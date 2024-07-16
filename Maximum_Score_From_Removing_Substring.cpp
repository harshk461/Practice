#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    pair<int, string> solve(string s, string ptr, int cost)
    {
        stack<char> st;
        int ans = 0;

        for (auto it : s)
        {
            if (!st.empty() && st.top() == ptr[0] && it == pt[1])
            {
                ans += cost;
                st.pop();
            }
            else
                st.push(it);
        }

        string temp = "";
        // creating string after removing all the ptr substring
        while (!st.empty())
        {
            temp += st.top();
            st.pop();
        }

        reverse(temp.begin(), temp.end());

        return {ans, temp};
    }

public:
    int maximumGain(string s, int x, int y)
    {
        string s1 = "ab";
        string s2 = "ba";

        if (x < y)
        {
            // means cost of ba is greater than ab
            swap(x, y);
            swap(s1, s2);
        }

        // first we add the string with higher cost and in the remaining string we find the other substring

        auto s_after_high_cost = solve(s, s1, x);
        auto other_substring = solve(s_after_high_cost.second, s2, y);

        return s_after_high_cost.first + other_substring.first;
    }
};

int main()
{

    return 0;
}