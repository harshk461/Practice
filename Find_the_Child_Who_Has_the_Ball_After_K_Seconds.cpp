class Solution
{
public:
    int numberOfChild(int n, int k)
    {
        int c = 0;
        int count = 1;
        for (int i = 0; i < k; i++)
        {
            c += count;
            if (c == 0 || c == n - 1)
            {
                count *= -1;
            }
        }
        return c;
    }
};