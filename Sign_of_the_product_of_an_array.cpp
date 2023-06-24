#include <bits/stdc++.h>
using namespace std;

int arraySign(vector<int> &nums)
{
    int sum = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < 0)
        {
            nums[i] = -1;
        }
        else if (nums[i] > 0)
        {
            nums[i] = 1;
        }
        else if (nums[i] == 0)
        {
            return 0;
        }
        sum *= nums[i];
    }
    if (sum > 0)
    {
        return 1;
    }
    return -1;
}
int main()
{
    vector<int> arr = {9, 72, 34, 29, -49, -22, -77, -17, -66, -75, -44, -30, -24};
    cout << arr.;
    return 0;
}