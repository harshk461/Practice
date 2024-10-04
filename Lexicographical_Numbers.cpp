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
    vector<int> lexicalOrder(int n)
    {
        vector<string> arr;
        for (int i = 1; i <= n; i++)
            arr.push_back(to_string(i));

        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (auto it : arr)
            ans.push_back(stoi(it));

        return ans;
    }
};

int main()
{

    return 0;
}