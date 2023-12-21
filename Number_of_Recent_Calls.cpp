#include <bits/stdc++.h>
using namespace std;

class RecentCounter
{
public:
    // vector<int> arr;
    queue<int> q;
    RecentCounter()
    {
    }

    int ping(int t)
    {
        // arr.push_back(t);
        // vector<int> ranges = {t - 3000, t};
        // int count = 0;
        // for (auto it : arr)
        // {
        //     if (it >= ranges[0] && it <= ranges[1])
        //         count++;
        // }
        // return count;
        int limit = t - 3000;
        q.push(t);
        while (q.front() < limit)
            q.pop();
        return q.size();
    }
};

int main()
{

    return 0;
}