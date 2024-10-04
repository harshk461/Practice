#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    bool canArrange(vector<int> &arr, int k)
    {
        unordered_map<int, int> remainder;
        for (auto it : arr)
            remainder[(it % k + k) % k]++;

        for (auto it : arr)
        {
            int rem = (it % k + k) % k;

            if (rem == 0)
            {
                if (remainder[rem] % 2 == 1)
                    return false;
            }

            else if (remainder[rem] != remainder[k - rem])
                return false;
        }
        return true;
    }
};

int main()
{

    return 0;
}