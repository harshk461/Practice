#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<bool> SieveOfEratosthenes(int n)
    {
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 2; i * i < n; i++)
        {
            if (prime[i])
                for (int j = i * i; j < n; j+=i)
                    prime[j] = false;
        }
        return prime;
    }

public:
    vector<vector<int>> findPrimePairs(int n)
    {
        vector<int> arr;
        vector<vector<int>> ans;
        vector<bool> prime = SieveOfEratosthenes(n + 1);
        for (int i = 2; i <= n / 2; i++)
        {
            if (prime[i] && prime[n - i])
                ans.push_back({i, n - i});
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> arr = s.findPrimePairs(10);
    for (auto i : arr)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}