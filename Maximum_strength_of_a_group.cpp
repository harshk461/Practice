#include <bits/stdc++.h>
using namespace std;

long long maxStrength(vector<int> &nums)
{
    long long posProd = 1;
    long long negProd = 1;
    int maxNeg = INT_MIN;
    int negCount = 0;
    bool hasPos = false;
    bool hasZero = false;

    for (auto i : nums)
    {
        if (i > 0)
        {
            posProd *= i;
            hasPos = true;
        }
        else if (i < 0)
        {
            negProd *= i;
            maxNeg = max(maxNeg, i);
            ++negCount;
        }
        else
        {
            hasZero = true;
        }
    }

    if (negCount == 0 && !hasPos)
        return 0;
    if (negCount % 2 == 0)
        return posProd * negProd;
    if (negCount >= 3)
        return negProd / maxNeg * posProd; // follows bodmas
    if (hasPos)
        return posProd;
    if (hasZero)
        return 0;
    return maxNeg;
}

int main()
{
    vector<int> arr = {3, -1, -5, 2, 5, -9};
    cout << maxStrength(arr);
    return 0;
}