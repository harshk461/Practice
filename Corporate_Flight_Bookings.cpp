#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> rangeAddition(vector<vector<int>> &bookings, int n)
    {
        vector<int> prefix(n + 1, 0);
        vector<int> ans(n);
        for (auto it : bookings)
        {
            int start = it[0] - 1;
            int end = it[1];
            int seats = it[2];

            prefix[start] += seats;
            prefix[end] -= seats;
        }

        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += prefix[i];
            ans[i] = sum;
        }

        return ans;
    }

public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n)
    {
        vector<int> ans(n, 0);
        for (auto it : bookings)
        {
            int start = it[0] - 1;
            int end = it[1] - 1;
            int seats = it[2];
            for (int i = start; i <= end; i++)
                ans[i] += seats;
        }

        return rangeAddition(bookings, n);
    }
};

int main()
{

    return 0;
}