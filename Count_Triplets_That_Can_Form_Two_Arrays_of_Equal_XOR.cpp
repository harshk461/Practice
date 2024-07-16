#include <iostream>
using namespace std;

class Solution
{
private:
    int brute(vector<int> &arr)
    {
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            int a = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                int b = 0;
                for (int k = j; k < n; k++)
                {
                    b = b ^ arr[k];
                    if (a == b)
                        ans++;
                }
                a = a ^ arr[j];
            }
        }
        return ans;
    }

    int solve(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);

        // maintaining prefix values for precomputation
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] ^ arr[i];

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int k = i + 1; k < n; k++)
                if (prefix[i] == prefix[k + 1])
                    ans += (k - i);

        return ans;
    }

public:
    int countTriplets(vector<int> &arr)
    {
        return solve(arr);
    }
};

int main()
{

    return 0;
}