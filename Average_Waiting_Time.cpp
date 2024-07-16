#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double sum = 0;
        int start = 0;
        int end = 0;

        for (auto it : customers)
        {
            int at = it[0];
            int t = it[1];
            start = start + at;
            end = start + t;

            sum += (end - start);
            start = end;
        }

        return sum / (double)customers.size();
    }
};

int main()
{

    return 0;
}