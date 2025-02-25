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
    int numOfSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prefix(n, 0);
        prefix[0] = arr[0];

        int ans = arr[0] % 2 != 0 ? 1 : 0;

        for (int i = 1; i < n; i++)
        {
        }
    }
};

int main()
{

    return 0;
}