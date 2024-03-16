#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mostBooked(int n, vector<vector<int>> &meetings)
    {
        sort(meetings.begin(), meetings.end(), [&](const vector<int> &a, const vector<int> &b)
             { return a[0] < b[0]; });

        vector<int> ans(n, 0);
        vector<long long> count(n, 0);

        for (int i = 0; i < meetings.size(); i++)
        {
            int start = meetings[i][0];
            int end = meetings[i][1];

            bool flag = true;
            int min_index = -1;

            long long val = 1e10;

            for (int j = 0; j < n; j++)
            {
                if (count[j] < val)
                {
                    val = count[j];
                    min_index = j;
                }

                if (count[j] <= start)
                {
                    flag = false;
                    ans[j]++;
                    count[j] = end;
                    break;
                }
            }

            if (!flag)
            {
                ans[min_index]++;
                count[min_index] += (1ll * (end - start));
            }
        }

        int maxi = -1, id = -1;
        for (int i = 0; i < n; i++)
            if (ans[i] > maxi)
                maxi = ans[i], id = i;

        return id;
    }
};

int main()
{

    return 0;
}