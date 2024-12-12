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
private:
    bool brute(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == 2 * arr[j] && i != j)
                    return true;
            }
        }

        return false;
    }

    bool solve(vector<int> &arr)
    {
        multiset<int> st(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++)
        {
            auto it = st.find(arr[i]);
            if (it != st.end())
                st.erase(it);

            if (st.find(2 * arr[i]) != st.end())
                return true;
            st.insert(arr[i]);
        }

        return false;
    }

public:
    bool checkIfExist(vector<int> &arr)
    {
        return solve(arr);
    }
};

int main()
{

    return 0;
}