class Solution
{
public:
    int MOD = 1e9 + 7;
    int valueAfterKSeconds(int n, int k)
    {
        vector<int> arr(n, 1);
        long long sum = 0;
        while (k--)
        {
            for (int i = 0; i < n; i++)
            {
                sum += arr[i] % MOD;
                arr[i] = sum % MOD;
            }
            sum = 0;
        }

        return (arr[n - 1]) % MOD;
    }
};