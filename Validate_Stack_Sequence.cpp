#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        unordered_map<int, int> mp;
        stack<int> st;
        int i = 0;

        for (int j = 0; j < popped.size(); j++)
        {
            int ele = popped[j];

            while (mp.find(ele) == mp.end())
            {
                st.push(pushed[i]);
                mp[pushed[i]]++;
                i++;
            }

            if (st.top() == ele)
            {
                st.pop();
                mp.erase(ele);
                continue;
            }
            else
            {
                return false;
            }
        }

        if (st.empty())
        {
            return true;
        }

        return false;
    }
};


int main()
{

    return 0;
}