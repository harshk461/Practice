#include <bits/stdc++.h>
using namespace std;

int superUgly(int n, vector<int> prime, int k)
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return 1;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
        pq.push(prime[i]);

    int count = 1, no;
    while (count < n)
    {
        no = pq.top();
        pq.pop();

        if (no != pq.top())
        {
            count++;
            for (int i = 0; i < k; i++)
                pq.push(no * prime[i]);
        }
    }
    return no;
}

int main()
{

    return 0;
}