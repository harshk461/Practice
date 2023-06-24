#include <bits/stdc++.h>
using namespace std;

int maximumCount(vector<int> &nums)
{
    int post = 0, neg = 0;
    for (auto i : nums)
    {
        if (i > 0)
            post++;
        else if (i < 0)
            neg++;
    }
    return max(post, neg);
}

int main()
{

    return 0;
}
