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
    int brute(int n, int k)
    {
        vector<string> arr;
        for (int i = 1; i <= n; i++)
            arr.push_back(to_string(i));

        sort(arr.begin(), arr.end());
        vector<int> ans;
        for (auto it : arr)
            ans.push_back(stoi(it));

        return ans[k - 1];
    }

    void generate(int base, int n, int &k, int &ans)
    {
        if (base > n)
            return;

        if (k == 0)
        {
            ans = base;
            return;
        }
        for (int i = 0; i < 10; i++)
            generate(base * 10 + i, n, k--, ans);
    }

public:
    int findKthNumber(int n, int k)
    {
        int ans = 0;
        for (int i = 1; i < 10; i++)
            generate(i, n, k, res, ans);

        return ans;
    }
};

int main()
{

    return 0;
}