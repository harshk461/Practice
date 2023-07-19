#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        vector<int> bucket(n + 1);
        for (int i = 0; i < n; i++)
        {
            int x = citations[i];
            if (x >= n)
                bucket[n]++;
            else
                bucket[x]++;
        }

        int h = 0;
        for (int i = n; i >= 0; i--)
        {
            h += bucket[i];
            if (h >= i)
                return i;
        }
        return -1;
    }
};

int main()
{

    return 0;
}