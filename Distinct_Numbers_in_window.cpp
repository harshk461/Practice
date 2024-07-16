#include <bits/stdc++.h>
using namespace std;

vector<int> dNums(vector<int> &arr, int b)
{
    int n = arr.size();
    if (b > n)
        return {};
    vector<int> ans(n - b + 1, 0);
    for (int i = 0; i <= n - b; i++)
    {
        set<int> s(arr.begin() + i, arr.begin() + i + b);
        ans[i] = s.size();
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2};

    vector<int> ans = dNums(arr, 1);
    for (auto it : ans)
        cout << it << " ";

    return 0;
}