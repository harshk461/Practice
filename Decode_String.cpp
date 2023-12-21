#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// private:
//     string solve(int i, string s)
//     {
//         string ans;
//         while (i < s.length() && s[i] != ']')
//         {
//             if (!isdigit(s[i]))
//                 ans += s[i++];
//             else
//             {
//                 int n = 0;
//                 while (i < s.size() && isdigit(s[i]))
//                     n = n * 10 + s[i] - '0';

//                 i++;
//                 string temp = solve(i, s);
//                 i++;
//                 while (n--)
//                     ans += temp;
//             }
//         }
//         return ans;
//     }

// public:
//     string decodeString(string s)
//     {
//         return solve(0, s);
//     }
// };

class Solution
{
public:
    string decodeString(string s)
    {
        string ans = "";
        // store numbers
        stack<int> m;

        // store letters
        stack<char> st;

        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                string temp;
                temp.push_back(s[i]);
                int j = i + 1;
                while (j < s.length())
                {
                    if (isdigit(s[j]))
                        temp.push_back(s[j++]);
                    else
                    {
                        i = j - 1;
                        break;
                    }
                }
                // stores the number of time we have to repeat the string
                m.push(stoi(temp));
            }
            // when we got a ending bracket
            else if (s[i] == ']')
            {
                int times = m.top();
                m.pop();
                string temp_string = "";
                while (!st.empty() && st.top() != '[')
                {
                    temp_string += st.top();
                    st.pop();
                }
                st.pop(); // pop the starting bracket
                reverse(temp_string.begin(), temp_string.end());
                string str = temp_string;
                for (int k = 1; k < times; k++)
                    str += temp_string;

                // we have other brackets also
                if (!st.empty())
                    for (int k = 0; k < str.size(); k++)
                        st.push(str[k]);
                else
                    ans += str;
            }
            // we have starting bracket or a letter which we have to push in the letter stack
            else
                st.push(s[i]);
        }
        // if we some elements which are not in brackets but are present in the string
        string temp = "";
        while (!st.empty())
        {
            temp += st.top();
            st.pop();
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.decodeString("3[a]2[bc]");
    return 0;
}