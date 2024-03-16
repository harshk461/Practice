#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int averageValue(vector<int> &nums)
    {
        int sum = 0;
        int n = 0;
        for (auto it : nums)
            if (it % 3 == 0 && it % 2 == 0)
                sum += it, n++;

        return sum != 0 ? sum / n : 0;
    }
};

int main()
{

    return 0;
}