#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
            q.push(i);

        while (q.size() != 1)
        {
            int K = 1;
            while (K <= k)
            {
                int top = q.front();
                q.push(top);
                q.pop();
            }
            cout << q.top() << " ";
        }

        return 0;
    }
};

int main()
{

    return 0;
}