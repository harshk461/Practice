#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &dist, vector<int> &speed)
    {
        priority_queue<float, vector<float>, greater<float>> hp;

        for (int i = 0; i < dist.size(); i++)
            hp.push((float)dist[i] / speed[i]);

        int ans = 0;
        while (!hp.empty())
        {
            if (hp.top() <= ans)
                break;
            ans++;
            hp.pop();
        }

        return ans;
    }

public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        vector<float> arrival;
        for (int i = 0; i < dist.size(); i++)
            arrival.push_back((float)dist[i] / speed[i]);

        sort(arrival.begin(), arrival.end());
        int ans = 0;

        for (int i = 0; i < arrival.size(); i++)
        {
            if (arrival[i] <= i)
                break;
            ans++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}