#include <bits/stdc++.h>
using namespace std;

int differenceOfSum(vector<int> &nums)
{
    int ele_sum = accumulate(nums.begin(), nums.end(), 0);
    int digit_sum = 0;

    for (auto i : nums)
    {
        int temp = 0;
        while (i > 0)
        {
            temp += i % 10;
            i /= 10;
        }
        digit_sum += temp;
    }
    return abs(ele_sum - digit_sum);
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    cout << differenceOfSum(arr);
    return 0;
}