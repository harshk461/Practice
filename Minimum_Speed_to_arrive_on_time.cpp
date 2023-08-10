#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    double time(vector<int> &dist, double hour, int speed)
    {
        double sum = 0;
        for (int i = 0; i < dist.size() - 1; i++)
            sum += ceil((double)dist[i] / speed);
        return sum + (double)dist.back() / speed;
    }

public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int ans = -1;
        int l = 1;
        int r = 1e7;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (time(dist, hour, m) > hour)
                l = m + 1;
            else
            {
                ans = m;
                r = m - 1;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}