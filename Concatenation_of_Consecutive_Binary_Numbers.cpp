class Solution
{
public:
    int MOD = 1e9 + 7;
    int concatenatedBinary(int n)
    {
        long ans = 0;
        int len = 0;

        for (int i = 1; i <= n; i++)
        {
            if ((i & (i - 1)) == 0)
                len++;

            ans = ((ans << len) % MOD + i) % MOD;
        }

        return ans;
    }
};
