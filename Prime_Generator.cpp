#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int s, e;
        cin >> s >> e;
        vector<bool> prime(e + 1, true);
        prime[0] = false, prime[1] = false;
        for (int i = 2; i * i <= e; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= e; j += i)
                {
                    prime[j] = false;
                }
            }
        }
        for (int i = 2; i <= e; i++)
        {
            if (i >= s && prime[i])
            {
                cout << i << " ";
            }
        }
    }
    return 0;
}