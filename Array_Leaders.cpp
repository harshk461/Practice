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
    // Function to find the leaders in the array.
public:
    vector<int> leaders(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> suffix(n, 0);
        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
            suffix[i] = max(suffix[i + 1], arr[i]);
        // for(auto it:suffix)cout<<it<<" ";
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == suffix[i])
                ans.push_back(arr[i]);
        }

        return ans;
    }
};

int main()
{

    return 0;
}