#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int brute(vector<int> &time)
    {
        int ans = 0;
        int n = time.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
                if ((time[i] + time[j]) % 60 == 0)
                    ans++;
        }

        return ans;
    }

public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        vector<int> arr(60, 0);
        int ans = 0;
        for (auto it : time)
        {
            int t = it % 60;
            if (t == 0)
                ans += arr[0];
            else
                ans += arr[60 - t];
            arr[t]++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}