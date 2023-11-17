#include <bits/stdc++.h>
using namespace std;

class SeatManager
{
private:
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    SeatManager(int n)
    {
        for (int i = 1; i <= n; i++)
            pq.push(i);
    }

    int reserve()
    {
        int s = pq.top();
        pq.pop();
        return s;
    }

    void unreserve(int seatNumber)
    {
        pq.push(seatNumber);
    }
};

int main()
{

    return 0;
}