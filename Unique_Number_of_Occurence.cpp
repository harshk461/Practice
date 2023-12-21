#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_set<int> st;
        for (auto it : arr)
            st.insert(count(arr.begin(), arr.end(), it));

        set<int> s(arr.begin(), arr.end());

        return s.size() == st.size();
    }
};

int main()
{

    return 0;
}