#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        set<int> st;
        st.insert(s[0]);
        for (int i = 1; i < s.length(); i++)
        {
            if (st.find(s[i]) != st.end())
                return s[i];
            st.insert(s[i]);
        }
        return 'a';
    }
};

int main()
{

    return 0;
}