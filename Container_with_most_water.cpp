#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int maxA = INT_MIN;
    int i = 0, j = height.size() - 1;
    while (i < height.size() && j > 0)
    {
        maxA = max((j - i) * min(height[i], height[j]), maxA);
        if (height[i] < height[j])
        {
            i++;
        }
        else
        {
            j--;
        }
        cout << maxA << " ";
    }
    return maxA;
}

int main()
{
    vector<int> arr = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    maxArea(arr);
    return 0;
}