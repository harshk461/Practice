#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int start = 0;
        int remaining = 0;
        int balance = 0;

        for (int i = 0; i < gas.size(); i++)
        {
            balance += gas[i] - cost[i];
            if (balance < 0)
            {
                start = 0;
                remaining += balance;
                balance = 0;
            }
        }

        if (remaining + balance >= 0)
            return start;
        return -1;
    }
};

int main()
{

    return 0;
}