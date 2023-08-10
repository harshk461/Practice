#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isUgly(int n)
    {
        if (n <= 0)
            return false;
        if (n == 1)
            return true;

        vector<int> prime = {2, 3, 5};
        for (auto i : prime)
            while (n % i == 0)
                n /= i;
        return n == 1;
    }
};

int main()
{

    return 0;
}