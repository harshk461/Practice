#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = 0.05 * arr.size();
        int ans = accumulate(arr.begin() + n, arr.begin() + arr.size() - n);

        return ans / (arr.size() - 2 * n);
    }
};

int main()
{

    return 0;
}