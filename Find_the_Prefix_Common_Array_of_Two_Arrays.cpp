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
    vector<int> brute(vector<int> &a, vector<int> &b)
    {
        int n = a.size();
        vector<int> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> freq;
            for (int j = 0; j <= i; j++)
            {
                freq[a[j]]++;
                freq[b[j]]++;
            }
            int count = 0;
            for (auto it : freq)
                if (it.second == 2)
                    count++;

            ans[i] = count;
        }

        return ans;
    }

public:
    vector<int> findThePrefixCommonArray(vector<int> &a, vector<int> &b)
    {
        return brute(a, b);
    }
};

int main()
{

    return 0;
}