#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        vector<int> arr(n, 1);
        for (int i = 0; i < n - 1; i++)
        {
            if (ratings[i] < ratings[i + 1])
                arr[i + 1] = max(arr[i + 1], arr[i] + 1);
            if (ratings[n - 1 - i] < ratings[n - i - 2])
                arr[n - 2 - i] = max(arr[n - i - 2], arr[n - i - 1] + 1);
        }
        int ans = accumulate(arr.begin(), arr.end(), 0);
        return ans;
    }
};

int main()
{

    return 0;
}